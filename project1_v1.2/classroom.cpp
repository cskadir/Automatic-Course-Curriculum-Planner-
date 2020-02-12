//author cs.kadir

#include "classroom.h"

classroom::classroom()
{
    //ctor
}

classroom::~classroom()
{
    //dtor
}
classroom::classroom(string name)
{
    this->name=name;
}

string classroom::getName()
{
    return name;
}
