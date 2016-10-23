#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <list>
#include <iostream>
#include "Event.h"

using namespace std;

class Student
{
    public:
        Student();
        Student(string first, string last);
        ~Student();

        string getname() const{
            return (lname + ", " + fname);
        }

        void addevent(list<Event> &schedule)
        {
            Event eve = Event();
            string in;
            cout << "Invite Level: (Study Group, Class) -";
            cin >> in;
            eve.setlevel(in);
            cout << "Description: -";
            cin >> in;
            eve.setdescription(in);
            cout << "Date: -";
            cin >> in;
            eve.setstartdate(in);
            eve.setcreator(this->getname());

            schedule.push_back(eve);
        }

    private:
        string lname;///Last name, will be combined with finitial during output
        string fname;///First letter of students first name. will be combined with name during output
};

inline
bool operator== (const Student& left, const Student& right)
{
    return(left.getname() == right.getname());
}

#endif // STUDENT_H
