#include <sstream>
#include "tests.h"
#include "SensorPNITrax.h"
#include "SensorParser.h"

int TEST_Sensor_PNI_Trax()
{
    int EXIT_STATUS = EXIT_SUCCESS;
    SensorPNITrax S1;

    for (float i : S1.kQuaternion) {
        if (i != FLT_DFLT) {
            EXIT_STATUS += EXIT_FAILURE;
            break;
        }
    }

    return EXIT_STATUS;
}

int TEST_string_to_bytes()
{
    int EXIT_STATUS = EXIT_SUCCESS;

    std::string s = "0550A789";
    size_t index = 0;
    int byte = SensorParser::string_to_bytes(s, index);
    if (byte != 5)
        EXIT_STATUS +=EXIT_FAILURE;
    byte = SensorParser::string_to_bytes(s, index);
    if (byte != 80)
        EXIT_STATUS += EXIT_FAILURE;
    byte = SensorParser::string_to_bytes(s, index);
    if (byte != 167)
        EXIT_STATUS += EXIT_FAILURE;
    byte = SensorParser::string_to_bytes(s, index);
    if (byte != 137)
        EXIT_STATUS += EXIT_FAILURE;
    return EXIT_STATUS;
}

int TEST_bytes_to_float()
{
    int EXIT_STATUS = EXIT_SUCCESS;

    size_t index = 0;
    float f = SensorParser::bytes_to_float("41A40000", index);
    if (f != 20.5)
        EXIT_STATUS += EXIT_FAILURE;

    return EXIT_STATUS;
}

int TEST_full_1()
{
    int EXIT_STATUS = EXIT_SUCCESS;

    SensorPNITrax S;
    std::istringstream in("053F80000009011C40000000\n");
    std::ostringstream out;
    SensorParser::receive_PNI_Trax_data(in, out, S);

    std::string str_example =
            "sens.kHeading = 1.00000000\n"
            "sens.kCalStatus = true\n"
            "sens.kMagY = 2.00000000\n";
    std::string str_out = out.str();
    if (str_out != str_example)
        EXIT_STATUS += EXIT_FAILURE;

    return EXIT_STATUS;
}

int TEST_full_2()
{
    int EXIT_STATUS = EXIT_SUCCESS;

    SensorPNITrax S;
    std::istringstream in("4C41A400004B3F91BCD8\n");
    std::ostringstream out;
    SensorParser::receive_PNI_Trax_data(in, out, S);

    std::string str_example =
            "sens.kGyroZ = 20.50000000\n"
            "sens.kGyroY = 1.13857555\n";
    std::string str_out = out.str();
    if (str_out != str_example)
        EXIT_STATUS += EXIT_FAILURE;

    return EXIT_STATUS;
}

int TEST_full_3()
{
    int EXIT_STATUS = EXIT_SUCCESS;

    SensorPNITrax S;
    std::istringstream in("0741A40000053F91BCD819413547AE\n");
    std::ostringstream out;
    SensorParser::receive_PNI_Trax_data(in, out, S);

    std::string str_example =
            "sens.kTemperature = 20.50000000\n"
            "sens.kHeading = 1.13857555\n"
            "sens.kRoll = 11.32999992\n";
    std::string str_out = out.str();
    if (str_out != str_example)
        EXIT_STATUS += EXIT_FAILURE;

    return EXIT_STATUS;
}

int TEST_full_4()
{
    int EXIT_STATUS = EXIT_SUCCESS;

    SensorPNITrax S;
    std::istringstream in("05430D083B183F91BCD8193EDF4DE94D422869E241F8F5C341DEC28F3C594D0E\n");
    std::ostringstream out;
    SensorParser::receive_PNI_Trax_data(in, out, S);

    std::string str_example =
            "sens.kHeading = 141.03215027\n"
            "sens.kPitch = 1.13857555\n"
            "sens.kRoll = 0.43614128\n"
            "sens.kQuaternion[0] = 42.10340118\n"
            "sens.kQuaternion[1] = 31.12000084\n"
            "sens.kQuaternion[2] = 27.84499931\n"
            "sens.kQuaternion[3] = 0.01326300\n";
    std::string str_out = out.str();
    if (str_out != str_example)
        EXIT_STATUS += EXIT_FAILURE;

    return EXIT_STATUS;
}

int TEST_full_5()
{
    int EXIT_STATUS = EXIT_SUCCESS;

    SensorPNITrax S;
    std::istringstream in("05430D083B183F91BCD8193EDF4DE94F00080015BCA408C0163BFB4DAB173F80F5081BC16EA4371CC1"
                          "2D31271D42513D4F4A000000004B000000004C00000000\n");
    std::ostringstream out;
    SensorParser::receive_PNI_Trax_data(in, out, S);

    std::string str_example =
            "sens.kHeading = 141.03215027\n"
            "sens.kPitch = 1.13857555\n"
            "sens.kRoll = 0.43614128\n"
            "sens.kHeadingStatus = 0\n"
            "sens.kDistortion = false\n"
            "sens.kAccelX = -0.02002370\n"
            "sens.kAccelY = 0.00766917\n"
            "sens.kAccelZ = 1.00747776\n"
            "sens.kMagX = -14.91509151\n"
            "sens.kMagY = -10.82450008\n"
            "sens.kMagZ = 52.30987167\n"
            "sens.kGyroX = 0.00000000\n"
            "sens.kGyroY = 0.00000000\n"
            "sens.kGyroZ = 0.00000000\n";
    std::string str_out = out.str();
    if (str_out != str_example)
        EXIT_STATUS += EXIT_FAILURE;

    return EXIT_STATUS;
}
