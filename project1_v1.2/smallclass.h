//author cs.kadir

#ifndef SMALLCLASS_H
#define SMALLCLASS_H

#include "classroom.h"

using namespace std;

class smallClass : public classroom
{
    public:
        smallClass();
        smallClass(string name);
        virtual ~smallClass();

    protected:

    private:
};

#endif // SMALLCLASS_H
