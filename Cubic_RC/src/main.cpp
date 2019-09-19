#include "robot-config.h"
          

int main() {
    float leftDriveValue;
    float leftDriveValue2;
    
    float rightDriveValue;
    float rightDriveValue2;
    
    while(true){
        leftDriveValue = Controller1.Axis3.position(percentUnits::pct);
        
        if(abs(leftDriveValue) < 10){
            leftDriveValue = 0;
        }
        leftDriveValue2 = pow(leftDriveValue/100, 3.0)*100;
        
        LeftDrive.spin(directionType::fwd,leftDriveValue2,velocityUnits::pct);
        
        
        rightDriveValue = Controller1.Axis2.position(percentUnits::pct);
        
        if(abs(rightDriveValue) < 10){
            rightDriveValue = 0;
        }
        rightDriveValue2 = pow(rightDriveValue/100, 3.0)*100;
        
        RightDrive.spin(directionType::fwd,rightDriveValue2,velocityUnits::pct);
    }
}