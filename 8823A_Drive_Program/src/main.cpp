/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Samuel Bosch-Bird                                         */
/*    Created:      Tue Sep 17 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;
vex::brain brain;
vex::motor frontRight (vex::PORT11, vex::gearSetting::ratio18_1,false);
vex::motor backRight (vex::PORT12, vex::gearSetting::ratio18_1,false);
vex::motor leftArm (vex::PORT14, vex::gearSetting::ratio18_1,true);
vex::motor rightArm (vex::PORT15, vex::gearSetting::ratio18_1,false);
vex::motor claw (vex::PORT16, vex::gearSetting::ratio18_1,false);
vex::motor backLeft (vex::PORT18, vex::gearSetting::ratio18_1,false);
vex::motor frontLeft (vex::PORT19, vex::gearSetting::ratio18_1,false);
vex::controller remote;

int fwdBack;
int leftRight;
int leftDrive;
int rightDrive;
const unsigned short driveSpeed [101] =
{0,0,0,0,0,0,0,0,0,0,1,						//0-10
1,1,2,2,2,3,3,3,4,4,					    //11-20
4,5,5,6,6,7,7,8,8,9,					    //21-30
10,10,11,12,12,13,14,14,15,16,		//31-40
17,18,18,19,20,21,22,23,24,25,		//41-50
26,27,28,29,30,31,32,34,35,36,		//51-60
37,38,40,41,42,44,45,46,48,49,		//61-70
50,52,53,55,56,58,59,61,62,64,		//71-80
66,67,69,71,72,74,76,77,79,81,		//81-90
83,85,86,88,90,92,94,96,98,100};  //91-100

int main() {

  while(true){
    if(true){ //Drive | if statement for collapsability   
      if (remote.Axis3.position(percentUnits::pct)>0){
			fwdBack = driveSpeed[abs(remote.Axis3.position(percentUnits::pct))];}
	    else{
			fwdBack = -(driveSpeed[abs(remote.Axis3.position(percentUnits::pct))]);}
	    if (remote.Axis1.position(percentUnits::pct)>0){
			leftRight = (0.7*driveSpeed[abs(remote.Axis1.position(percentUnits::pct))]);}
	    else{
			leftRight = -(0.7*driveSpeed[abs(remote.Axis1.position(percentUnits::pct))]);}

		  leftDrive = (fwdBack + leftRight);
		  rightDrive = (fwdBack - leftRight);
    
      frontLeft.spin(directionType::fwd,leftDrive,velocityUnits::pct);
      backLeft.spin(directionType::fwd,leftDrive,velocityUnits::pct);
      frontRight.spin(directionType::rev,rightDrive,velocityUnits::pct);
      backRight.spin(directionType::rev,rightDrive,velocityUnits::pct);
    }

    if(true){ //Lift | if statement for collapsability
      if(remote.ButtonL1.pressing()){leftArm.spin(directionType::fwd);rightArm.spin(directionType::fwd);}
      else if(remote.ButtonL2.pressing()){leftArm.spin(directionType::rev);rightArm.spin(directionType::rev);}
      else{leftArm.stop(brakeType::hold);rightArm.stop(brakeType::hold);}
    }

    if(true){ //Claw | if statement for collapsability
      if(remote.ButtonR1.pressing()){claw.spin(directionType::fwd);}
      else if(remote.ButtonR2.pressing()){claw.spin(directionType::rev);}
      else{claw.stop();}
    }

  }
}
