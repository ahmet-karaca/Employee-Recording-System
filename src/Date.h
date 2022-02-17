//
// Created by lenovo on 2.12.2021.
//

#ifndef ASSIGNMENT2_DATE_H
#define ASSIGNMENT2_DATE_H


#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int,int,int);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    int operator<(const Date& second) const;

    friend ostream& operator<<(ostream& os, const Date& dt);
};


#endif //ASSIGNMENT2_DATE_H
