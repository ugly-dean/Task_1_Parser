#include <iostream>
#include "tests.h"

int main() {
    int EXIT_STATUS = EXIT_SUCCESS;

    EXIT_STATUS += TEST_Sensor_PNI_Trax();
    EXIT_STATUS += TEST_string_to_bytes();
    EXIT_STATUS += TEST_bytes_to_float();

    EXIT_STATUS += TEST_full_1();
    EXIT_STATUS += TEST_full_2();
    EXIT_STATUS += TEST_full_3();
    EXIT_STATUS += TEST_full_4();
    EXIT_STATUS += TEST_full_5();

    std::cout << "EXIT_STATUS = " << EXIT_STATUS << std::endl;

    return 0;
}
