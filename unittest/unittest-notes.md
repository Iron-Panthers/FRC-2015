# Notes
classes used in our code
	- Encoder
	- Gyro
	- Joystick
	- Talon

required
	- everything in hal
	- CounterBase
	- SensorBase
	- Counter
	- PIDSource
	- GenericHID
	- probably need to simulate I2C

RobotBase.cpp
	- where I should put everything to simulate the real world?
	- Have to create my own driverstation?
	- Or, this is only if I want to simulate the competition
	- My goal is to create a wpilib I can compile against and test without the real world boilerplate