#ifndef __Wezel_H__
#define __Wezel_H__
#include <memory>
using namespace std;

class Wezel{
public:
    shared_ptr<Wezel> next;
    weak_ptr<Wezel> nextweak;
    ~Wezel();

};

#endif // __Wezel_H__