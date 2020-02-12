//author cs.kadir

#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>

using namespace std;

class course
{
    public:
        course();
        virtual ~course();
        course(string codeOfCourse, string nameOfCourse,int yearOfSem,int credit,char dOrS,string nameOfIns);
        string getCodeOfCourse();
        string getNameOfCourse();
        string getNameOfInse();
        int getYearOfSem();
        int getCredit();
        char getKindOfCourse();
        char getdOrS();
        void setcodeOfCourse(string codeOfCourse);
        void setnameOfCourse(string nameOfCourse);
        void setyearOfSem(int yearOfSem);
        void setcredit(int credit);
        void setdOrS(char dOrS);
        void setnameOfIns(string nameOfIns);

    protected:

    private:

        string codeOfCourse;
        string nameOfCourse;
        int yearOfSem;
        int credit;
        char dOrS;
        string nameOfIns;

};

#endif // COURSE_H
