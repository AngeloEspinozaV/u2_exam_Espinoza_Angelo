/*
 * File:          u3_exam_Espinoza_Angelo.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h> 
#include <webots/keyboard.h>

#include <stdio.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   /* IMPORTING MOTORS */
   WbDeviceTag motor_1 = wb_robot_get_device("motor1");
   WbDeviceTag motor_2 = wb_robot_get_device("motor2");
   WbDeviceTag motor_3 = wb_robot_get_device("motor3"); 
   
   /* SETTING POSITION OF THE MOTORS */
   wb_motor_set_position(motor_1, INFINITY);
   wb_motor_set_position(motor_2, INFINITY); 
   wb_motor_set_position(motor_3, INFINITY);
         
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
   
   /* ENABLING THE KEYBOARD */
   wb_keyboard_enable(TIME_STEP); 
   
   int key;
   
  while (wb_robot_step(TIME_STEP) != -1) {
      
      
      key = wb_keyboard_get_key();

      if (key == WB_KEYBOARD_UP) {
       wb_motor_set_velocity(motor_1, 5);
       wb_motor_set_velocity(motor_2, 5);
       wb_motor_set_velocity(motor_3, 0);
      }
            
      else if (key == WB_KEYBOARD_DOWN) {
       wb_motor_set_velocity(motor_1, -5);
       wb_motor_set_velocity(motor_2, -5);
       wb_motor_set_velocity(motor_3, 0);
      }

      else if (key == WB_KEYBOARD_LEFT) {
       wb_motor_set_velocity(motor_1, 5);
       wb_motor_set_velocity(motor_2, -5);
       wb_motor_set_velocity(motor_3, 8.66);
      }
      else if (key == WB_KEYBOARD_RIGHT) {
       wb_motor_set_velocity(motor_1, -5);
       wb_motor_set_velocity(motor_2, 5);
       wb_motor_set_velocity(motor_3, -8.66);
      }      
      else {
       wb_motor_set_velocity(motor_1, 0);
       wb_motor_set_velocity(motor_2, 0);
       wb_motor_set_velocity(motor_3, 0);
      }
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
