cmake_minimum_required(VERSION 3.5)
project(priority_tasks)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Build the executable
add_executable(priority_tasks src/priority_tasks.cpp)
ament_target_dependencies(priority_tasks rclcpp)

# Install the executable
install(TARGETS priority_tasks DESTINATION lib/${PROJECT_NAME})

ament_package()

