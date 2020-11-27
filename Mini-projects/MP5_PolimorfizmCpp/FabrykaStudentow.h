#ifndef __FabrykaStudentow_H__
#define __FabrykaStudentow_H__
#include "Student.h"
#include "FabrykaOsob.h"

class FabrykaStudentow : public FabrykaOsob{
public:
    Student* utworz();
};

#endif // __FabrykaStudentow_H__