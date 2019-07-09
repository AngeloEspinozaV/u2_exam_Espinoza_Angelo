				*****************************
				** Description of the exam **
				*****************************

MOTOR (34:1 Metal Gearmotor 25Dx67L mm HP 12V with 48 CPR Encoder): 

Since the in the datasheet the specified Stall Torque varied for two differet voltages(12V and 6V), the considered for this practice was 12V, thus the Stall Torque chose was 120 oz·in which convert to N·m is 0.847 N·m and this is the maxTorque put in each RotationalMotor.
The next attribute to modify was the maxVelocity, in this the formula proportionated was useful:

			      MaxVel = (RPM·2·PI)/(60)

which in this case the datasheet indicates that the RPM is equal to 290, therefore the MaxVel = 30.36.

POSITION SENSOR: 

For the position sensor I based on the formula provided:

			   resolution = 2·PI/(countersPerRevolution)

Therefore, the resolution put in PositionSensor attribute was 0.003848, the noise part was left in 0.

DISTANCE SENSOR (VCNL4040):

The distance sensors contain a shape of a cube of dimension 0.01 x 0.01 x 0.01. In the lookupTable attribute basing on the datasheet, the sensor to reproduce is a proximity sensor that operates with a range from 0mm to 200mm, therefore in the lookupTable the the values put were: x = 0, y = 0, z = 0. The datasheet also states that the resolution of the sensor is of 16-bit, for instance using the formula given in class:

				resolution = 2^(bit) - 1
Giving as result resolution = 65535 which will be put together with the maximum distance that the sensor can read (0.2m). 
				x = 0    y = 0     z = 0
				x = 0.2  y = 65535 z = 0
This lookupTable for both distace sensor.In this way sensing from 0 (the start of the sensor) to the end of it.


