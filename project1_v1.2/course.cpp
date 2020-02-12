//author cs.kadir

#include "course.h"
#include<string>


course::course()
{
    //ctor
}
course::course(string codeOfCourse, string nameOfCourse,int yearOfSem,int credit,char dOrS,string nameOfIns){
            this->codeOfCourse=codeOfCourse;
            this->nameOfCourse=nameOfCourse;
            this->yearOfSem=yearOfSem;
            this->credit=credit;
            this->dOrS=dOrS;
            this->nameOfIns=nameOfIns;
        }

course::~course()
{
    //dtor
}



string course::getCodeOfCourse(){
    return codeOfCourse;
}
string course::getNameOfCourse(){
    return nameOfCourse;
}
string course::getNameOfInse(){
    return nameOfIns;
}
int course::getYearOfSem(){
    return yearOfSem;
}
int course::getCredit(){
    return credit;
}

char  course::getdOrS(){
    return dOrS;
}
void course::setcodeOfCourse(string codeOfCourse)
{
    this->codeOfCourse=codeOfCourse;
}

void course::setnameOfCourse(string nameOfCourse)
{
    this->nameOfCourse=nameOfCourse;
}
void course::setyearOfSem(int yearOfSem)
{
    this->yearOfSem=yearOfSem;
}

void course::setcredit(int credit)
{
    this->credit=credit;
}

void course::setdOrS(char dOrS)
{
    this->dOrS=dOrS;
}

void course::setnameOfIns( string nameOfIns)
{
    this->nameOfIns=nameOfIns;
}

