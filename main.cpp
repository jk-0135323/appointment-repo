#include <iostream>
#include <string>
#include "functionHeader.h"

using namespace std;

int operation, index, identity;
char logout, changeIdentity;

lecturer lectArr[3] = {{"Ms bridget"}, {"Mr Khoo"}, {"Ms.Hema"}};
student *studentHead = new student{"james", 0, 1};

lecturer currentLect;
student *currentStudent = studentHead;

int main()
{
    studentHead->next = new student{"Balpreet", 0, 1};
    studentHead->next->next = new student{"Daniel", 0, 1};

    while (true)
    {

        identity = chooseIdentity(); // identify lecturer or student

        switch (identity)
        {
        case 1:
            index = chooseLecturer(lectArr); // identify which lecturer
            currentLect = lectArr[index];
            while (logout == 'y' || logout == 'Y')
            {
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
                    cout << "Invalid operation";
                }
                break;
                cout << "continue as " << currentLect.name << "? (y/n)" << endl;
                cin >> logout;
            }
            break;
        case 2:
            logout = 'y';
            chooseStudent(studentHead, currentStudent); // identify which student
            while (logout == 'y' || logout == 'Y')
            {
                operation = showMenu(); // identify operation, make or cancel or view appointment
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
                    cout << "Invalid operation";
                }
                break;
                cout << "continue as " << currentStudent->name << "? (y/n)" << endl;
                cin >> logout;
            }
            break;
        default:
            cout << "invalid identity" << endl;
            break;
        }
    }
}