#ifndef CLASSROOMBASE_H
#define CLASSROOMBASE_H


class classroomBase
{
    public:
        classroomBase();
        virtual ~classroomBase();
        virtual int classType()=0;

    protected:

    private:
};

#endif // CLASSROOMBASE_H
