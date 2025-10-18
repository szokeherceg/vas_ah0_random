#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <cstdlib>
#include <ctime>

class RandomPublisher : public rclcpp::Node
{
public:
  RandomPublisher() : Node("random_publisher")
  {
    pub_ = this->create_publisher<std_msgs::msg::Int32>("random_number", 10);

    timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                     std::bind(&RandomPublisher::publish_random, this));

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    RCLCPP_INFO(this->get_logger(), "Elindult a random számok generálása");
  }

private:
  void publish_random()
  {
    std_msgs::msg::Int32 msg;
    msg.data = std::rand() % 100;

    pub_->publish(msg);

    RCLCPP_INFO(this->get_logger(),
                "[INFO] A generált szám: %d", msg.data);
  }

  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<RandomPublisher>();

  rclcpp::spin(node);

  RCLCPP_INFO(node->get_logger(), "Leállítás...");
  rclcpp::shutdown();
}
