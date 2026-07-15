#include <iostream>
#include "StudentManagement.h"

using namespace std;

int main()
{
    StudentManagement sm;
    sm.loadStudents();


    int choice;

    do
    {
        sm.displayMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            sm.addStudent();
            break;

        case 2:
            sm.displayStudents();
            break;

        case 3:
            sm.searchStudent();
            break;

        case 4:
            sm.updateStudent();
            break;

        case 5:
            sm.deleteStudent();
            break;

        case 6:
            sm.statistics();
            break;

        case 7:
            sm.saveStudents();
            cout << "Good Bye.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 7);

    return 0;
}
