#include <iostream>
#include <string>
#include "date.h"
#include <chrono>
#include <ctime>

using namespace std;

struct appointment
{
    date::year_month_day ymd;
    time_t time;
    string name;
    string status;
};

struct appointmentNode
{
    appointment app;
    appointment *next;
};

struct lecturer
{
    string name;
    appointment *appointmentList[5];
};

struct student
{
    string name;
    int n;// # of appointment
    int size; //#size of array
    appointment record[1];
    student *next;
};

int chooseIdentity();

int chooseLecturer(lecturer *arr);
void chooseStudent(student *head, student *navigator);

int showMenu();

void addAppointment(lecturer lect);
void lecturerCancel(lecturer lect, student *student);
void lecturerView(lecturer lect);

void bookAppointment(student *student, lecturer *arr);
void studentCancel(student *student, lecturer *arr);
void studentView(student* student);

int operation, i ,identity = 0;
char logout, changeIdentity = 'y';

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
            i = chooseLecturer(lectArr); // identify which lecturer
            currentLect = lectArr[i];
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


int chooseIdentity()
{
    int i;
    cout <<"1. Lecturer"<<endl<<"2. Student"<<endl;
    try
    {
        cin>>i;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return i;
}

int showMenu()
{
    int i;
    cout <<"Select Operation/n 1. Add Appointment slot/n 2.Cancel Appointment/n 3.View Appointment"<<endl;
    try
    {
        cin>>i;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return i;
    
}

int chooseLecturer(lecturer *arr)
{
    int i;
    cout <<"Select identity \n1. Ms Bridget \n2. Mr.Khoo\n3. Ms.Hema"<<endl;;
    try
    {
        cin>>i;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return i;
    
}

void chooseStudent(student *head, student *navigator)
{
    cout << "move the navigator to the selected student" << endl;
}

void addAppointment(lecturer lect)
{
    cout << "start a while loop, input year, month, day, time" << endl
         << "check the day, add to linked list of the day, by comparing date and time, break loop if wish to stop making" << endl;
}

void lecturerCancel(lecturer lect, student *student)
{
    cout << "Prompt the lecturer to choose a day to view the appointments they made." << endl
         << "Prompt the lecturer to choose an appointment from the chosen day to cancel." << endl
         << "Based on the chosen appointment, check if it has been booked by a student." << endl
         << "If appointment is booked, change status of the appointment to 'Cancelled' in  student's record array and delete the appointment from lecturer." << endl;
}

void lecturerView(lecturer lect)
{
    cout << "choose a day, (mon to fri), then loop through linked list of the day";
}

void bookAppointment(student *student, lecturer *arr)
{
    cout << "select lecturer, choose day(mon-fri), update student name into lecturer linked list, make a copy in students array" << endl
         << "sort the array base on date and time" << endl;
}

void studentCancel(student *student, lecturer *arr)
{
    cout << "loop through student array, identify date, time and name of lecturer" << endl
         << "on the student side,change status into cancelled, on lecturer side, change status into available" << endl;
}

void studentView(student* student)
{
    cout << "loop to display all appointment" << endl;
}
