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
#include "unitree_go/msg/sport_mode_state.hpp"
#include "unitree_api/msg/request.hpp"

using namespace std::chrono_literals;

class Go2_Controller : public rclcpp::Node {

public:

    explicit Go2_Controller(const rclcpp::NodeOptions & options);
    virtual ~Go2_Controller();

private:

    // ROS2 - Objects
    rclcpp::TimerBase::SharedPtr timer_;
};

RCLCPP_COMPONENTS_REGISTER_NODE(Go2_Controller)