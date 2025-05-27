#include <unistd.h>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "unitree_go/msg/sport_mode_state.hpp"

#include "unitree_api/msg/request.hpp"
#include "common/ros2_sport_client.h"

#include "geometry_msgs/msg/twist.hpp"

using std::placeholders::_1;

class cmd_vel_converter : public rclcpp::Node {

public:
    cmd_vel_converter() : Node("cmd_vel_converter") {

        cmd_vel_suber = this->create_subscription<geometry_msgs::msg::Twist>(
            "cmd_vel", 10, std::bind(&cmd_vel_converter::cmd_vel_callback, this, _1));

        req_puber = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);
    };

private:

    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {

        float vx = msg->linear.x;
        float vy = msg->linear.y;
        float vyaw = msg->angular.z;

        // Set the request to move
        sport_req.Move(req, vx, vy, vyaw);

        // Publish the request
        req_puber->publish(req);
    }

    // ROS2 subscriber for cmd_vel topic
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_suber;

    rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr req_puber;

    // Unitree Go2 ROS2 request message
    unitree_api::msg::Request req;
    SportClient sport_req;
};

int main(int argc, char *argv[]) {

    // Initialize rclcpp
    rclcpp::init(argc, argv);

    // Create a timer callback object to send sport request in time intervals
    rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::spin(std::make_shared<cmd_vel_converter>());

    rclcpp::shutdown();

    return 0;
}