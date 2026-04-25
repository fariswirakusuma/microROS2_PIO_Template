# GANESIS ROS TAMPLATE

## Setup That I use initialy:
* ## Microcontroller :
  * ### STM 32 Bluepills (bluepill_f103c8)
*  ## ROS2 Package :
   *  ### ngetestyahbot

## Requirements :
* ## Libraries and tools:
  * ### MicroROS
  * ### Platform IO
  * ### CMAKE

## Run And Setup
### ROS2 SETUP:
```bash

# >> Build Workspace
colcon build
# or
colcon build --packages-select ngetestyahbot

# >> Source the Environment:
source install/setup.bash

# >> Run the Listener Node:
ros2 run ngetestyahbot stm_counter

# Debugging
ros2 topic list
ros2 topic echo /stm_counter
```
### PIO SETUP:
* #### if u are using non CLI:
  * select environment
  * upload the code (->) arrow
* #### if u are using CLI:
     ```bash
     pio run --target upload
     pio device monitor
     ```

## Modify

### dependencies & lib
CMakeLists.txt:
```cmake
ament_target_dependencies(
  stm_counter
  rclcpp
  std_msgs
)
```

### add new or modify board:
```pio
[env:<board_env_name>]
platform = <board_platform>
board = <board_name>
framework = arduino
```
