#include "Logger.h"
#include <iostream>
#include <ctime>
using namespace std;

Logger::Logger(bool debug) : debug(debug) {}

void Logger::log(const char *x){
    time_t rawtime;
    if (debug)
        cerr << "Czas lokalny: " << ctime (&rawtime) << " " << x << endl;
    else
        cout << "Czas lokalny: " << ctime (&rawtime) << " " << x << endl;
}

