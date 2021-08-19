cmake_minimum_required(VERSION 3.0.2)
project(sumo_simulation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(gazebo REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  gazebo_plugins
  gazebo_ros
  roscpp
)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(gazebo REQUIRED)

catkin_package(
  CATKIN_DEPENDS gazebo_plugins gazebo_ros roscpp
)

include_directories(${catkin_INCLUDE_DIRS}
                    ${Boost_INCLUDE_DIR}
                    ${GAZEBO_INCLUDE_DIRS}
                    ${Qt5Core_INCLUDE_DIRS}
)

include_directories(plugins/include)

link_directories(${GAZEBO_LIBRARY_DIRS})

add_library(control_plugin SHARED ${headers_MOC} plugins/src/control_plugin.cpp)

target_link_libraries(control_plugin
  ${GAZEBO_LIBRARIES}
  ${Qt5Core_LIBRARIES}
  ${Qt5Widgets_LIBRARIES}
  ${PROTOBUF_LIBRARIES}
)

find_package(roslaunch)

foreach(dir config launch urdf worlds)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
