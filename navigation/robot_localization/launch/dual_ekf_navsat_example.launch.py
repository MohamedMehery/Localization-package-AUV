import os
import sys

import launch
import launch_ros.actions


def generate_launch_description():
    ld = launch.LaunchDescription([
        launch_ros.actions.Node(
            package='robot_localization',
            executable='ekf_localization_node',
            name='ekf_se_odom'
        ),
        launch_ros.actions.Node(
            package='robot_localization',
            executable='ekf_localization_node',
            name='ekf_se_map'
        ),
        launch_ros.actions.Node(
            package='robot_localization',
            executable='navsat_transform_node',
            name='navsat_transform'
        )
    ])
    return ld


if __name__ == '__main__':
    generate_launch_description()
