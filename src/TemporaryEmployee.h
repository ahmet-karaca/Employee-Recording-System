//
// Created by lenovo on 2.12.2021.
//

#ifndef ASSIGNMENT2_TEMPORARYEMPLOYEE_H
#define ASSIGNMENT2_TEMPORARYEMPLOYEE_H


#include "Employee.h"

class TemporaryEmployee : public Employee{
public:
    TemporaryEmployee(int employeeNumber, int employeeType, const string &employeeName, const string &employeeSurname,
                      const string &employeeTitle, double employeeSalaryCoefficient, const Date &employeeBirthDate,
                      const Date &employeeAppointmentDate, int employeeLengthofService);
};


#endif //ASSIGNMENT2_TEMPORARYEMPLOYEE_H
