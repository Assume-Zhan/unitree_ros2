cmake_minimum_required(VERSION 3.8)
project(go2_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(unitree_go REQUIRED)
find_package(unitree_api REQUIRED)

# Add node - Go2_Controller
add_library(go2_controller SHARED src/go2_controller.cpp)

target_include_directories(go2_controller PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/go2_controller>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/go2_controller/nlohmann>
  $<INSTALL_INTERFACE:include>
  $<INSTALL_INTERFACE:include/go2_controller>
)

ament_target_dependencies(go2_controller
  "rclcpp"
  "rclcpp_action"
  "rclcpp_components"
  "std_msgs"
  "geometry_msgs"
  "sensor_msgs"
  "unitree_go"
  "unitree_api"
)
rclcpp_components_register_node(go2_controller 
  PLUGIN "Go2_Controller" 
  EXECUTABLE go2_controller_node
)
install(TARGETS
  go2_controller
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
