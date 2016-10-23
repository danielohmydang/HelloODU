#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <list>
#include <string>
#include <iostream>
#include <array>
#include "Homework.h"
#include "Student.h"
#include "StudyGroup.h"

using namespace std;

class Instructor
{
    public:
        Instructor();
        Instructor(string lastName)
        {
            name = lastName;
        }
        ~Instructor();
        void assignStudyGroup(list<Student> students){
            ///Takes in a list of students at the beginning of the year and splits them up into study groups
            list<Student>::iterator sitr = students.begin();
            int pop = students.size();
            int scount = 0;
            double groupcount = pop;

            list<StudyGroup>::iterator gitr;
            cout<<"Assigning " << pop << " to Study Groups" << endl;

            if (pop <= 6){groupcount = 1;}
            else if ((groupcount / 6) < (pop % 6)){groupcount -= (pop%6); groupcount /= 6; groupcount++;}
            else{groupcount -= (pop%6); groupcount /= 6;}
            cout<< "groupcount = "<<groupcount<<endl;

            char letter = 'A';
            for (int x = 0; x < groupcount; x++)
            {

                groups.push_back(StudyGroup(letter, name));
                ///cout<<"Group " << letter << " Created"<< endl;
                letter++;
            }
            while (sitr != students.end())
            {
                for (gitr = groups.begin(); gitr != groups.end(); gitr++)
                {
                    if (sitr != students.end())
                    {
                        gitr->addstudent(*sitr);
                        ///cout << sitr->getname() << " added to group " << gitr->getname() << endl;
                        sitr++;
                    }
                }
            }
        }
        void assignHomework(){
            ///Create Homework assignments which each student will request

        }

        string getname(){
            return name;
        }

        void listgroups(){
            cout<<name<<endl;
            for(gitr = groups.begin();gitr!= groups.end(); gitr++){
                cout << gitr->getname() << " ";
            }
        }

        void liststudents(){
            cout<<name<<endl;
            for(gitr = groups.begin();gitr!= groups.end(); gitr++){
                gitr->liststudents();
            }
        }

        void findstudent(Student stu, bool& found, list<Student>::iterator& pitr)
        {
            for(gitr = groups.begin();gitr!= groups.end(); gitr++){
                gitr->findstudent(stu, found, pitr);
            }
            if (found){cout << "Class - " << this->name << endl;}
        }

        void listlevels(Student stu, bool& found, list<string>& levels)
        {
            for(gitr = groups.begin();gitr!= groups.end(); gitr++){
                gitr->listlevels(stu, found, levels);
            }
            if (found){levels.push_back("Class" + name);}

        }


    private:
        string name;///Just last name, Prof. will be added in output.
        list<Homework> assignments;///List of all created Homework assignments. list is kept till end of semester for reference
        list<StudyGroup> groups;///List of all created study groups for this instructor in this subject
        list<Homework>::iterator hitr;
        list<StudyGroup>::iterator gitr;

};

#endif // INSTRUCTOR_H
