#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"
//
using namespace vex;
vex::brain Brain;
vex::motor FrontRight (vex::PORT11, vex::gearSetting::ratio18_1,false);
vex::motor BackRight (vex::PORT12, vex::gearSetting::ratio18_1,false);
vex::motor LeftArm (vex::PORT14, vex::gearSetting::ratio18_1,false);
vex::motor RightArm (vex::PORT15, vex::gearSetting::ratio18_1,true);
vex::motor Claw (vex::PORT16, vex::gearSetting::ratio18_1,false);
vex::motor BackLeft (vex::PORT18, vex::gearSetting::ratio18_1,true);
vex::motor FrontLeft (vex::PORT19, vex::gearSetting::ratio18_1,true);
vex::controller Controller1;