#ifndef HOMEWORK_H
#define HOMEWORK_H
#include <string>
using namespace std;

class Homework
{
    public:
        Homework();
        Homework(string due, string work)
        {
            dueDate = due;
            description = work;
        }
        virtual ~Homework();

    private:
        string dueDate;
        string description;
};

#endif // HOMEWORK_H
