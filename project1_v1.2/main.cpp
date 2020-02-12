//author cs.kadir

#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include"course.h"
#include"scheduler.h"
#include <exception>


using namespace std;



int main()
{

    vector<course> arr;
    vector<course> electiveCourse;
    vector<course> compulsoryCourse;

    scheduler k;
    //cout<<"COURSES"<<endl;
    k.readCourses();
    //k.showCourses();

    //cout<<"CLASSROOM"<<endl;
    k.readClasroom();
    //k.showClass();
    //cout<<"SERVICE"<<endl;
    k.readService();
    //k.showService();
    //cout<<"BUSY"<<endl;
    k.readBusy();
    //k.showBusy();

    int flag=k.createPlan(k.getCountSlot());
    if(flag==1){
        k.setServiceCourses();
        k.setCompCourses();
        k.setElectCourses();
        k.showPlan();
    }
    else
        cout<<"SINIF SAYISI DERSLER ICIN YETERSIZ"<<endl;

    return 0;


}

