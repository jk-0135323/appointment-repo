#include <iostream>
#include <string>

#include "functionHeader.h"
#include <chrono>

using namespace std;

int operation, index;
int identity;

lecturer lectArr[3] = {{"Ms bridget"}, {"Mr Khoo"}, {"Ms.Hema"}};
student *studentHead = new student{"james", 0, 1};

lecturer currentLect;
student *currentStudent = studentHead;

int main()
{
    while (true)
    {

        identity = chooseIdentity(); // identify lecturer or student

        switch (identity)
        {
        case 1:
            index = chooseLecturer(lectArr); // identify which lecturer
            currentLect = lectArr[index];
            operation = showMenu(); // identify operation, make or cancel or view appointment
            switch (operation)
            {
            case 1:
                cout << "lecturer chose to make appointment";
                addAppointment(currentLect);
                break;
            case 2:
                cout << "lecturer chose to cancel appointment";
                lecturerCancel(currentLect, studentHead);
                break;
            case 3:
                cout << "lecturer chose to view";
                lecturerView(currentLect);
                break;
            default:
                cout << "Invalid choice";
            }
            break;
        case 2:
            chooseStudent(studentHead, currentStudent); // identify which student
            operation = showMenu();                     // identify operation, make or cancel or view appointment
            switch (operation)
            {
            case 1:
                cout << "student chose to make appointment";
                bookAppointment(currentStudent, lectArr);
                break;
            case 2:
                cout << "student chose to cancel appointment";
                studentCancel(currentStudent, lectArr);
                break;
            case 3:
                cout << "student chose view appointment";
                studentView(currentStudent);
                break;
            default:
                cout << "Invalid choice";
            }
            break;

            break;
        default:

            break;
        }
    }
}