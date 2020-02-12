//author cs.kadir

#ifndef PLAN_H
#define PLAN_H
#include<string>
#include <fstream>
#include <vector>
#include"course.h"
#include <exception>
#include"classroom.h"
#include"service.h"
#include"electivecourse.h"
#include"compulsorycourse.h"
#include"smallclass.h"
#include"bigclass.h"

using namespace std;



//time 0 =>Morning
//time 1 =>Afternoon
class plan
{
    public:
        plan();
        virtual ~plan();
        void setDay(string day);
        void setTime(string time);
        void setClassroom(classroom k_class);
        void setCourse(course k_course);
        void setIsEmpty(bool empt);
        string show();
        string getDay();
        string getTime();
        classroom getClassroom();
        course getCourse();
        bool getIsEmpty();
        void removeCourse();

    protected:

    private:

        string day;
        string time;
        classroom k_class;
        course k_course;
        bool isEmpty;


};


#endif // PLAN_H
