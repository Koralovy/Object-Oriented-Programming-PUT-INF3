#ifndef __Logger_H__
#define __Logger_H__
using namespace std;

class Logger{
private:
    bool debug = false;

public:
    Logger(bool debug);
    void log(const char *x);
};

#endif // __Logger_H__