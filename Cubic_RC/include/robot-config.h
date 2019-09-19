#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"
//
using namespace vex;
vex::brain Brain;
vex::motor LeftDrive (vex::PORT1, vex::gearSetting::ratio18_1,false);
vex::motor RightDrive (vex::PORT10, vex::gearSetting::ratio18_1,true);
vex::controller Controller1;