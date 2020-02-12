//author cs.kadir

#include "service.h"

serviceandbusy::serviceandbusy()
{
    //ctor
}

serviceandbusy::~serviceandbusy()
{
    //dtor
}
serviceandbusy::serviceandbusy(string courseCode,string day,string time)
{
    this->courseCode=courseCode;
    this->day=day;
    this->time=time;
}

void serviceandbusy::getService()
{
    cout<<courseCode<<" "<<day<<" "<<time<<" "<<endl;
}

string serviceandbusy::getCodeOfCourse()
{
    return courseCode;
}

string serviceandbusy::getDay()
{
    return day;
}

string serviceandbusy::getTime()
{
    return time;
}

