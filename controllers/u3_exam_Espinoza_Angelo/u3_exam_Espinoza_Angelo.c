/*
 * File:          u3_exam_Espinoza_Angelo.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/* WEBOTS LIBRARIES */
#include <webots/robot.h>
#include <webots/motor.h> 
#include <webots/keyboard.h>
#include <webots/distance_sensor.h>
#include <webots/position_sensor.h>

/* C LIBRARIES */
#include <stdio.h>

/* MACROS */
#define TIME_STEP 64
#define MAX_BITS 65535

/* PROTOFUNCTIONS */
float bitsToCentimeters(float centimeters);

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
   
   /* IMPORTING DISTANCE SENSORS */
    WbDeviceTag distance_sensor1 = wb_robot_get_device("distance_sensor1");         
    WbDeviceTag distance_sensor2 = wb_robot_get_device("distance_sensor2");         
     
   /* ENABLING ENCODERS */
    wb_distance_sensor_enable(distance_sensor1, TIME_STEP);
    wb_distance_sensor_enable(distance_sensor2, TIME_STEP);
    
   /* IMPORTING POSITION SENSOR */
    WbDeviceTag position_sensor1 = wb_robot_get_device("position_sensor1");
    WbDeviceTag position_sensor2 = wb_robot_get_device("position_sensor2");
    WbDeviceTag position_sensor3 = wb_robot_get_device("position_sensor3");
   
   /* ENABLING POSITION SENSORS */
    wb_position_sensor_enable(position_sensor1, TIME_STEP);
    wb_position_sensor_enable(position_sensor2, TIME_STEP); 
    wb_position_sensor_enable(position_sensor3, TIME_STEP); 
       
   /* ENABLING THE KEYBOARD */
    wb_keyboard_enable(TIME_STEP); 
       
   /* VARIABLES */
    int key;
    
    double distance_sensor_value1;
    double distance_sensor_value2;
    
    double position_sensor_value1;   
    double position_sensor_value2;
    double position_sensor_value3;    
    
    float desired_centimeters = bitsToCentimeters(17);
    
  while (wb_robot_step(TIME_STEP) != -1) {
      
      distance_sensor_value1 = wb_distance_sensor_get_value(distance_sensor1);
      distance_sensor_value2 = wb_distance_sensor_get_value(distance_sensor2);
      printf("Distance sensor right value is: %.4f\n", distance_sensor_value1);
      printf("Distance sensor left value is: %.4f\n", distance_sensor_value2);

      position_sensor_value1 = wb_position_sensor_get_value(position_sensor1);
      position_sensor_value2 = wb_position_sensor_get_value(position_sensor2);
      position_sensor_value3 = wb_position_sensor_get_value(position_sensor3);
      
      printf("Position sensor wheel 1 is: %.4f\n", position_sensor_value1);
      printf("Position sensor wheel 2 is: %.4f\n", position_sensor_value2);
      printf("Position sensor wheel 3 is: %.4f\n", position_sensor_value3);
      
      key = wb_keyboard_get_key();
      
      /* MOVE FORWARD */
      if ((distance_sensor_value1 > desired_centimeters) && (distance_sensor_value2 > desired_centimeters)) {

         wb_motor_set_velocity(motor_1, 1);
         wb_motor_set_velocity(motor_2, 1);
         wb_motor_set_velocity(motor_3, 0);
      }
      
      /* STOP */      
      else if ((distance_sensor_value1 == desired_centimeters) && (distance_sensor_value2 == desired_centimeters)) {
         wb_motor_set_velocity(motor_1, 0);
         wb_motor_set_velocity(motor_2, 0);
         wb_motor_set_velocity(motor_3, 0);
      }
      
      /* MOVE RIGHT AROUND A PIVOT */
      else if((distance_sensor_value1 < desired_centimeters) && (distance_sensor_value2 < desired_centimeters)) {
         wb_motor_set_velocity(motor_1, 0);
         wb_motor_set_velocity(motor_2, -2);
         wb_motor_set_velocity(motor_3, -2); 
      }
      
      /* AVOID OBSTACLES LEFT */
      else if(distance_sensor_value2 <= desired_centimeters) {
         wb_motor_set_velocity(motor_1, 0);
         wb_motor_set_velocity(motor_2, 3);
         wb_motor_set_velocity(motor_3, 3); 
      }
      /* AVOID OBSTACLES RIGHT */
      else if(distance_sensor_value1 <= desired_centimeters) {
         wb_motor_set_velocity(motor_1, 3);
         wb_motor_set_velocity(motor_2, 0);
         wb_motor_set_velocity(motor_3, -3); 
      }      // else {
       // wb_motor_set_velocity(motor_1, 0);
       // wb_motor_set_velocity(motor_2, 0);
       // wb_motor_set_velocity(motor_3, 0);
      // }      
      // else {
       // wb_motor_set_velocity(motor_1, 0);
       // wb_motor_set_velocity(motor_2, 0);
       // wb_motor_set_velocity(motor_3, 0);
      // }
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

float bitsToCentimeters(float centimeters) {
    
    return (MAX_BITS*centimeters)/(20);
    
    }

