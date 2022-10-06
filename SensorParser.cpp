#include <iostream>
#include <iomanip>
#include "SensorParser.h"

#define ERROR_ID "Wrong ID: "

#define PROCESS_FLOAT(PAR) \
PAR = bytes_to_float(bytes, index); \
out << #PAR << " = " << std::fixed << std::setprecision(FLT_PRECISION) << (PAR) << std::endl; \
break;

#define PROCESS_CHAR(PAR) \
PAR = (char) string_to_bytes(bytes, index); \
out << #PAR << " = " << ((int) (PAR)) << std::endl; \
break;

#define PROCESS_BOOL(PAR) \
PAR = (bool) string_to_bytes(bytes, index); \
out << #PAR << " = " << std::boolalpha << (PAR) << std::endl; \
break;

#define PROCESS_FLOAT_ARR(PAR, SIZE) \
for (size_t i = 0; i < SIZE; ++i) {  \
    PAR[i] = bytes_to_float(bytes, index); \
    out << #PAR << '[' << i << "] = " << PAR[i] << std::endl; \
} \
break;

size_t const FLT_PRECISION = 8;

uint8_t SensorParser::string_to_bytes(std::string const & bytes, size_t & index)
{
    uint8_t res = 0;
    uint8_t high = isdigit(bytes[index]) ?
                   bytes[index] - '0' :
                   bytes[index] - 'A' + 10;
    ++index;
    uint8_t low = isdigit(bytes[index]) ?
                  bytes[index] - '0' :
                  bytes[index] - 'A' + 10;
    res = (high << 4) + low;
    ++index;
    return res;
}

float SensorParser::bytes_to_float(std::string const & bytes, size_t & index)
{
    size_t CHARS = 4;
    uint8_t b[CHARS];
    for (size_t i = 0; i < CHARS; ++i) {
        b[CHARS - i - 1] = string_to_bytes(bytes, index);
    }
    auto fp = reinterpret_cast<float *>(b);
    return *fp;
}

int SensorParser::receive_PNI_Trax_data(std::istream & in, std::ostream & out, SensorPNITrax & sens)
{
    int EXIT_STATUS = EXIT_SUCCESS;

    std::string bytes;
    std::getline(in, bytes);
    if (bytes.size() < 2) {
        return EXIT_FAILURE;
    }

    size_t index = 0;
    int ID = 0;

    while (index < bytes.size()) {
        ID = string_to_bytes(bytes, index);
        EXIT_STATUS = process_ID(bytes, index, ID, sens, out);
        if (EXIT_STATUS != EXIT_SUCCESS) {
            break;
        }
    }
    return EXIT_STATUS;
}

int SensorParser::process_ID(std::string const & bytes, size_t & index,
                      int ID, SensorPNITrax & sens, std::ostream & out)
{
    int EXIT_STATUS = EXIT_SUCCESS;
    using PNI = SensorPNITrax;
    switch (ID) {
        case PNI::HEADING:
            PROCESS_FLOAT(sens.kHeading);
        case PNI::PITCH:
            PROCESS_FLOAT(sens.kPitch);
        case PNI::ROLL:
            PROCESS_FLOAT(sens.kRoll);
        case PNI::HEAD_STATUS:
            PROCESS_CHAR(sens.kHeadingStatus);
        case PNI::QUATERNION:
            PROCESS_FLOAT_ARR(sens.kQuaternion, 4);
        case PNI::TEMPERATURE:
            PROCESS_FLOAT(sens.kTemperature);
        case PNI::DISTORTION:
            PROCESS_BOOL(sens.kDistortion);
        case PNI::CAL_STATUS:
            PROCESS_BOOL(sens.kCalStatus);
        case PNI::ACCEL_X:
            PROCESS_FLOAT(sens.kAccelX);
        case PNI::ACCEL_Y:
            PROCESS_FLOAT(sens.kAccelY);
        case PNI::ACCEL_Z:
            PROCESS_FLOAT(sens.kAccelZ);
        case PNI::MAG_X:
            PROCESS_FLOAT(sens.kMagX);
        case PNI::MAG_Y:
            PROCESS_FLOAT(sens.kMagY);
        case PNI::MAG_Z:
            PROCESS_FLOAT(sens.kMagZ);
        case PNI::GYRO_X:
            PROCESS_FLOAT(sens.kGyroX);
        case PNI::GYRO_Y:
            PROCESS_FLOAT(sens.kGyroY)
        case PNI::GYRO_Z:
            PROCESS_FLOAT(sens.kGyroZ);
        default:
            out << ERROR_ID << ID << std::endl;
            EXIT_STATUS = EXIT_FAILURE;
            break;
    }
    return EXIT_STATUS;
}