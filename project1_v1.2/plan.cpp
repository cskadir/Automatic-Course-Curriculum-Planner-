//author cs.kadir


#include "plan.h"

plan::plan()
{
    //ctor
    isEmpty=true;
}

plan::~plan()
{
    //dtor
}

void plan::setDay(string day)
{
    this->day=day;
}

void plan::setTime(string time)
{
    this->time=time;
}

void plan::setClassroom(classroom k_class)
{
    this->k_class=k_class;
}

void plan::setCourse(course k_course)
{
    this->k_course=k_course;
    this->isEmpty=false;
}

void plan::setIsEmpty(bool empt)
{
    this->isEmpty=empt;
}

string plan::show()
{
    return day+" "+time+" "+k_class.getName()+" "+k_course.getCodeOfCourse();
}

string plan::getDay()
{
    return day;
}

string plan::getTime()
{
    return time;
}

classroom  plan::getClassroom()
{
    return k_class;
}

course plan::getCourse()
{
    return k_course;
}

bool plan::getIsEmpty()
{
    return isEmpty;
}

void plan::removeCourse()
{
    course k;
    k_course=k;
    isEmpty=true;
}

