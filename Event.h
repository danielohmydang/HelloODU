#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <iostream>

using namespace std;

class Event
{
    public:
        Event();
        Event(string lev, string desc, string crea, string date)
        {
            level = lev;
            description = desc;
            creator = crea;
            startdate = date;
        }
        virtual ~Event();

        void setlevel(string lev){level = lev;}
        void setcreator(string crea){creator = crea;}
        void setdescription(string desc){description = desc;}
        void setstartdate(string date){startdate = date;}

        string getlevel(){return level;}

        void display()
        {
            cout << "----------------------------------------------------------------------" << endl;
            cout << "Group " << level << " Event: by " << creator << endl << "-" << description << endl << "Begins - " << startdate << endl;
            cout << "----------------------------------------------------------------------" << endl;
        }

    private:
        string startdate;///format hh:mm mm/dd/yyyy
        string creator;
        string level;
        string description;
};

#endif // EVENT_H
