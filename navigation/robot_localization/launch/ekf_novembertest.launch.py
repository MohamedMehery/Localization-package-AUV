import os
import sys

import launch
import launch_ros.actions
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    ld = launch.LaunchDescription([
        launch_ros.actions.Node(
            package='driver_stim300',
            executable='stim300_driver_node',
            name='driver_stim300'
        ),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_imu0'
        ),
        launch_ros.actions.Node(
            package='dvl1000_ros',
            executable='publisherDVL1000.py',
            name='publisherDVL1000'
        ),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_link_to_DVL'
        ),
        launch_ros.actions.Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='odom_to_Pressure'
        ),
        launch.actions.IncludeLaunchDescription(
            launch.launch_description_sources.PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory(
                    'robot_localization'), 'launch/ekf_IMU_DVL_PRESSURE.launch.py')
            )
        )
    ])
    return ld


if __name__ == '__main__':
    generate_launch_description()
