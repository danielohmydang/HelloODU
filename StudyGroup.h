#ifndef STUDYGROUP_H
#define STUDYGROUP_H

#include <iostream>
#include <list>
#include <string>
#include <sstream>

#include "Student.h"
using namespace std;

class StudyGroup
{
    public:
        StudyGroup();
        StudyGroup(char letter, string prefix)
        {
            stringstream ss;
            ss<<letter;
            ss>>name;
            name = prefix + "_" + name;
        }
        ~StudyGroup();

        void addstudent(Student s){
            members.push_back(s);
        }

        void liststudents(){
            cout<< endl;
            cout<< "Group: " << name << endl << "------------" << endl;
            for(sitr = members.begin(); sitr != members.end(); sitr++){
                cout<< sitr->getname() << endl;
            }
        }

        void findstudent(Student stu, bool& found, list<Student>::iterator& pitr)
        {
            for(sitr = members.begin(); sitr != members.end(); sitr++){
                if (stu == *sitr){
                    cout << "Account found:" << endl << sitr->getname() << endl;
                    cout << "Member of Group " << this->name << endl;
                    found = true;
                    pitr = sitr;
                }
            }
        }

        void listlevels(Student stu, bool& found, list<string>& levels)
        {
            for(sitr = members.begin();sitr!= members.end(); sitr++){
                if (stu == *sitr){
                    levels.push_back("Group " + name);
                }
            }
        }

        string getname(){
            return name;
        }

    private:
        string name;///Name of group and will be displayed with "Group: " during output
        list<Student> members;///the assigned students for this study group
        list<Student>::iterator sitr;
};

#endif // STUDYGROUP_H
