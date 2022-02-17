#include <iostream>
#include "DoubleDynamicLinkedList.h"
#include "CircularArrayLinkedList.h"
#include "Employee.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "Date.h"
#include "sstream"
#include <vector>
#include <algorithm>

using namespace std;

int * split(const string& text);

bool compareNumber(const Employee& e1, const Employee& e2);
bool compareDate(const Employee& e1, const Employee& e2);

int main() {

    DoubleDynamicLinkedList permEmployeeList;
    CircularArrayLinkedList tempEmployeeList;
    tempEmployeeList.arrayFiller();

    bool finisher = true;
    while (finisher){
        cout << endl;
        cout << "____ Employee Recording System ____" << endl;
        cout << "Please selecct for the following Menu Operation:" << endl;
        cout << "1) Appointment of a new employee" << endl;
        cout << "2) Appointment of a transferred employee" << endl;
        cout << "3) Updating the title and salary coefficient of an employee" << endl;
        cout << "4) Deletion of an employee" << endl;
        cout << "5) Listing the information of an employee" << endl;
        cout << "6) Listing employees ordered by employee number" << endl;
        cout << "7) Listing employees ordered by appointment date" << endl;
        cout << "8) Listing employees appointed after a certain date" << endl;
        cout << "9) Listing employees assigned in a given year" << endl;
        cout << "10) Listing employees born before a certain date" << endl;
        cout << "11) Listing employees born in particular month" << endl;
        cout << "12) Listing the information of the last assigned employee with a given title" << endl;

        int number;
        cin >> number;

        if (number == 1){
            // yeni bir employee oluşturulacak
            // bütün parametreler sirasiyla cin ile alınacak
            // date objeleri olusturulacak
            // yeni employee oldugu icin employeeLengthofService 0 kabul edilecek
            // employeeType degerine gore employee objesi oluşturulacak

            cout << "Please type the employee number" << endl;
            int employeeNumber;
            cin >> employeeNumber;

            cout << "Type the employee type" << endl;
            int employeeType;
            cin >> employeeType;

            cout << "Type the Name" << endl;
            string employeeName;
            cin >> employeeName;

            cout << "Type surname" << endl;
            string employeeSurname;
            cin >> employeeSurname;

            cout << "Type title" << endl;
            string employeeTitle;
            cin >> employeeTitle;

            cout << "Type salary coefficinet" << endl;
            double employeeSalaryCoefficient;
            cin >> employeeSalaryCoefficient;

            cout << "Type birth date" << endl;
            string employeeBirthDateString;
            cin >> employeeBirthDateString;
            int* birthDateArray=new int[3];
            birthDateArray = split(employeeBirthDateString);
            Date birthDate(birthDateArray[0], birthDateArray[1], birthDateArray[2]);

            cout << "Type appointment date" << endl;
            string employeeAppoiDateString;
            cin >> employeeAppoiDateString;
            int* appoiDateArray = new int[3];
            appoiDateArray = split(employeeAppoiDateString);
            Date appoiDate(appoiDateArray[0], appoiDateArray[1], appoiDateArray[2]);

            int employeeLengthofService = 0;

            if (employeeType == 0){
                //"TemporaryEmployee olusturuluyor"
                TemporaryEmployee e1(employeeNumber, employeeType, employeeName,employeeSurname,employeeTitle,employeeSalaryCoefficient,birthDate,appoiDate,employeeLengthofService);

                // buradan sonra olusturulan obje gerekli listeye eklenecek
                tempEmployeeList.append(&e1);
            }

            if (employeeType == 1){
                //"PermanentEmployee olusturuluyor"
                PermanentEmployee e1(employeeNumber, employeeType, employeeName,employeeSurname,employeeTitle,employeeSalaryCoefficient,birthDate,appoiDate,employeeLengthofService);

                // buradan sonra olusturulan obje gerekli listeye eklenecek
                Node *permNode = new Node(e1);
                permEmployeeList.append(permNode);
            }
        }
        if (number == 2){
            // burada length of service infosu da alınacak

            cout << "Please type the employee number" << endl;
            int employeeNumber;
            cin >> employeeNumber;

            cout << "Type the employee type" << endl;
            int employeeType;
            cin >> employeeType;

            cout << "Type the Name" << endl;
            string employeeName;
            cin >> employeeName;

            cout << "Type surname" << endl;
            string employeeSurname;
            cin >> employeeSurname;

            cout << "Type title" << endl;
            string employeeTitle;
            cin >> employeeTitle;

            cout << "Type salary coefficinet" << endl;
            double employeeSalaryCoefficient;
            cin >> employeeSalaryCoefficient;

            cout << "Type birth date" << endl;
            string employeeBirthDateString;
            cin >> employeeBirthDateString;
            int* birthDateArray=new int[3];
            birthDateArray = split(employeeBirthDateString);
            Date birthDate(birthDateArray[0], birthDateArray[1], birthDateArray[2]);

            cout << "Type appointment date" << endl;
            string employeeAppoiDateString;
            cin >> employeeAppoiDateString;
            int* appoiDateArray = new int[3];
            appoiDateArray = split(employeeAppoiDateString);
            Date appoiDate(appoiDateArray[0], appoiDateArray[1], appoiDateArray[2]);

            cout << "Type length of service days" << endl;
            int employeeLengthofService;
            cin >> employeeLengthofService;

            if (employeeType == 0){
                //"TemporaryEmployee olusturuluyor"
                TemporaryEmployee e1(employeeNumber, employeeType, employeeName,employeeSurname,employeeTitle,employeeSalaryCoefficient,birthDate,appoiDate,employeeLengthofService);

                // buradan sonra olusturulan obje gerekli listeye eklenecek
                tempEmployeeList.append(&e1);
            }

            if (employeeType == 1){
                //"PermanentEmployee olusturuluyor"
                PermanentEmployee e1(employeeNumber, employeeType, employeeName,employeeSurname,employeeTitle,employeeSalaryCoefficient,birthDate,appoiDate,employeeLengthofService);

                // buradan sonra olusturulan obje gerekli listeye eklenecek
                Node *permNode = new Node(e1);
                permEmployeeList.append(permNode);
            }

        }

        if (number == 3){
            // oncelikle cin ine numara al
            // eger numara listede varsa devam et
            // employee.setEmployeeTitle(newTitle);
            // employee.setEmployeeSalaryCoefficient(newSalary);

            cout << "Type the number of the employee whose title and salary coefficient are to be updated" << endl;
            int empNumber;
            cin >> empNumber;
            cout << "Type new Title" << endl;
            string newTitle;
            cin >> newTitle;
            cout << "Type new Salary Coefficient" << endl;
            double newSalaryCoefficient;
            cin >> newSalaryCoefficient;

            Node *node = permEmployeeList.isNumber(empNumber);
            if (node == NULL){
                //"Permde yok"
                Nodee *empNode = tempEmployeeList.isNumber(empNumber);
                if (empNode == NULL){
                    cout << "There is no employee with this number." << endl;
                }
                else{
                    empNode->data->setEmployeeSalaryCoefficient(newSalaryCoefficient);
                    empNode->data->setEmployeeTitle(newTitle);
                }
            }
            else{
                node->empData.setEmployeeTitle(newTitle);
                node->empData.setEmployeeSalaryCoefficient(newSalaryCoefficient);
            }
        }

        if (number == 4){
            // oncelikle cin ine numara al
            // eger numara listede varsa devam et
            // employee yi sil

            cout << "Type the number of the employee to be deleted" << endl;
            int empNumber;
            cin >> empNumber;
            Node *node = permEmployeeList.isNumber(empNumber);
            if (node == NULL){
                //"Permde yok"
                Nodee *empNode = tempEmployeeList.isNumber(empNumber);
                if (empNode == NULL){
                    cout << "There is no employee with this number." << endl;
                }
                else{
                    //"Siliniyor"
                    tempEmployeeList.deleteEmp(empNumber);
                }
            }
            else{
                //"Siliniyor"
                permEmployeeList.deleteNode(empNumber);
            }
        }

        if (number == 5){
            // eger numara listede varsa devam et
            // zaten << overloading yapıldığı için direkt
            // cout << employee << endl;

            cout << "Type the number of the employee whose information will be listed" << endl;
            int empNumber;
            cin >> empNumber;
            Node *node = permEmployeeList.isNumber(empNumber);
            if (node == NULL){
                //"Permde yok"
                Nodee *empNode = tempEmployeeList.isNumber(empNumber);
                if (empNode->data == NULL){
                    cout << "There is no employee with this number." << endl;
                }
                else{
                    cout << *empNode->data << endl;
                }
            }
            else{
                cout << node->empData << endl;
            }
        }

        if (number == 6){
            // calisan numarasina gore artan sıralama
            // yeni bir vector
            // icine sırayla butun employee ler
            // sonra compare fonksiyonuna bakarak butun employee leri numbera gore sirala
            // en son butun vector u gezerek cout << employee

            vector<Employee> sortedList;
            Node *temp = permEmployeeList.head;

            if (temp->next == NULL){
                //"listedeki son eleman"
                sortedList.push_back(temp->empData);
            }
            while (temp->next != NULL){
                sortedList.push_back(temp->empData);
                temp = temp->next;
                // eger yeni temp.next == NULL ise onu da listeye ekliyorum cunku tekrar while a girmiyor
                if (temp->next == NULL){
                    sortedList.push_back(temp->empData);
                }
            }
            sort(sortedList.begin(), sortedList.end(), compareNumber);
            // sayi olarak kucukten buyuye(artan)
            for (int i = 0; i < sortedList.size(); ++i) {
                cout << sortedList[i];
                cout << "----------------------------------------------------" << endl;
            }
        }

        if (number == 7){
            // eskiden yeniye sıralama
            cout << "Listing of all employees in the order of their appointment to the institution" << endl;


            vector<Employee> sortedList;
            Node *temp = permEmployeeList.head;

            if (temp->next == NULL){
                //"listedeki son eleman"
                sortedList.push_back(temp->empData);
            }
            while (temp->next != NULL){
                sortedList.push_back(temp->empData);
                temp = temp->next;
                // eger yeni temp.next == NULL ise onu da listeye ekliyorum cunku tekrar while a girmiyor
                if (temp->next == NULL){
                    sortedList.push_back(temp->empData);
                }
            }
            sort(sortedList.begin(), sortedList.end(), compareDate);
            // eskiden yeniye siralama
            for (int i = 0; i < sortedList.size(); ++i) {
                cout << sortedList[i];
                cout << "----------------------------------------------------" << endl;
            }
        }

        if (number == 8){
            // yeniyden eskiye sıralama
            // 2002 - 2001 - 2000

            // bu tarihten sonra kuruma atanan -> verilen 2001 istenen 2002 if verilen < emp.date

            cout << "Type the date on which the employees assigned to the institution will be listed after that date" << endl;
            string dateString;
            cin >> dateString;
            int *dateArray = new int[3];
            dateArray = split(dateString);
            Date date(dateArray[0],dateArray[1],dateArray[2]);


            vector<Employee> sortedList;
            Node *temp = permEmployeeList.head;
            cout << temp->empData.getEmployeeName() << endl;
            if (temp->next == NULL){
                //"listedeki tek eleman"
                // eger verilen < emp.date ise listeye ekle
                if (date < temp->empData.getEmployeeAppointmentDate()){
                    sortedList.push_back(temp->empData);
                }
            }
            while (temp->next != NULL){
                if (date < temp->empData.getEmployeeAppointmentDate()){
                    sortedList.push_back(temp->empData);
                }
                temp = temp->next;
                // eger yeni temp.next == NULL ise onu da listeye ekliyorum cunku tekrar while a girmiyor
                if (temp->next == NULL){
                    if (date < temp->empData.getEmployeeAppointmentDate()){
                        sortedList.push_back(temp->empData);
                    }
                }
            }
            sort(sortedList.begin(), sortedList.end(), compareDate);
            // compareDate eskiden yeniye siraliyor. bu yüzden listeyi tersten bastiriyoruz
            // yeniden eskiye siralama
            for (int i = sortedList.size()-1; i > -1; --i) {
                cout << sortedList[i];
                cout << "----------------------------------------------------" << endl;
            }
        }

        if (number == 9){
            // eskiden yeniye sıralama
            // 2000 - 2001 - 2002

            cout << "Type the year in which the employees assigned to the institution will be listed this year. " << endl;
            int year;
            cin >> year;

            // butun listeyi dolas
            // if(data == emp.AppoinDate{cout << emp  << endl;


            vector<Employee> sortedList;
            Node *temp = permEmployeeList.head;
            if (temp->next == NULL){
                //"listedeki tek eleman"
                // eger verilen < emp.date ise listeye ekle
                if (year == temp->empData.getEmployeeAppointmentDate().getYear()){
                    sortedList.push_back(temp->empData);
                }
            }
            while (temp->next != NULL){
                if (year == temp->empData.getEmployeeAppointmentDate().getYear()){
                    sortedList.push_back(temp->empData);
                }
                temp = temp->next;
                // eger yeni temp.next == NULL ise onu da listeye ekliyorum cunku tekrar while a girmiyor
                if (temp->next == NULL){
                    if (year == temp->empData.getEmployeeAppointmentDate().getYear()){
                        sortedList.push_back(temp->empData);
                    }
                }
            }
            sort(sortedList.begin(), sortedList.end(), compareDate);
            // eskiden yeniye siralama
            for (int i = 0; i < sortedList.size(); ++i) {
                cout << sortedList[i];
                cout << "----------------------------------------------------" << endl;
            }
        }

        if (number == 10){
            // çalışan numarasına göre artan sıralama

            // Belirli bir tarihten önce doğan çalışanların listesi -> verilen date = 01-08-2001 istenilen 01-08-2000 if( emp.date < date)

            cout << "Type the date on which the employees born will be listed before this date" << endl;
            string dateString;
            cin >> dateString;
            int *dateArray = new int[3];
            dateArray = split(dateString);
            Date date(dateArray[0],dateArray[1],dateArray[2]);
            cout << date << endl;


            vector<Employee> sortedList;
            Node *temp = permEmployeeList.head;
            cout << temp->empData.getEmployeeName() << endl;
            if (temp->next == NULL){
                //"listedeki tek eleman"
                // eger  emp.date < verilen ise listeye ekle
                if (temp->empData.getEmployeeBirthDate() < date){
                    sortedList.push_back(temp->empData);
                }
            }
            while (temp->next != NULL){
                if (temp->empData.getEmployeeBirthDate() < date){
                    sortedList.push_back(temp->empData);
                }
                temp = temp->next;
                // eger yeni temp.next == NULL ise onu da listeye ekliyorum cunku tekrar while a girmiyor
                if (temp->next == NULL){
                    if (temp->empData.getEmployeeBirthDate() < date){
                        sortedList.push_back(temp->empData);
                    }
                }
            }
            // calisan numarasina gore siralama
            sort(sortedList.begin(), sortedList.end(), compareNumber);
            // sayi olarak kucukten buyuye(artan)
            for (int i = 0; i < sortedList.size(); ++i) {
                cout << sortedList[i];
                cout << "----------------------------------------------------" << endl;
            }

        }

        if (number == 11){
            // 9 un appointmantdate yerine birthDate in sadece month hali
            // üstte direkt Date < ü kullanılırken burada e1.getmonth < e2.getmonth yapılabilir

            // Belirli bir ayda doğan çalışanların listesi
            // çalışan sayısına göre artan

            cout << "Type the month in which employees born will be listed in this month(Enter an integer between 1 and 12)" << endl;
            int month;
            cin >> month;

            vector<Employee> sortedList;
            Node *temp = permEmployeeList.head;
            cout << temp->empData.getEmployeeName() << endl;
            if (temp->next == NULL){
                //"listedeki tek eleman"
                // eger verilen < emp.date ise listeye ekle
                if (month == temp->empData.getEmployeeBirthDate().getMonth()){
                    sortedList.push_back(temp->empData);
                }
            }
            while (temp->next != NULL){
                if (month == temp->empData.getEmployeeBirthDate().getMonth()){
                    sortedList.push_back(temp->empData);
                }
                temp = temp->next;
                // eger yeni temp.next == NULL ise onu da listeye ekliyorum cunku tekrar while a girmiyor
                if (temp->next == NULL){
                    if (month == temp->empData.getEmployeeBirthDate().getMonth()){
                        sortedList.push_back(temp->empData);
                    }
                }
            }

            sort(sortedList.begin(), sortedList.end(), compareNumber);
            // sayi olarak kucukten buyuye(artan)
            for (int i = 0; i < sortedList.size(); ++i) {
                cout << sortedList[i];
                cout << "----------------------------------------------------" << endl;
            }
        }

        if (number == 12){
            cout << "Type the title where the information of the person who was last appointed to the institution and has this title will be listed" << endl;
            string title;
            cin >> title;
            cout << title << endl;

            vector<Employee> sortedList;
            Node *temp = permEmployeeList.head;

            if (temp->next == NULL){
                //"listedeki tek eleman"
                // eger verilen < emp.date ise listeye ekle
                if (title == temp->empData.getEmployeeTitle()){
                    sortedList.push_back(temp->empData);
                }
            }
            while (temp->next != NULL){
                if (title == temp->empData.getEmployeeTitle()){
                    sortedList.push_back(temp->empData);
                }
                temp = temp->next;
                // eger yeni temp.next == NULL ise onu da listeye ekliyorum cunku tekrar while a girmiyor
                if (temp->next == NULL){
                    if (title == temp->empData.getEmployeeTitle()){
                        sortedList.push_back(temp->empData);
                    }
                }
            }
            // permList te gezme islemi zaten tarihe gore eskiden yeniye oldugu icin listeye eklenen son eleman en yeni eleman
            cout << sortedList[sortedList.size()-1] << endl;
        }
    }
    return 0;
}

int* split(const string& text){
    int* intArray=new int[3];
    string strToken;
    int index=0;

    stringstream ss(text);
    while(getline(ss, strToken, '-')){
        stringstream toInt(strToken);
        int intToken;
        toInt >> intToken;
        intArray[index]= intToken;
        index++;
    }
    return intArray;
}

bool compareNumber(const Employee& e1, const Employee& e2){
    return (e1.getEmployeeNumber() < e2.getEmployeeNumber());
}

bool compareDate(const Employee& e1, const Employee& e2){
    return (e1.getEmployeeAppointmentDate() < e2.getEmployeeAppointmentDate());
}