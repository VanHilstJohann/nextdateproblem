#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool leapyear(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}

void testdate(int day, int month, int year) {

    if (day < 0 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2025)
        cout << day << " " << month << " " << year << " " << "is an invalid date." << endl;
    else if (month == 2 && day > 28 && !leapyear(year))
        cout << day << " " << month << " " << year << " " << "is an invalid date." << endl;
    else if (month == 2 && day > 29 && leapyear(year))
        cout << day << " " << month << " " << year << " " << "is an invalid date." << endl;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        cout << day << " " << month << " " << year << " " << "is an invalid date." << endl;
    else {
        cout << "The date after " << day << " " << month << " " << year << " is:" << endl;
        if (day > 0 && day < 28)	//checking for day from 0 to 27
                day += 1;

        else if (day == 28) {
            if (month == 2) {	//checking for February
                if (leapyear(year)) {  //leap year check in case of February
                    day = 29;
                } else {
                    day = 1;
                    month = 3;
                }
            } else	//when it's not February
                day += 1;
        }
        else if ((day == 29) && (!leapyear(year))) {	//last day check for February
            if (month == 2) {
                day = 1;
                month = 3;
            } else
                day += 1;
        }
        else if (day == 30) {	//last day check for April, June, September, or November
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                day += 1;
            else {
                day = 1;
                month += 1;
            }
        }
         else if (day == 31) {	//last day of the month
            day = 1;
            if (month == 12) {	//checking for last day of the year
                year += 1;
                month = 1;
            }
            else
                month += 1;
        }


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
}

ifstream getFile() {
    string fileName;
    cout << "Enter the filename: " << endl;
    cin >> fileName;
    ifstream file(fileName);
    if (file.fail()) {
        cout << "File " << fileName << " not found." << endl;
        file.close();
    }
    else
        return file;
}

int main() {
    int day, month, year = 0;
    string entry;
    bool status = true;

    while (status) {
        cout << "Enter 't' to type in a test case, or 'f' to read from a file, or 'q' to quit: " << endl;
        cin >> entry;
        if (entry == "t") {
            cout << "Enter the test date in the format: DD MM YYYY" << endl;
            cin >> day >> month >> year;
            cout << endl;
            testdate(day, month, year);
        }
        else if (entry == "f") {
            ifstream fin(getFile());
            while (fin >> day >> month >> year) {
                testdate(day, month, year);
            }
        }
        else if (entry == "q") {
            cout << "Goodbye." << endl;
            status = false;
        }
    }
	return 0;
}
