//author cs.kadir

#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include <exception>

using namespace std;

class serviceandbusy
{
    public:
        serviceandbusy();
        serviceandbusy(string coursName, string day, string time);
        virtual ~serviceandbusy();
        void getService();
        string getCodeOfCourse();
        string getDay();
        string getTime();

    protected:

    private:
    string courseCode;
    string day;
    string time;
};

#endif // SERVICE_H
