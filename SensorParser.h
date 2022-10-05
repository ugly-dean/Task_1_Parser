#ifndef TASK_1_SENSORPARSER_H
#define TASK_1_SENSORPARSER_H

#include <string>
#include "SensorPNITrax.h"

class SensorParser
{
public:
    static uint8_t string_to_bytes(std::string const & bytes, size_t & index);

    static float bytes_to_float(std::string const & bytes, size_t & index);

    static int receive_PNI_Trax_data(std::istream & in, std::ostream & out, SensorPNITrax & sens);

private:
    static int process_ID(std::string const & bytes, size_t & index,
                          int ID, SensorPNITrax & sens, std::ostream & out);
};


#endif //TASK_1_SENSORPARSER_H
