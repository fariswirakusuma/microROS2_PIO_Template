#include <Arduino.h>
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <std_msgs/msg/int32.h>


rcl_publisher_t publisher;
std_msgs__msg__Int32 msg;
rcl_node_t node;
rcl_allocator_t allocator;
rclc_support_t support;

#define LED_PIN PC13
#define RCCHECK(fn) { rcl_ret_t rc = fn; if (rc != RCL_RET_OK) error_loop(); }
void error_loop() {
  while (1) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
}


void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); 

  Serial1.begin(115200);
  set_microros_transports();

  allocator = rcl_get_default_allocator();
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  RCCHECK(rclc_node_init_default(&node, "stm_node", "", &support));
  RCCHECK(rclc_publisher_init_default(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "stm_counter"
  ));

  msg.data = 0;
}

void loop() {
  static unsigned long last_time = 0;
  
  if (millis() - last_time > 1000) {
    rcl_ret_t rc = rcl_publish(&publisher, &msg, NULL);
    
    if (rc == RCL_RET_OK) {
        msg.data++;
        digitalWrite(LED_PIN, LOW);
        delay(50);
        digitalWrite(LED_PIN, HIGH);
    }
    last_time = millis();
  }
}