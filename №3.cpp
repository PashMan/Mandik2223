#include <iostream>
using namespace std;

enum class Month {
    January, February, March, April, May, June,
    July, August, September, October, November, December
};

class Date {
private:
    int year;
    Month month;
    int day;

public:
    Date(int year, Month month, int day)
        : year(year), month(month), day(day) {}

    void printDate() {
        cout << year << "-" << static_cast<int>(month) + 1 << "-" << day << endl;
    }

    Date operator+(int days) {
        int totalDays = day + days;
        int daysInMonth = getDaysInMonth();
        int newYear = year;
        Month newMonth = month;
        int newDay = totalDays;

        while (newDay > daysInMonth) {
            newDay -= daysInMonth;
            newMonth = static_cast<Month>(static_cast<int>(newMonth) + 1);
            if (newMonth == Month::January) {
                newYear++;
            }
            daysInMonth = getDaysInMonth();
        }

        return Date(newYear, newMonth, newDay);
    }

    Date operator++() {
        return *this + 1;
    }

    Date operator--() {
        return *this - 1;
    }

    Date operator-(int days) {
        int totalDays = day - days;
        int daysInMonth = getDaysInMonth();
        int newYear = year;
        Month newMonth = month;
        int newDay = totalDays;

        while (newDay <= 0) {
            newMonth = static_cast<Month>(static_cast<int>(newMonth) - 1);
            if (newMonth == Month::December) {
                newYear--;
            }
            daysInMonth = getDaysInMonth();
            newDay += daysInMonth;
        }

        return Date(newYear, newMonth, newDay);
    }

private:
    int getDaysInMonth() {
        switch (month) {
        case Month::January:
        case Month::March:
        case Month::May:
        case Month::July:
        case Month::August:
        case Month::October:
        case Month::December:
            return 31;
        case Month::April:
        case Month::June:
        case Month::September:
        case Month::November:
            return 30;
        case Month::February:
            if (isLeapYear()) {
                return 29;
            }
            else {
                return 28;
            }
        }
        return 0;
    }

    bool isLeapYear() {
        if (year % 4 != 0) {
            return false;
        }
        else if (year % 100 != 0) {
            return true;
        }
        else if (year % 400 != 0) {
            return false;
        }
        return true;
    }
};

int main() {
    Date date(2023, Month::May, 30);
    date.printDate();

    Date nextDate = ++date;
    nextDate.printDate();

    Date previousDate = --date;
    previousDate.printDate(); 

    Date futureDate = date + 10;
    futureDate.printDate();

    return 0;
}
