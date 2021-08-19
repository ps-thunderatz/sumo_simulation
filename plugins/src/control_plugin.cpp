/**
 * @file control_plugin.h
 *
 * @brief Gazebo plugin of a start and stop buttons.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 08/2021
 *
 * @copyright MIT License - Copyright (c) 2021 ThundeRatz
 */

#include "control_plugin.h"

#include <std_msgs/Bool.h>

/*****************************************
 * Private Constants
 *****************************************/

constexpr uint32_t queue_size{1};

constexpr bool start{true};
constexpr bool stop{false};

/*****************************************
 * Class Definition
 *****************************************/

using namespace gazebo;

// Register this plugin with the simulator
GZ_REGISTER_GUI_PLUGIN(ControlPlugin)

ControlPlugin::ControlPlugin() : GUIPlugin() {
    // Set the frame background and foreground colors
    this->setStyleSheet(
        "QFrame { background-color : rgba(100, 100, 100, 255); color : white; }");

    // Create the main layout
    QHBoxLayout* main_layout = new QHBoxLayout;

    // Create the frame to hold all the widgets
    QFrame* main_frame = new QFrame();

    // Create the layout that sits inside the frame
    QVBoxLayout* frame_layout = new QVBoxLayout();

    // Create a push button, and connect it to the OnStart function
    QPushButton* start_button = new QPushButton(tr("Start"));
    connect(start_button, SIGNAL(clicked()), this, SLOT(OnStart()));

    QPushButton* stop_button = new QPushButton(tr("Stop"));
    connect(stop_button, SIGNAL(clicked()), this, SLOT(OnStop()));

    // Add the button to the frame's layout
    frame_layout->addWidget(start_button);
    frame_layout->addWidget(stop_button);

    // Add frame_layout to the frame
    main_frame->setLayout(frame_layout);

    // Add the frame to the main layout
    main_layout->addWidget(main_frame);

    // Remove margins to reduce space
    frame_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(main_layout);

    // Position and resize this widget
    this->move(10, 10);
    this->resize(120, 40);
}

void ControlPlugin::Load(sdf::ElementPtr _sdf) {
    if (!ros::isInitialized()) {
        ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin.");
        return;
    }

    if (_sdf->HasElement("controlTopic")) {
        this->control_pub = this->_nh.advertise<std_msgs::Bool>(_sdf->Get<std::string>("controlTopic"), queue_size);
    } else {
        ROS_FATAL_STREAM("Parameter <controlTopic> is missing.");
    }
}

void ControlPlugin::OnStart() {
    std_msgs::Bool msg;
    msg.data = start;
    this->control_pub.publish(msg);
}

void ControlPlugin::OnStop() {
    std_msgs::Bool msg;
    msg.data = stop;
    this->control_pub.publish(msg);
}
