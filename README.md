# ROS2 Priority task scheduling Assignment:
This assignment is performed in ROS2 Humble for priority scheduling of T1, T2 and T3 with the help of Semaphore for the controlled execution.

## **Project Overview**
- **Framework**: ROS2 Humble
- **Package Name**: priority_tasks
- **Workspace Name**: tal
- **Concepts Used**:
  - Task prioritization
  - Semaphores for synchronization
- **Execution Order**:
  - T2 (Medium priority) runs first.
  - T1 (Low priority) runs second.
  - T3 (High priority) runs last.


### **Installation and Usage**

#### **Step 1: Clone the Repository**

git clone https://github.com/<your-username>/ROS2-Priority-Tasks.git
cd ROS2-Priority-Tasks

Step 2: Build the Workspace

colcon build

Step 3: Source the Workspace

source install/setup.bash

Step 4: Run the Task Priority Example

ros2 run priority_tasks priority_tasks

You should see the following output:

T2 which is of Medium Priority is running
T1 which is of Low Priority is running
T3 which is of High Priority is running

Code Explanation

    Tasks: To control the execution of each tasks(T1, T2, T3) where each task is a function which uses a semaphore.
    Semaphores:
        sem_t2 starts with an initial value of 1, allowing T2 to run first.
        sem_t1 and sem_t3 start with 0, blocking T1 and T3 until they are signaled.
    Execution Order:
        T2 signals to T1 upon completion.
        T1 signals to T3 upon completion.
        T3 completes last.
