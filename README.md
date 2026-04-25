# ROS TAMPLATE


# Spesifikasi Perangkat & Perangkat Lunak
### Perangkat Keras
- Microcontroller: STM32 Bluepill (F103C8T6)
- Interface: USB-to-TTL (untuk flashing/serial) atau ST-Link.

### Dependensi Sistem
- ROS2 Distribution: (Contoh: Humble/Foxy)
- Build System: CMake, Colcon
- Embedded Toolchain: PlatformIO (PIO)
- Client Library: Micro-ROS

## Run And Setup
### ROS2 SETUP:
```bash

# >> Build Workspace
colcon build
# or
colcon build --packages-select <nama_package>


# >> Source the Environment:
source install/setup.bash

# >> Run the Listener Node:
ros2 run <nama_package> <nama_node>
# CONTOH:
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
Pembuatan Node dapat dilakukan di:
```cmake
add_executable(<nama_node> path_node)
ament_target_dependencies(
  nodw
  rclcpp
  <nama_node>
)

install(TARGETS
  <name_node>
  DESTINATION lib/${PROJECT_NAME}
)
```

### add new or modify board:
```pio
[env:<board_env_name>]
platform = <board_platform>
board = <board_name>
framework = arduino
```

