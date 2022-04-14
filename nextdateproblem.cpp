#include <iostream>
#include <fstream>
using namespace std;

bool leapyear(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}

int main() {
    int day, month, year = 0;

	//cout << "Enter today's date in the format:DD MM YYYY\n";
    //cin >> day >> month >> year;

    ifstream fin("dates.txt");

    while (fin >> day >> month >> year) {

        if (day > 0 && day < 28)	//checking for day from 0 to 27
            day += 1;

        if (day == 28) {
            if (month == 2) {	//checking for February
                if (leapyear(year)) {  //leap year check in case of February
                    day = 29;
                    cout << "is a leap year" << endl;
                } else {
                    day = 1;
                    month = 3;
                }
            } else	//when it's not February
                day += 1;
        }
        if ((day == 29) && (!leapyear(year))) {	//last day check for February
            if (month == 2) {
                day = 1;
                month = 3;
            } else
                day += 1;
        }
        if (day == 30) {	//last day check for April, June, September, or November
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                day += 1;
            else {
                day = 1;
                month += 1;
            }
        }
        if (day == 31) {	//last day of the month
            day = 1;
            if (month == 12) {	//checking for last day of the year
                year += 1;
                month = 1;
            }
            else
                month += 1;
        }

        cout << "Tomorrow's date:\n";
        if (day < 10) {	//checking if day needs to be preceded by 0
            cout << "0" << day << " ";
        }
        else
            cout << day << " ";
        if (month < 10) {	//checking if month needs to be preceded by 0
            cout << "0" << month << " ";
        }
        else
            cout << month << " ";

        cout << year << endl;
    }
	return 0;
}
