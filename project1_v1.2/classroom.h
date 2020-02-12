//author cs.kadir

#ifndef CLASSROOM_H
#define CLASSROOM_H
#include<iostream>
#include<string>

using namespace std;

class classroom
{
public:
    classroom();
    classroom(string name);
    string getName();
    int getCount();

    virtual ~classroom();





private:
    string name;
};

#endif // CLASSROOM_H
