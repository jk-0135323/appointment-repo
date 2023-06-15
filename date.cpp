#include <iostream>
#include "date.h"

using namespace std;
int main()
{

    while (true)
    {
        int y, m, d;
        std::cout << "Enter year: ";
        std::cin >> y;
        std::cout << "Enter month: ";
        std::cin >> m;
        std::cout << "Enter day: ";
        std::cin >> d;
        date::year_month_day ymd = date::year(y) / date::month(m) / date::day(d);
        cout << ymd << endl;
        if (ymd.ok())
        {
            cout << "date is valid" << endl;

            if (date::weekday{date::year(y) / date::month(m) / date::day(d)} == date::weekday{4})
            {
                cout << "thursday";
            }

            break;
        }
        else
        {
            cout << "try again" << endl;
        }
    }
    return 0;
}
