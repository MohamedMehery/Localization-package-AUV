import os
import sys

import launch
import launch_ros.actions
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    ld = launch.LaunchDescription([
        launch_ros.actions.Node(
            package='robot_localization',
            executable='ekf_localization_node',
            name='ekf_se',
            parameters=[
                get_package_share_directory(
                    'robot_localization') + '/params/dvl_ekf_template.yaml'
            ]
        )
    ])
    return ld


if __name__ == '__main__':
    generate_launch_description()
