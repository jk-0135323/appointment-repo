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
    appointmentNode *next;
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
    appointment record[2];
    student *next;
};

int chooseIdentity(); // done

int chooseLecturer(lecturer *arr);       // done
void chooseStudent(student *&navigator); // done

int showMenu(); // done

int setAppointment(appointmentNode *&node);                          // done
void addAppointment(appointmentNode *&head, appointmentNode *&node); // done
void lecturerCancel(lecturer lect, student *head);
void lecturerView(lecturer lect);

void bookAppointment(student *&student, lecturer *arr);
void studentCancel(student *&student, lecturer *arr);
void studentView(student *&student); // james

int compareAppointment(appointment a, appointment b);       // done
void merge(appointment arr[], int front, int mid, int end); // done
void mergeSort(appointment arr[], int front, int end);      // done

int operation, i, identity = 0;
char logout, changeIdentity = 'y';

lecturer lectArr[3] = {{"Ms bridget"}, {"Mr Khoo"}, {"Ms.Hema"}};
student *studentHead = new student{"james", 0, 1};

lecturer currentLect;
student *currentStudent = studentHead;

int main()
{
    studentHead->next = new student{"Balpreet", 0, 1};
    studentHead->next->next = new student{"Daniel", 0, 1};
    // populate each index with a dummy node
    for (int dumb = 0; dumb < 5; dumb++)
    {
        lectArr[0].appointmentList[dumb] = new appointmentNode;
        lectArr[1].appointmentList[dumb] = new appointmentNode;
        lectArr[2].appointmentList[dumb] = new appointmentNode;
    }

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
                    int day = setAppointment(newAppointment);
                    addAppointment(currentLect.appointmentList[day], newAppointment);
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
            currentStudent = studentHead;
            chooseStudent(currentStudent); // identify which student
            while (logout == 'y' || logout == 'Y')
            {
                operation = showMenu(); // identify operation, make or cancel or view appointment
                switch (operation)
                {
                case 1:
                {
                    cout << "student chose to make appointment";
                    bookAppointment(currentStudent, lectArr);
                    break;
                }
                case 2:
                {
                    cout << "student chose to cancel appointment";
                    studentCancel(currentStudent, lectArr);
                    break;
                }
                case 3:
                {
                    cout << "student chose view appointment";
                    mergeSort(currentStudent->record, 0, 1);
                    studentView(currentStudent);
                    break;
                }
                default:
                    cout << "Invalid operation";
                    break;
                }

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

void chooseStudent(student *&navigator)
{
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
    for (int i = 1; i < input; i++)
    {
        navigator = navigator->next;
    }
}

int setAppointment(appointmentNode *&node)
{
    chrono::system_clock::time_point currentTime = chrono::system_clock::now();
    date::year_month_day today = date::year_month_day{date::floor<date::days>(currentTime)};
    date::year_month_day ymd;
    while (true) // setting date
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

            if (date::weekday(ymd).iso_encoding() != 6 && date::weekday(ymd).iso_encoding() != 7)
            {
                node->app.ymd = ymd;
                break;
            }
            else
            {
                cout << "but its a weekend" << endl;
            }
        }
        else
        {
            cout << "try again" << endl;
        }
    }

    int hour = 0, minute = 0;

    while (true) // setting time
    {

        cout << "Input hour (0-23)";
        cin >> hour;
        cout << "Input minutes (0-59)";
        cin >> minute;
        if (hour < 0 || hour > 23)
        {
            cout << "try again"<<endl;
            continue;
        }

        if (minute < 0 || minute > 59)
        {
            cout << "try again"<<endl;
            continue;
        }
        time_t now_t = chrono::system_clock::to_time_t(currentTime);
        tm *desiredTime_tm = localtime(&now_t);
        ;
        desiredTime_tm->tm_hour = hour;
        desiredTime_tm->tm_min = minute;
        desiredTime_tm->tm_sec = 0;
        time_t desiredTime_t = mktime(desiredTime_tm);
        chrono::system_clock::time_point desiredTimePoint = chrono::system_clock::from_time_t(desiredTime_t);
        if ((node->app.ymd == today) && currentTime > desiredTimePoint)
        {
            cout << "Cannot time travel backwards" << endl;
            continue;
        }
        else
        {
            node->app.time = desiredTime_t;
            node->app.status = "Available";
            return date::weekday(ymd).iso_encoding() - 1;
        }
        break;
    }
}

void addAppointment(appointmentNode *&head, appointmentNode *&node)
{
    appointmentNode *navigator = head;
    if (navigator->next == nullptr)
    {
        navigator->next = node;
    }
    else
    {
        while (navigator->next != nullptr)
        {
            if (node->app.ymd > navigator->next->app.ymd) // if date is bigger than next node, move to the next node
            {
                navigator = navigator->next;
            }
            else if (node->app.ymd < navigator->next->app.ymd) // if date is smaller than next node, put infront of that node
            {
                node->next = navigator->next;
                navigator->next = node;
                break;
            }
            else // the date is same, compare the time in this case
            {
                chrono::system_clock::time_point nodeTime = chrono::system_clock::from_time_t(node->app.time);
                chrono::system_clock::time_point navigatorNextTime = chrono::system_clock::from_time_t(navigator->next->app.time);

                if (nodeTime > navigatorNextTime) // if the time is later than next node, move the navigator
                {
                    navigator = navigator->next;
                }
                else if (nodeTime < navigatorNextTime) // if time is sooner than next node, put infront of it
                {
                    node->next = navigator->next;
                    navigator->next = node;
                    break;
                }
                else // clash timing, inform user to make a choice
                {
                    cout << "You have another appointment with the same date and time, would you like to add this appointment anyway? (y/n)" << endl;
                    char c;
                    cin >> c;
                    if (c == 'y' || c == 'Y')
                    {
                        node->next = navigator->next;
                        navigator->next = node;
                        break;
                    }
                    else
                    {
                        cout << "no appointment is added" << endl;
                    }
                }
            }
        }
    }
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

void bookAppointment(student *&student, lecturer *arr)
{
    cout << "select lecturer, choose day(mon-fri), update student name into lecturer linked list, make a copy in students array" << endl
         << "sort the array base on date and time" << endl;
}

void studentCancel(student *&student, lecturer *arr)
{
    cout << "loop through student array, identify date, time and name of lecturer" << endl
         << "on the student side,change status into cancelled, on lecturer side, change status into available" << endl;
}

void studentView(student *&student)
{
    char buffer[6];
    
    cout << "Name \t Date \t \t Time \t Status" << endl;
    for (int i = 0; i < student->n; i++)
    {
        strftime(buffer, sizeof(buffer), "%H:%M", localtime(&student->record[i].time));
        cout << student->record[i].name << "\t " << student->record[i].ymd << " \t "
             << buffer << " \t " << student->record[i].status << endl;
    }
}

int compareAppointment(appointment a, appointment b)
{
    if (a.ymd == b.ymd)
    {
        cout << "same date" << endl;
        chrono::system_clock::time_point timePointA = chrono::system_clock::from_time_t(a.time);
        chrono::system_clock::time_point timePointB = chrono::system_clock::from_time_t(b.time);

        if (timePointA == timePointB)
        {
            cout << "found match, returned 0" << endl;
            return 0;
        }
        else if (timePointA > timePointB)
        {
            cout << "time a bigger than time b, returned -1" << endl;
            return -1;
        }
        else
        {
            cout << "time b bigger than time a, return -2" << endl;
            return -2;
        }
    }
    else if (a.ymd > b.ymd)
    {
        cout << "a bigger than b, returned 2" << endl;
        return 2;
    }
    else if (a.ymd < b.ymd)
    {
        cout << "a smaller than b, return 3" << endl;
        return 3;
    }
}

void merge(appointment arr[], int front, int mid, int end)
{
    int firstHalf = mid - front + 1;
    int secondHalf = end - mid;
    int i, j, k;

    appointment tempArr[firstHalf], tempArr2[secondHalf];

    for (i = 0; i < firstHalf; i++)
        tempArr[0] = arr[front + i];

    for (j = 0; j < secondHalf; j++)
        tempArr2[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = 0;

    while (i < firstHalf && j < secondHalf)
    {
        if (compareAppointment(tempArr[i], tempArr2[j]) == 3 || compareAppointment(tempArr[i], tempArr2[j]) == -2)
        {
            arr[k] = tempArr[i];
            i++;
        }
        else
        {
            arr[k] = tempArr2[j];
            j++;
        }
        k++;
    }

    while (i < firstHalf)
    {
        arr[k] = tempArr[i];
        i++;
        k++;
    }

    while (j < secondHalf)
    {
        arr[k] = tempArr2[j];
        j++;
        k++;
    }
}

void mergeSort(appointment arr[], int front, int end)
{
    if (front < end)
    {
        int m = (front + end) / 2;
        mergeSort(arr, front, m);
        mergeSort(arr, m + 1, end);
        merge(arr, front, m, end);
    }
}