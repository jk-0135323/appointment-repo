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
    appointmentNode *appointmentList[5];
};

struct student
{
    string name;
    int n;    // # of appointment
    int size; // #size of array
    appointment record[1];
    student *next;
};

int chooseIdentity();

int chooseLecturer(lecturer *arr);
void chooseStudent(student *head, student *navigator);

int showMenu();

void setAppointment(appointmentNode *node);
void addAppointment(lecturer lect, appointmentNode *node);
void lecturerCancel(lecturer lect, student *head);
void lecturerView(lecturer lect);

void bookAppointment(student *student, lecturer *arr);
void studentCancel(student *student, lecturer *arr);
void studentView(student *student);

int compareAppointment(appointment a, appointment b);

int operation, i, identity = 0;
char logout , changeIdentity = 'y';

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
        {
            i = chooseLecturer(lectArr); // identify which lecturer
            currentLect = lectArr[i];
            logout = 'y';
            while (logout == 'y' || logout == 'Y')
            {
                operation = showMenu(); // identify operation, make or cancel or view appointment
                switch (operation)
                {
                case 1:
                {
                    cout << "lecturer chose to make appointment\n";
                    appointmentNode *newAppointment = new appointmentNode;
                    setAppointment(newAppointment);
                    addAppointment(currentLect, newAppointment);
                }
                break;
                case 2:
                {
                    cout << "lecturer chose to cancel appointment";
                    lecturerCancel(currentLect, studentHead);
                }
                break;
                case 3:
                {
                    cout << "lecturer chose to view";
                    lecturerView(currentLect);
                    break;
                }
                default:
                    cout << "Invalid operation";
                }

                cout << "continue as " << currentLect.name << "? (y/n)" << endl;
                cin >> logout;
            }
        }
        break;
        case 2:
        {
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
    cout << "1. Lecturer" << endl
         << "2. Student" << endl;
    try
    {
        cin >> i;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return i;
}

int showMenu()
{
    int i;
    cout << "Select Operation\n1. Add Appointment slot\n2. Cancel Appointment\n3. View Appointment" << endl;
    try
    {
        cin >> i;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return i;
}

int chooseLecturer(lecturer *arr)
{
    int i;
    cout << "Select identity \n1. Ms Bridget \n2. Mr.Khoo\n3. Ms.Hema" << endl;
    ;
    try
    {
        cin >> i;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return i - 1;
}

void chooseStudent(student *head, student *navigator)
{
    navigator = head;
    int input;
    cout << "Select identity \n1. James \n2. Balpreet\n3. Daniel" << endl;
    try
    {
        cin >> input;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < input; i++)
    {
        navigator = navigator->next;
    }
}

void setAppointment(appointmentNode *node)
{
    chrono::system_clock::time_point currentTime = chrono::system_clock::now();
    date::year_month_day today = date::year_month_day{date::floor<date::days>(currentTime)};
    date::year_month_day ymd;
    while (true)//setting date
    {
        int y, m, d;
        cout << "Enter year(YYYY): ";
        cin >> y;
        cout << "Enter month(MM): ";
        cin >> m;
        cout << "Enter day(DD): ";
        cin >> d;
        ymd = date::year(y) / date::month(m) / date::day(d);
        cout << ymd << endl;
        if (ymd.ok())
        {
            cout << "date is valid" << endl;

            if (static_cast<unsigned>(ymd.day()) != 6 && static_cast<unsigned>(ymd.day()) != 7)
            {
                cout<<date::weekday(ymd).iso_encoding()<<endl;
                node->app.ymd = ymd;
            }

            break;
        }
        else
        {
            cout << "try again" << endl;
        }
    }


    int hour =0, minute = 0;

    while(true)//setting time
    {
        
        cout<<"Input hour (0-23)";
        cin>>hour;
        cout<<"Input minutes (0-59)";
        cin>>minute;
        if (hour < 0 || hour > 23)
        {
            cout<<"try again";
            continue;
        }

        if (minute < 0 || minute > 59)
        {
            cout<<"try again";
                continue;
        }
        time_t now_t = chrono::system_clock::to_time_t(currentTime);
        tm* desiredTime_tm = localtime(&now_t);;
        desiredTime_tm->tm_hour = hour;
        desiredTime_tm->tm_min = minute;
        desiredTime_tm->tm_sec = 0;
        time_t desiredTime_t = mktime(desiredTime_tm);
        chrono::system_clock::time_point desiredTimePoint = chrono::system_clock::from_time_t(desiredTime_t);
        if ((node->app.ymd == today) && currentTime > desiredTimePoint) 
        {
            cout<<"Cannot time travel backwards"<<endl;
            continue;
        } else 
        {
            node->app.time = desiredTime_t;
        }
        break;
    }
    

}


void addAppointment(lecturer lect, appointmentNode *node)
{
    cout << "check the day, add accordingly";
}

void lecturerCancel(lecturer lect, student *head)
{
    cout << "Prompt the lecturer to choose a day to view the appointments they made." << endl
         << "Prompt the lecturer to choose an appointment from the chosen day to cancel." << endl
         << "Based on the chosen appointment, check if it has been booked by a student." << endl
         << "If appointment is booked, using compareAppointment() to find a match, change status of the appointment to 'Cancelled' in  student's record array and delete the appointment from lecturer." << endl;
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

void studentView(student *student)
{
    cout << "loop to display all appointment" << endl;
}

int compareAppointment(appointment a, appointment b)
{
    cout << "compare ymd using == operator,"
         << "if not same, return 1," << endl
         << "if same, convert time_t to time_point using from_time_t() and compare, if not same, return 2, else return 0" << endl;
}