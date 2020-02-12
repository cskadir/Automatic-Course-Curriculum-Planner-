//author cs.kadir

#ifndef BIGCLASS_H
#define BIGCLASS_H

#include "classroom.h"

using namespace std;

class bigClass : public classroom
{
    public:
        bigClass();
        bigClass(string name);
        virtual ~bigClass();

    protected:

    private:
};

#endif // BIGCLASS_H
