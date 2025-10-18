A projekt során 2 féle node-ot hoztam létre,az egyik a random_publisher és a másik pedig a random_subscriber.

A random_publisher random számokat generál 0 és 99 között másodpercenként,amiket utána ki is irat.
A random_subscriber,pedig a publisher adatait megkapva szintén kiirja a továbbított számokat,azzal a kiegészítéssel,hogy az a szám páros,vagy páratlan.

A projekt futtatásának lépései:

Feltételezzük,hogy az "~/ros2_ws/"-ben dolgozunk

1.Repository másolása

    cd ~/ros2_ws/src

    git clone https://github.com/szokeherceg/vas_ah0_random.git

2.ROS2 csomagok buildelése

    cd ~/ros2_ws

    colcon build --packages-select vas_ah0_random

3.Source futtatása,az ROS parancsok előtt

    source install/setup.bash

4.Publisher futtatása egyik terminálban

    ros2 run vas_ah0_random random_publisher

5.Subscriber futtatása egy második terminálban

    ros2 run vas_ah0_random random_subscriber

A node-ok kapcsolata Meramid diagrammal,a követkető:

```mermaid
graph LR
    RP[random_publisher] --> RN[random_number topic]
    RN --> RS[random_subscriber]

classDef red fill:#ef4638,stroke:#152742,stroke-width:2px,color:#fff;
classDef dark fill:#152742,stroke:#34aec5,stroke-width:2px,color:#34aec5;
classDef green fill:#28a745,stroke:#152742,stroke-width:2px,color:#fff;

class RP red
class RN dark
class RS green

```
