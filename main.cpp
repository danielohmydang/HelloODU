#include <iostream>
#include <fstream>
#include <list>
#include "Instructor.h"
#include "StudyGroup.h"
#include "Student.h"
#include "Homework.h"

using namespace std;

int main()
{
    Instructor zeil = Instructor("CS350");
    Instructor morris = Instructor("CS355");

    list<Student> slist;

    ifstream input ("names_A.txt");
    string fname;
    string lname;

    if (!input)
    {
        cout<<"Could not open file"<<endl;
        return 1;
    }
    while(input >> fname)
    {
        input >> lname;
        Student stu = Student(fname, lname);
        slist.push_back(stu);
        ///cout<< "Added " << fname << " " << lname << " to list." << endl;
    }

    zeil.assignStudyGroup(slist);
    slist.clear();

    input.close();

    input.open("names_B.txt");
    if (!input)
    {
        cout<<"Could not open file"<<endl;
        return 1;
    }
    while(input >> fname)
    {
        input >> lname;
        Student stu = Student(fname, lname);
        slist.push_back(stu);
    }

    morris.assignStudyGroup(slist);
    slist.clear();

    input.close();

    zeil.liststudents();
    morris.liststudents();

    cout << endl << "------------------" << endl;
    char cont = ' ';
    string in;
    bool found = false;

    list<Student> profile;
    list<Student>::iterator pitr;
    list<string> levels;
    list<string>::iterator litr;
    list<Event> calendar;
    list<Event>::iterator citr;

    cout << "Continue? (y/n) -";
    cin >> cont;

    while(cont != 'n')
    {
        profile.clear();
        levels.clear();
        cout << "Student Login" << endl << "Enter First Name: ";
        cin >> fname;
        cout << "Enter Last Name: ";
        cin >> lname;
        Student stu = Student(fname, lname);
        cout << "Searching" << endl << "-----------";

        zeil.findstudent(stu, found, pitr);
        zeil.listlevels(stu, found, levels);
        if(found)
        {
            profile.push_back(*pitr);
            found = false;
        }
        morris.findstudent(stu, found, pitr);
        morris.listlevels(stu, found, levels);
        if(found)
        {
            profile.push_back(*pitr);
            found = false;
        }
        if(profile.size() != 0){
            while(cont != 'n'){

                cout << "Task? (Create, View) -";
                cin >> in;
                if (in == "Create" || in == "create"){
                    Event eve = Event();

                    pitr = profile.begin();
                    eve.setcreator(pitr->getname());

                    cout << "Starting Event creation: Creator - " << pitr->getname() << endl << endl;

                    cout << "What level is this event at? " << endl;
                    cont = 'n';
                    while(cont != 'y' && levels.size() != 0){
                        cin.ignore();
                        for (litr = levels.begin(); litr != levels.end(); litr++){cout << " | " << *litr << " | ";}
                        cout << endl << "Level: ";
                        getline(cin, in);
                        cout << in << endl;
                        for (litr = levels.begin(); litr != levels.end(); litr++){if(in == *litr){cont = 'y';}}
                        if (cont == 'n'){cout << "Invalid level, Please pick from provided choices." << endl;}
                        else {eve.setlevel(in);}
                    }

                    cout << endl << "What is the description for the event? " << endl;
                    getline(cin, in);
                    eve.setdescription(in);

                    cout << endl << "When will the Event take place? (hh:mm mm/dd/yyyy) -";
                    getline(cin, in);
                    eve.setstartdate(in);

                    calendar.push_back(eve);
                }
                else if(in == "View" || in == "view"){
                    for(citr = calendar.begin(); citr != calendar.end(); citr++){
                        for(litr = levels.begin(); litr != levels.end(); litr++){
                            if (*litr == citr->getlevel()){citr->display();}
                        }
                    }
                }
                cout << "Continue with another Task? (y/n) -";
                cin >> cont;
            }
            cout << "Login as a different User? (y/n) -";
            cin >> cont;
        }
        else{
            cout << "Could not find student. Try Again? (y/n) -";
            cin >> cont;
        }
        profile.clear();
    }
    return 0;
}
