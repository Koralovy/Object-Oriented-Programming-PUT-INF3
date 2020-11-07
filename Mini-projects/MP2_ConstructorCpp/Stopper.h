#include <ctime>
#ifndef __Stopper_H__
#define __Stopper_H__
using namespace std;


class Stopper{
private:
    clock_t t;
    
public:
    void start();
    void stop();
    void reset();
    void print_time();
};

#endif // __Stopper_H__