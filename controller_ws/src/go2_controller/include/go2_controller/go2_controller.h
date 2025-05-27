#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <mutex>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

// Basic Unitree Go2 libraries
#include "common/ros2_sport_client.h"

// Messages
#include "geometry_msgs/msg/twist.hpp"
#include "unitree_go/msg/sport_mode_state.hpp"
#include "unitree_api/msg/request.hpp"

using namespace std::chrono_literals;

class Go2_Controller : public rclcpp::Node {

public:

    explicit Go2_Controller(const rclcpp::NodeOptions & options);
    virtual ~Go2_Controller();

private:

    // ROS2 - Subscribers
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub;

    // ROS2 - Publishers
    rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr req_pub;

    // ROS2 - callbacks
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg);

    // Unitree Go2 - ROS2 request message
    unitree_api::msg::Request req;

    // Unitree Go2 - Sport Client
    SportClient sport_client;
};

RCLCPP_COMPONENTS_REGISTER_NODE(Go2_Controller)