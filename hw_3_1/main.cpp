#include <iostream>

#include "command.h"

int main()
{
    LogToCli ltc;
    print(ltc, "printing to CLI");


    LogToFile ltf("sample_log.txt");
    print(ltf, "line one to file log");
    print(ltf, "line two to file log");

    return 0;
}
