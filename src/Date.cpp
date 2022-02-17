//
// Created by lenovo on 2.12.2021.
//

#include "Date.h"

Date::Date(int Day, int Month, int Year) {
    day = Day;
    month = Month;
    year = Year;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

int Date::operator<(const Date& second) const{
    if(year < second.year){
        return 1;
    }
    if(year == second.year && month < second.month){
        return 1;
    }
    if(year == second.year && month == second.month && day < second.day){
        return 1;
    }
    return 0;
}

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.day << '-' << dt.month << "-" << dt.year;
    return os;
}