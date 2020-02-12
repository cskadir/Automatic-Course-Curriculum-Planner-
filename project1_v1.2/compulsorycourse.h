//author cs.kadir

#ifndef COMPULSORYCOURSE_H
#define COMPULSORYCOURSE_H

#include "course.h"

using namespace std;


class compulsoryCourse : public course
{
    public:
        compulsoryCourse();
        compulsoryCourse(string codeOfCourse, string nameOfCourse, int yearOfSem, int credit, char dOrS, string nameOfIns);

        virtual ~compulsoryCourse();

    protected:

    private:
};

#endif // COMPULSORYCOURSE_H
