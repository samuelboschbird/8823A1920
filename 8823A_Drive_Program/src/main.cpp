/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Samuel Bosch-Bird                                         */
/*    Created:      Tue Sep 17 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "robot-config.h"

using namespace vex;
          

int main() {
  float leftDriveValue;
  float leftDriveValue2;
    
  float rightDriveValue;
  float rightDriveValue2;
    
  while(true){

    if(true){ //Drive | if statement for collapsability
      leftDriveValue = remote.Axis1.position(percentUnits::pct);

      if(abs(leftDriveValue) < 10){
        leftDriveValue = 0;
      }
      leftDriveValue2 = pow(leftDriveValue/100, 3.0)*100;
        
      frontLeft.spin(directionType::fwd,leftDriveValue2,velocityUnits::pct);
      backLeft.spin(directionType::fwd,leftDriveValue2,velocityUnits::pct);
        
        
      rightDriveValue = remote.Axis2.position(percentUnits::pct);
        
      if(abs(rightDriveValue) < 10){
        rightDriveValue = 0;
      }
      rightDriveValue2 = pow(rightDriveValue/100, 3.0)*100;
        
      frontRight.spin(directionType::fwd,rightDriveValue2,velocityUnits::pct);
      backRight.spin(directionType::fwd,rightDriveValue2,velocityUnits::pct);
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
