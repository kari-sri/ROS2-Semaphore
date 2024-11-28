#include <rclcpp/rclcpp.hpp>
#include <semaphore.h>
#include <thread>
#include <chrono>

sem_t sem_t1, sem_t2, sem_t3;

void task1() {
    sem_wait(&sem_t1);
    RCLCPP_INFO(rclcpp::get_logger("Task1"), "T1 (Lowest Priority) is running...");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    sem_post(&sem_t3);  // Signal T3
}

void task2() {
    sem_wait(&sem_t2);
    RCLCPP_INFO(rclcpp::get_logger("Task2"), "T2 (Medium Priority) is running...");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    sem_post(&sem_t1);  // Signal T1
}

void task3() {
    sem_wait(&sem_t3);
    RCLCPP_INFO(rclcpp::get_logger("Task3"), "T3 (Highest Priority) is running...");
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    // Initialize semaphores
    sem_init(&sem_t1, 0, 0);
    sem_init(&sem_t2, 0, 1);  // Start T2 first
    sem_init(&sem_t3, 0, 0);

    // Create threads for each task
    std::thread t2(task2);
    std::thread t1(task1);
    std::thread t3(task3);

    // Wait for threads to finish
    t2.join();
    t1.join();
    t3.join();

    // Cleanup
    sem_destroy(&sem_t1);
    sem_destroy(&sem_t2);
    sem_destroy(&sem_t3);

    rclcpp::shutdown();
    return 0;
}
