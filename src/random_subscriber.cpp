#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class RandomSubscriber : public rclcpp::Node
{
public:
  RandomSubscriber() : Node("random_subscriber")
  {
    sub_ = this->create_subscription<std_msgs::msg::Int32>(
      "random_number",
      10,
      std::bind(&RandomSubscriber::callback_random, this, std::placeholders::_1)
    );

    RCLCPP_INFO(this->get_logger(), "A program elindult és várja a számokat...");
  }

private:
  void callback_random(const std_msgs::msg::Int32::SharedPtr msg)
  {
    if (msg->data%2 == 0) {
      RCLCPP_INFO(this->get_logger(), "A kapott szám páros, és ennyi: %d", msg->data);
    } else {
      RCLCPP_INFO(this->get_logger(), "A kapott szám páratlan, és ennyi: %d", msg->data);
    }
  }

  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<RandomSubscriber>();
  rclcpp::spin(node);
  RCLCPP_INFO(node->get_logger(), "Leállítás...");
  rclcpp::shutdown();
}
