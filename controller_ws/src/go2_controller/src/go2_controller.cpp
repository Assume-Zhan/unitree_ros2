#include "go2_controller/go2_controller.h"

Go2_Controller::Go2_Controller(const rclcpp::NodeOptions & options) : Node("go2_controller", options) {

    using namespace std::placeholders;

    // Initialize the publisher and subscriber
    cmd_vel_sub = this->create_subscription<geometry_msgs::msg::Twist>(
        "cmd_vel", 10, std::bind(&Go2_Controller::cmd_vel_callback, this, _1));

    req_pub = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);
}

void Go2_Controller::cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {

    float vx = msg->linear.x;
    float vy = msg->linear.y;
    float vyaw = msg->angular.z;

    // Set the request to move
    sport_client.Move(req, vx, vy, vyaw);

    // Publish the request
    req_pub->publish(req);

    // Log the command
    RCLCPP_INFO(this->get_logger(), "Received cmd_vel: vx=%.2f, vy=%.2f, vyaw=%.2f", vx, vy, vyaw);
}

Go2_Controller::~Go2_Controller() {
    // Shutdown the node
    rclcpp::shutdown();
}