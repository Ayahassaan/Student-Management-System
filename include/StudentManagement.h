#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <vector>
#include "Student.h"

using namespace std;

class StudentManagement
{
    private:
        vector<Student> students;
        bool isIdExist(int id);
    public:
        StudentManagement();

        //Refactoring
        void displayLine();
        void displayMainMenu();
        void displayStatisticsMenu();
        void displaySearchMenu();
        void displayUpdateMenu();

        string toLower(string text);

        void addStudent();
        void displayStudents();

        void searchStudent();
        void searchById();
        void searchByName();
        void searchByDepartment();

        void updateStudent();
        void deleteStudent();

        void sortStudents();
        void saveStudents(); //to save if exist
        void loadStudents();


        //Statistics.
        int NumberOfStudents();
        float Avg_GPA();
        bool HighestGPA(Student& highestStudent);
        bool LowestGPA(Student& lowestStudent);
        void statistics();

        virtual ~StudentManagement();
};

#endif // STUDENTMANAGEMENT_H
