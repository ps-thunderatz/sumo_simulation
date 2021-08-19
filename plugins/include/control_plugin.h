/**
 * @file start_button_plugin.h
 *
 * @brief Gazebo plugin of a start button.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 08/2021
 *
 * @copyright MIT License - Copyright (c) 2021 ThundeRatz
 */

#ifndef _CONTROL_PLUGIN_H_
#define _CONTROL_PLUGIN_H_

#include <gazebo/common/Plugin.hh>
#include <gazebo/gui/GuiPlugin.hh>

#include <ros/ros.h>

/*****************************************
 * Class Definition
 *****************************************/

namespace gazebo {
class GAZEBO_VISIBLE ControlPlugin :
    public GUIPlugin {
    Q_OBJECT

    public:
        /**
         * @brief Construct a new Start Control object
         *
         */
        ControlPlugin();

        /**
         * @brief Load function
         *        Called when a plugin is first created.
         *        This function should not be blocking. This function will be
         *        called with an empty sdf element when a GUI plugin is loaded
         *        via a gui.ini file or via a command line argument.
         *
         * @param _sdf Pointer the the SDF element of the plugin. This is
         *             the plugin SDF, <plugin ...>, and its children. It
         *             will be an empty element when loaded from INI file
         *             or command line argument.
         *
         * @note Documentation inherited
         */
        void Load(sdf::ElementPtr _sdf);

    protected slots:
        /**
         * @brief Callback trigged when the start button is pressed.
         *
         */
        void OnStart();

    protected slots:
        /**
         * @brief Callback trigged when the stop button is pressed.
         *
         */
        void OnStop();

    private:
        ros::NodeHandle _nh;
        ros::Publisher control_pub;
};
}

#endif // _CONTROL_PLUGIN_H_
