#include "go2_controller/go2_controller.h"

Go2_Controller::Go2_Controller(const rclcpp::NodeOptions & options) :
    Node("go2_controller", options) {

    using namespace std::placeholders;

    // Create a timer
    // timer_ = this->create_wall_timer(1s, std::bind(&Go2_Controller::timer_callback, this));
}

Go2_Controller::~Go2_Controller() {
    // Shutdown the node
    rclcpp::shutdown();
}