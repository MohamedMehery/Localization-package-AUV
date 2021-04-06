import os
import sys

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return  LaunchDescription([
        Node(
            package='robot_localization',
            node_executable='ekf_localization_node',
            node_name='ekf_se',
            parameters=[
                get_package_share_directory(
                    'robot_localization') + '/params/dvl_ekf_template.yaml'
            ]
        )
    ])
