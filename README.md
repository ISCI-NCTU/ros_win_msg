sudo apt-get install ros-indigo-rosserial-windows
sudo apt-get install ros-indigo-rosserial-server

rosrun rosserial_windows make_libraries.py ~/code/my_library

<in Win:>
Create a new visual studio command line app project
Copy the ros_lib generated by rosserial_windows into your project
Copy the testdrive.cpp instead of your main cpp file
Add the .h and .cpp files from the top level of the ros_lib to your VS project (should only be WindowsSocket.h WindowsSocket.cpp duration.cpp time.cpp and ros.h)
Compile the project
Run the exe with the command line argument of the IP address of your robot
Watch your robot spin around!
Some tips:
Do not enable unicode support. If your command line arguments are not working correctly, try turning off unicode as the character set.
Turn off precompiled headers or WindowsSocket will not compile properly.

<in linux:>
======---win send msg-----------======
sudo ufw allow  in 11411 
export ROS_IP=192.168.1.50
roscore
rosrun rosserial_server socket_node
(rosrun rosserial_server socket_node cmd_vel:=/r1/cmd_vel)
rostopic echo /cmd_vel

======---win get msg-----------======
roslaunch motorGo keyboard.launch
roslaunch mrpt_tutorials r1_gazebo_gh25.launch
rosrun rosserial_server socket_node estimated_pose:=/r1/odom


<in VC2010>
http://blog.csdn.net/hua_007/article/details/10931035
	error C3861: 'round': identifier not found
 	There is no round function in <cmath> for windows. Instead, you have to implement it yourself. This is 		rather easy, however:

	inline double round( double d )
	{
    		return floor( d + 0.5 );
	}


ref:
https://github.com/ros-drivers/rosserial/tree/jade-devel/rosserial_windows/src/examples/TestDrive
http://wiki.ros.org/rosserial_windows
