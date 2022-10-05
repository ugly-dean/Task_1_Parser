#ifndef TASK_1_SENSORPNITRAX_H
#define TASK_1_SENSORPNITRAX_H

#include <cstdint>

float const FLT_DFLT = 0.0;
char const CHR_DFLT = '\0';
bool const BOOL_DFLT = false;

struct SensorPNITrax
{
    // IDs:
    static uint8_t const HEADING        = 5;
    static uint8_t const PITCH          = 24;
    static uint8_t const ROLL           = 25;
    static uint8_t const HEAD_STATUS    = 79;
    static uint8_t const QUATERNION     = 77;
    static uint8_t const TEMPERATURE    = 7;
    static uint8_t const DISTORTION     = 8;
    static uint8_t const CAL_STATUS     = 9;
    static uint8_t const ACCEL_X        = 21;
    static uint8_t const ACCEL_Y        = 22;
    static uint8_t const ACCEL_Z        = 23;
    static uint8_t const MAG_X          = 27;
    static uint8_t const MAG_Y          = 28;
    static uint8_t const MAG_Z          = 29;
    static uint8_t const GYRO_X         = 74;
    static uint8_t const GYRO_Y         = 75;
    static uint8_t const GYRO_Z         = 76;
    // Fields:
    float kHeading          = FLT_DFLT;
    float kPitch            = FLT_DFLT;
    float kRoll             = FLT_DFLT;
    float kQuaternion[4]    = {FLT_DFLT, };
    float kTemperature      = FLT_DFLT;
    float kAccelX           = FLT_DFLT;
    float kAccelY           = FLT_DFLT;
    float kAccelZ           = FLT_DFLT;
    float kMagX             = FLT_DFLT;
    float kMagY             = FLT_DFLT;
    float kMagZ             = FLT_DFLT;
    float kGyroX            = FLT_DFLT;
    float kGyroY            = FLT_DFLT;
    float kGyroZ            = FLT_DFLT;
    char  kHeadingStatus    = CHR_DFLT;
    bool  kDistortion       = BOOL_DFLT;
    bool  kCalStatus        = BOOL_DFLT;

};

#endif //TASK_1_SENSORPNITRAX_H
