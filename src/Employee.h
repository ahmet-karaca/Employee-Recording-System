//
// Created by lenovo on 2.12.2021.
//

#ifndef ASSIGNMENT2_EMPLOYEE_H
#define ASSIGNMENT2_EMPLOYEE_H


#include "Date.h"
#include <string>

using namespace std;

class Employee {
public:
    Employee(int employeeNumber,int employeeType, const string &employeeName,
             const string &employeeSurname, const string &employeeTitle, double employeeSalaryCoefficient,
             const Date &employeeBirthDate, const Date &employeeAppointmentDate,int employeeLengthofService);

    int getEmployeeNumber() const;

    int getEmployeeType() const;

    const string &getEmployeeName() const;

    const string &getEmployeeSurname() const;

    const string &getEmployeeTitle() const;

    void setEmployeeTitle(const string &employeeTitle);

    double getEmployeeSalaryCoefficient() const;

    void setEmployeeSalaryCoefficient(double employeeSalaryCoefficient);

    const Date &getEmployeeBirthDate() const;

    const Date &getEmployeeAppointmentDate() const;

    int getEmployeeLengthofService() const;

    friend ostream& operator<<(ostream& os, const Employee& employee);


private:
    int employeeNumber;
    int employeeType;
    string employeeName;
    string employeeSurname;
    string employeeTitle;
    double employeeSalaryCoefficient;
    Date employeeBirthDate;
    Date employeeAppointmentDate;
    int employeeLengthofService;
};


#endif //ASSIGNMENT2_EMPLOYEE_H
