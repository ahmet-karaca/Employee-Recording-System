//
// Created by lenovo on 2.12.2021.
//

#include "TemporaryEmployee.h"

TemporaryEmployee::TemporaryEmployee(int employeeNumber, int employeeType, const string &employeeName,
                                     const string &employeeSurname, const string &employeeTitle,
                                     double employeeSalaryCoefficient, const Date &employeeBirthDate,
                                     const Date &employeeAppointmentDate, int employeeLengthofService) : Employee(
        employeeNumber, employeeType, employeeName, employeeSurname, employeeTitle, employeeSalaryCoefficient,
        employeeBirthDate, employeeAppointmentDate, employeeLengthofService) {}