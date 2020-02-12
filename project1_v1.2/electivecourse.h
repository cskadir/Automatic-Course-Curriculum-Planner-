//author cs.kadir

#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

using namespace std;

#include "course.h"


class electiveCourse : public course
{
    public:
        electiveCourse();
        electiveCourse(string codeOfCourse, string nameOfCourse,int yearOfSem,int credit,char dOrS,string nameOfIns);
        virtual ~electiveCourse();

    protected:

    private:
};

#endif // ELECTIVECOURSE_H
