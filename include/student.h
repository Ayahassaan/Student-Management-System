#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        int id;
        string name;
        int age;
        string department;
        float gpa;

    public:
        //constructor
        Student();

        //setter
        void setId(int i);
        void setName(string n);
        void setAge(int a);
        void setDepartment(string d);
        void setGpa(float g);

        //getter
        int getId() const;
        string getName() const;
        int getAge() const;
        string getDepartment() const;
        float getGpa() const;

        // Functions

        string readName();
        string chooseDepartment();
        char readAge();
        float readGpa();
        int readId();
        void inputStudent();
        void displayStudent();
        bool isValidName(string name);


        virtual ~Student();
};

#endif // STUDENT_H
