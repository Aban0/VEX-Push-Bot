#pragma config(Sensor, dgtl1,  rightDrive,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftDrive,      sensorQuadEncoder)
#pragma config(Motor,  port1,           rightDrive1,   tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightDrive2,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightDrive3,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftDrive1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftDrive2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftDrive3,    tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................

	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// Declaring Varibles
	int KpR = 0;
	int errorR = 0;
	int targetSpeedR = 0;
	int drivePowerR = 0;
	int KpL = 0;
	int errorL = 0;
	int targetSpeedL = 0;
	int drivePowerL = 0;

	while (true)
	{
		// Drive controls
		motor[rightDrive1] = vexRT[Ch2];
		motor[rightDrive2] = vexRT[Ch2];
		motor[rightDrive3] = vexRT[Ch2];
		motor[leftDrive1] = vexRT[Ch3];
		motor[leftDrive2] = vexRT[Ch3];
		motor[leftDrive3] = vexRT[Ch3];

		// PID Parking Brake

		// Right side
		errorR = targetSpeedR - nMotorEncoder[rightDrive];  // Currently just P, we can add on in the future
		drivePowerR += (int)(KpR*errorR);
		//
		// Limit the drive power range to 0
		//
		if (drivePowerR > 0)
		{
			drivePowerR = 0;
		}
		else if (drivePowerR < 0)
		{
			drivePowerR = 0;
		}
		motor[rightDrive1] = drivePowerR;
		motor[rightDrive2] = drivePowerR;
		motor[rightDrive3] = drivePowerR;

		// Left side
		// PID Parking Brake right side
		errorL = targetSpeedL - nMotorEncoder[leftDrive];   // Currently just P, we can add on in the future
		drivePowerL += (int)(KpL*errorL);
		//
		// Limit the drive power range to 0
		//
		if (drivePowerL > 0)
		{
			drivePowerL = 0;
		}
		else if (drivePowerL < 0)
		{
			drivePowerL = 0;
		}
		motor[rightDrive1] = drivePowerL;
		motor[rightDrive2] = drivePowerL;
		motor[rightDrive3] = drivePowerL;
	}
}