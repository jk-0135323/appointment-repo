#include <iostream>
using namespace std;


int chooseIdentity(){
    cout<<" 1 for lect, 2 for student and validate input"<<endl;
    int role;
    cin>>role;
    return role;
}

/*bool login(lectArr lecturerArray, student* studentList) {
    cout<<"get role, input id, password"<<endl<<
    "if lecturer, return true, else return false"
    string username, password;
    int role, id;

    while (true) {
        cout << "Enter role (1 for lecturer, 2 for student): ";
        cin >> role;

        if (role == 1 || role == 2) {
            break;
        }

        cout << "Invalid role. Please enter 1 for lecturer or 2 for student." << endl;
    }

    while (true) {
        cout << "Enter id: ";
        cin >> id;

        if (id > 0) {
            break;
        }

        cout << "Invalid id. Please enter a positive integer." << endl;
    }

    cout << "Enter password: ";
    cin >> password;

    if (role == 1) {
        for (int i = 0; i < 1; ++i) {
            if (lecturerArray[i].id == id && lecturerArray[i].password == password) {
                cout << "Welcome, " << lecturerArray[i].name << endl;
                return true;
            }
        }
    } else if (role == 2) {
        StudentNode* navigator = studentList;
        while (navigator != NULL) {
            if (navigator->id == id && navigator->password == password) {
                cout << "Welcome, " << navigator->name << endl;
                return false;
            }
            navigator = navigator->next;
        }
    }

    return false;*/


int showLecturerMenu(){
    cout<<"show menu, 1 for make appointment, 2 for cancel, 3 for view"<< endl;
    return 8;
}

void makeAppointment(){
    cout<<"input year, month, day, time"<<endl<<
    "check the day, add to linked list of the day, by comparing date and tim"<<endl;

}

int lectLogin(){
    cout<<"get id, get password, if match, return the index of lectArray"<<endl
    <<"else return 10"<<endl;
    return 1;
}

int studentLogin(){
    cout<<"current student act as navigator, using while loop, if got match, return 1"<<endl
    <<"else, move current student back to head, and return 10"<<endl;
    return 1;
    
}

void lecturerCancelAppointment(){
    cout << "Prompt the lecturer to choose a day to view the appointments they made." << endl
     << "Prompt the lecturer to choose an appointment from the chosen day to cancel." << endl
     << "Based on the chosen appointment, check if it has been booked by a student." << endl
     << "If appointment is booked, change status of the appointment to 'Cancelled' in  student's record array and delete the appointment from lecturer." << endl;
}

int showStudentMenu(){
    cout << "display operations for student such as book appointment, cancel appointment and view personal record" <<endl;

return 9;
}