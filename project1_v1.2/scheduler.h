//author cs.kadir

#ifndef SCHEDULER_H
#define SCHEDULER_H
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
#include"plan.h"
#include<iostream>
#include<cstdlib>
#include <time.h>


using namespace std;

class scheduler
{
    public:
        scheduler();
        virtual ~scheduler();
        void readCourses();
        void showClass();
        void readClasroom();
        void readService();
        void showService();
        void readBusy();
        void showBusy();
        void showCourses();
        int createPlan(int countSlot);
        void showPlan();
        int searchCourse(course temp);
        void setServiceCourses();
        void setCompCourses();
        void setElectCourses();
        inline bool checkBusy(plan temp);
        bool checkIntersect(plan temp);
        bool isCourseService(course temp);
        int getCountSlot();




    protected:

    private:
    vector<course> electiveCourses;
    vector<course> compulsoryCourses;
    vector<bigClass> bigClassroom;
    vector<smallClass>smallClassroom;
    vector<serviceandbusy> serviceVector;
    vector<serviceandbusy> busyVector;
    vector<plan>planet;


};

#endif // SCHEDULER_H
