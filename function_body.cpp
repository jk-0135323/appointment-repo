#include <iostream>
#include <chrono>
#include <ctime>
#include "date.h"
using namespace std;
#include "functionHeader.h"

int chooseIdentity()
{
    cout << " 1 for lect, 2 for student and validate input" << endl;
    
}

int showMenu()
{
    cout << "show menu, 1 for make appointment, 2 for cancel, 3 for view" << endl;
    
}

int chooseLecturer(lecturer *arr)
{
    cout << "display list of lecturer(1-3) and return the chosen one ";
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

void lecturerCancel(lecturer lect)
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
