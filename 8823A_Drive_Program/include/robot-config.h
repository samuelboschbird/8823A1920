#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"
//
using namespace vex;
vex::brain brain;
vex::motor frontRight (vex::PORT11, vex::gearSetting::ratio18_1,false);
vex::motor backRight (vex::PORT12, vex::gearSetting::ratio18_1,false);
vex::motor leftArm (vex::PORT14, vex::gearSetting::ratio18_1,false);
vex::motor rightArm (vex::PORT15, vex::gearSetting::ratio18_1,true);
vex::motor claw (vex::PORT16, vex::gearSetting::ratio18_1,false);
vex::motor backLeft (vex::PORT18, vex::gearSetting::ratio18_1,true);
vex::motor frontLeft (vex::PORT19, vex::gearSetting::ratio18_1,true);
vex::controller remote;