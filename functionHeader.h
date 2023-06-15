#include <string>
#include "date.h"
using namespace std;

struct appointment
{
    date::year_month_day ymd;
    string time;
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
    int n;
    int size;
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


