//author cs.kadir

#include "scheduler.h"


scheduler::scheduler()
{
    //ctor
}

scheduler::~scheduler()
{
    //dtor
    delete this;
}

 void scheduler::readCourses(){

    ifstream inp;
    inp.exceptions ( ifstream::badbit );
    string st1;
    string st2;
    string st3;
    char ch1;
    char ch2;
    char tmp;
    int i1;
    int i2;
    try {

    inp.open("courses.csv");
    while(inp.good())
    {
        getline(inp,st1,';');
        getline(inp,st2,';');
        inp>>i1;
        inp.get(tmp);
        inp>>i2;
        inp.get(tmp);inp.get(ch1);
        inp.get(tmp);inp.get(ch2);
        inp.get(tmp);
        getline(inp,st3,'\n');
        ;
        if(ch1=='E'){
            electiveCourse tempCourse(st1,st2,i1,i2,ch2,st3);
            electiveCourses.push_back(tempCourse);
        }

        else if(ch1=='C')
        {
            compulsoryCourse tempCourse(st1,st2,i1,i2,ch2,st3);
            compulsoryCourses.push_back(tempCourse);
        }

    }
   }
  catch (const ifstream::failure& e) {
    cout << "Exception opening/reading file";
  }
    inp.close();
 }

 void scheduler::showCourses()
 {
     cout<<"Elective"<<endl;
     for(int i=0;i<electiveCourses.size();i++){
         cout<<electiveCourses[i].getCodeOfCourse()<<" "<<electiveCourses[i].getNameOfCourse()<<" "<<electiveCourses[i].getYearOfSem()<<" "<<electiveCourses[i].getCredit()<<" "<<electiveCourses[i].getdOrS()<<" "<<electiveCourses[i].getNameOfInse()<<endl;
     }

    cout<<"Complusory"<<endl;
    for(int i=0;i<compulsoryCourses.size();i++){
         cout<<compulsoryCourses[i].getCodeOfCourse()<<" "<<compulsoryCourses[i].getNameOfCourse()<<" "<<compulsoryCourses[i].getYearOfSem()<<" "<<compulsoryCourses[i].getCredit()<<" "<<compulsoryCourses[i].getdOrS()<<" "<<compulsoryCourses[i].getNameOfInse()<<endl;
     }

 }

void scheduler::readClasroom()
{
    string name;
    int count;
    int tmp;
    try {

    ifstream inp("classroom.csv");
    while(inp.good())
    {
        getline(inp,name,';');
        inp>>count;
        int k=1;
        for(int i=0;i<count;i++){
            string temp=name;
            string kk=to_string(k);
            temp=name+kk;
            if(name=="smallClass"){
                smallClass sc(temp);
                smallClassroom.push_back(sc);
            }
            else if(name=="bigClass"){
                bigClass bc(temp);
                bigClassroom.push_back(bc);
            }
            k++;
        }
        inp.get();

    }
    inp.close();
   }
  catch (const ifstream::failure& e) {
    cout << "Exception opening/reading file";
  }
}

void scheduler::showClass()
{
    for(int i=0;i<bigClassroom.size();i++)
        cout<<bigClassroom[i].getName()<<endl;
}

void scheduler::readService()
{
    string coursName;
    string day;
    string time;
    try {

    ifstream inp("service.csv");
    while(inp.good())
    {
        getline(inp,coursName,';');
        getline(inp,day,';');
        getline(inp,time,'\n');
        serviceandbusy temp(coursName,day,time);
        serviceVector.push_back(temp);
    }
    inp.close();
   }
  catch (const ifstream::failure& e) {
    cout << "Exception opening/reading file";
  }
}

void scheduler::showService()
{
    for(int i=0;i<serviceVector.size();i++)
        serviceVector[i].getService();
}

void scheduler::readBusy()
{
    string coursName;
    string day;
    string time;
    try {

    ifstream inp("busy.csv");
    while(inp.good())
    {
        getline(inp,coursName,';');
        //cout<<coursName<<endl;
        getline(inp,day,';');
        //cout<<day<<endl;
        getline(inp,time,'\n');
        //cout<<time<<endl;
        serviceandbusy temp(coursName,day,time);
        busyVector.push_back(temp);
    }
    inp.close();
   }
  catch (const ifstream::failure& e) {
    cout << "Exception opening/reading file";
  }
}

void scheduler::showBusy()
{
    for(int i=0;i<busyVector.size();i++)
        busyVector[i].getService();
}

int scheduler::getCountSlot()
{
    return (bigClassroom.size()*2+smallClassroom.size()*2);
}

int scheduler::createPlan(int countSlot=0)
{

    string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};

    int kk=0;
    plan _plan;
    for(int i=0;i<5*countSlot;i++)
        planet.push_back(_plan);
    if(planet.size()<compulsoryCourses.size()+electiveCourses.size()&&bigClassroom.size()<compulsoryCourses.size())
        return 0;


    for(int i=0;i<5;i++){
        for(int j=0;j<bigClassroom.size();j++){
            planet[kk].setDay(days[i]);
            planet[kk].setClassroom(bigClassroom[j]);
            planet[kk].setTime("Morning");
            kk++;
        }

        for(int j=0;j<smallClassroom.size();j++){
            planet[kk].setDay(days[i]);
            planet[kk].setClassroom(smallClassroom[j]);
            planet[kk].setTime("Morning");
            kk++;
        }

        for(int j=0;j<bigClassroom.size();j++){
            planet[kk].setDay(days[i]);
            planet[kk].setClassroom(bigClassroom[j]);
            planet[kk].setTime("Afternoon");
            kk++;
        }

        for(int j=0 ;j<smallClassroom.size();j++){
            planet[kk].setDay(days[i]);
            planet[kk].setClassroom(smallClassroom[j]);
            planet[kk].setTime("Afternoon");
            kk++;
        }


    }

    return 1;
}

void scheduler::setServiceCourses()
{
    for(int i=0;i<serviceVector.size();i++){

        string courseCode=serviceVector[i].getCodeOfCourse();
        string day=serviceVector[i].getDay();
        string time=serviceVector[i].getTime();
        course temp;
        int flag=-1;
        for(int i=0;i<compulsoryCourses.size();i++){
            if(courseCode.compare(compulsoryCourses[i].getCodeOfCourse())==0){
                flag=1;
                temp=compulsoryCourses[i];
            }
        }
        for(int i=0;i<electiveCourses.size();i++){
            if(courseCode.compare(electiveCourses[i].getCodeOfCourse())==0){
                flag=0;
                temp=electiveCourses[i];
            }
        }
        if(flag==1){
            for(int i=0;i<planet.size();i++){
                if(planet[i].getDay()==day&&planet[i].getTime()==time&&planet[i].getIsEmpty()==true&&searchCourse(temp)==0){
                    planet[i].setCourse(temp);
                }
            }
        }
        else{
            for(int i=0;i<planet.size();i++){
                if(planet[i].getDay()==day&&planet[i].getTime()==time&&planet[i].getIsEmpty()==true&&searchCourse(temp)==0
                   &&planet[i].getClassroom().getName().at(0)=='s'){
                    planet[i].setCourse(temp);
                }
            }
        }

    }
}

void scheduler::showPlan()
{
    ofstream myfile;
    myfile.open ("scheduler.txt");

    for(int i=0;i<planet.size();i++){
         myfile << planet[i].show()<<endl;
    }
    myfile.close();

}

int scheduler::searchCourse(course temp)
{
    for(int i=0;i<planet.size();i++){

        if(((planet[i].getCourse()).getCodeOfCourse()).compare(temp.getCodeOfCourse())==0)
                return 1;
    }
            return 0;
}

void scheduler::setCompCourses()
{
    srand (time(NULL));

    for(int i=0;i<compulsoryCourses.size();i++){
        int kk=0;
        int rndm;
        if(isCourseService(compulsoryCourses[i])==false){
                while(kk==0){
               // cout<<compulsoryCourses[i].getCodeOfCourse();
                rndm=rand() % planet.size();
               // cout<<" "<<rndm<<endl;
                if(planet[rndm].getIsEmpty()==true&&planet[rndm].getClassroom().getName().at(0)=='b'){
                    kk=1;
                 //   cout<<rndm<<" numarali index bos";
                    planet[rndm].setCourse(compulsoryCourses[i]);
                    if(checkBusy(planet[rndm])==false){
                        if(checkIntersect(planet[rndm])==false){
                     //       cout<<rndm<<" intersect degil"<<endl;
                            kk=1;
                        }
                        else{
                            kk=0;
                          //  cout<<"intersect"<<endl;
                            planet[rndm].removeCourse();
                        }

                }
                else{
                   kk=0;
                   planet[rndm].removeCourse();
                }
               }
               else{
                kk=0;
               }
            }
        }
    }



}

void scheduler::setElectCourses()
{
    srand (time(NULL));

    for(int i=0;i<electiveCourses.size();i++){
        int kk=0;
        int rndm;
        if(isCourseService(electiveCourses[i])==false){
                while(kk==0){
               // cout<<electiveCourses[i].getCodeOfCourse();
                rndm=rand() % planet.size();
               //cout<<" "<<rndm<<endl;
                if(planet[rndm].getIsEmpty()==true){
                    kk=1;
                  // cout<<rndm<<" numarali index bos";
                    planet[rndm].setCourse(electiveCourses[i]);
                    if(checkBusy(planet[rndm])==false){
                        if(checkIntersect(planet[rndm])==false){
                           // cout<<rndm<<" intersect degil"<<endl;
                            kk=1;
                        }
                        else{
                            kk=0;
                         //   cout<<"intersect"<<endl;
                            planet[rndm].removeCourse();
                        }

                }
                else{
                   kk=0;
                   planet[rndm].removeCourse();
                }
               }
               else{
                kk=0;
               }
            }
        }
    }//author cs.kadir

}

inline bool scheduler::checkBusy(plan temp)
{
    for(int i=0;i<busyVector.size();i++)
        if(temp.getCourse().getCodeOfCourse()==busyVector[i].getCodeOfCourse()&&
           temp.getDay()==busyVector[i].getDay()&&
           temp.getTime()==busyVector[i].getTime())
            return true;
    return false;
}

bool scheduler::checkIntersect(plan temp)
{
    for(int i=0;i<planet.size();i++){
       // cout<<endl<<temp.getDay()<<"--"<<planet[i].getDay()<<endl;
       // cout<<temp.getTime()<<"--"<<planet[i].getTime()<<endl;
       // cout<<temp.getCourse().getYearOfSem()<<"--"<<planet[i].getCourse().getYearOfSem()<<endl;

           if(temp.getCourse().getCodeOfCourse()!=planet[i].getCourse().getCodeOfCourse()&&
           planet[i].getIsEmpty()==false&&
           temp.getDay()==planet[i].getDay()&&
           temp.getTime()==planet[i].getTime()&&
           temp.getCourse().getYearOfSem()==planet[i].getCourse().getYearOfSem()){

            //   cout<<"if in ici"<<i<<endl;
                return true;
           }

    }
    return false;

}

bool scheduler::isCourseService(course temp)
{
    for(int i=0;i<serviceVector.size();i++)
        if(temp.getCodeOfCourse()==serviceVector[i].getCodeOfCourse())
            return true;
    return false;
}


