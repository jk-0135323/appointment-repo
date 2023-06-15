#include <iostream>
#include <string>
#include "date.h"
#include "functionHeader.h"
#include <chrono>

using namespace std;

int operation, index;
bool identity;


struct appointment {
    //date::year_month_day date;
    string date;
    string time;
    string name;
    date::weekday day;
    bool status;
};


struct lecturer {
    string name;
    int id;
    string password;
    appointment* appointmentList[5];
    lecturer* next;
};

struct student {
    string name;
    int id;
    string password;
    appointment record[1];
    student* next;
};


lecturer currentLect;

lecturer lectArr [1] = {"bridget", 133457,"lect123" };
student* studentHead = new student{"james", 12345, "password"};
student* currentStudent = studentHead;



int main(){


while(true){
    identity= chooseIdentity();
    if (identity == 1){
        index = lectLogin();
        if (index == 10){
            cout<<"wrong id or password"<<endl;
            continue;
        }else{
            currentLect = lectArr[index];
        }
            
        

    }
    else if(identity == 2){
        int temp;
        temp = studentLogin();
        if (temp == 10){
            cout<<"wrong id or password"<<endl;
            continue;
        }
    }

}


if (identity){
    
    operation = showLecturerMenu();
    switch (operation) {
    case 1:
        cout << "You chose to make appointment(s)";
        makeAppointment();
        break;
    case 2:
        cout << "You chose to cancel an appointment";
        lecturerCancelAppointment();
        break;
    case 3:
        cout << "You chose view appointment(s)";
        break;
    default:
        cout << "Invalid choice";
        }
    }else{
    operation = showStudentMenu();
}






}