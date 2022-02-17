//
// Created by lenovo on 2.12.2021.
//

#include "Employee.h"

Employee::Employee(int employeeNumber,int employeeType, const string &employeeName,
                   const string &employeeSurname, const string &employeeTitle, double employeeSalaryCoefficient,
                   const Date &employeeBirthDate, const Date &employeeAppointmentDate,int employeeLengthofService) : employeeNumber(
        employeeNumber), employeeType(employeeType), employeeName(employeeName), employeeSurname(employeeSurname),
                                                                                                                     employeeTitle(
                                                                                                                             employeeTitle),
                                                                                                                     employeeSalaryCoefficient(
                                                                                                                             employeeSalaryCoefficient),
                                                                                                                     employeeBirthDate(
                                                                                                                             employeeBirthDate),
                                                                                                                     employeeAppointmentDate(
                                                                                                                             employeeAppointmentDate),
                                                                                                                     employeeLengthofService(
                                                                                                                             employeeLengthofService) {}


int Employee::getEmployeeNumber() const {
    return employeeNumber;
}

int Employee::getEmployeeType() const {
    return employeeType;
}

const string &Employee::getEmployeeName() const {
    return employeeName;
}

const string &Employee::getEmployeeSurname() const {
    return employeeSurname;
}

const string &Employee::getEmployeeTitle() const {
    return employeeTitle;
}

void Employee::setEmployeeTitle(const string &employeeTitle) {
    Employee::employeeTitle = employeeTitle;
}

double Employee::getEmployeeSalaryCoefficient() const {
    return employeeSalaryCoefficient;
}

void Employee::setEmployeeSalaryCoefficient(double employeeSalaryCoefficient) {
    Employee::employeeSalaryCoefficient = employeeSalaryCoefficient;
}

const Date &Employee::getEmployeeBirthDate() const {
    return employeeBirthDate;
}

const Date &Employee::getEmployeeAppointmentDate() const {
    return employeeAppointmentDate;
}

int Employee::getEmployeeLengthofService() const {
    return employeeLengthofService;
}


ostream& operator<<(ostream& os, const Employee& employee)
{
    string employeeTypeStr;
    if (employee.getEmployeeType() == 0){
        employeeTypeStr = "Temporary";
    }
    if (employee.getEmployeeType() == 1){
        employeeTypeStr = "Permanent";
    }
    os << "__Employee Information__\n" << "Employee Number:" << employee.getEmployeeNumber() << "\n" << "Employee Type:" << employeeTypeStr << "\n" << "Employee Name and Surname:" << employee.getEmployeeName() << " " << employee.getEmployeeSurname() << "\n" << "Employee Title:" <<  employee.getEmployeeTitle() << "\n" << "Employee Salary Coefficient Number:" << employee.getEmployeeSalaryCoefficient() << "\n" << "Employee Date Of Birth:" << employee.getEmployeeBirthDate() << "\n" << "Employee Date of Appointment To The Institution:" << employee.getEmployeeAppointmentDate() << "\n" << "Employee Length Of Service In Other Institutions:" << employee.getEmployeeLengthofService()<< "\n";
    return os;
}