#include "StudentManagement.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

StudentManagement::StudentManagement()
{
    //ctor
}
void StudentManagement::displayLine()
{
    cout<<"==========================================\n";
}
string StudentManagement::toLower(string text)
{
    for(size_t i=0;i<text.length();i++)
    {
        text[i] = tolower(text[i]);
    }

    return text;
}
bool StudentManagement::isIdExist(int id)
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getId() == id)
        {
            return true;
        }
    }

    return false;
}
void StudentManagement::addStudent()
{

    Student student;
    student.readId();
    if (isIdExist(student.getId())){
        cout << "Student ID Already Exists.\n";
        return;
    }
    student.inputStudent();


    students.push_back(student);

    cout << "Student Added Successfully.\n";


    sortStudents();
    saveStudents();

}
void StudentManagement::displayStudents()
{
    if(students.empty()){
        cout<<"No Students found!!\n";
        return;
    }
    for(size_t i=0 ; i<students.size() ; i++){
        displayLine();
        students[i].displayStudent();
        displayLine();
    }

}
void StudentManagement::searchById()
{
    int id;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore(1000, '\n');

    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getId() == id)
        {
            cout << "Student Found.\n";
            students[i].displayStudent();
            return;
        }
    }

    cout << "Student Not Found.\n";
}
void StudentManagement::searchByName()
{
    string name;
    bool found = false;

    cout << "Enter Name: ";
    getline(cin, name);
    name = toLower(name);

    for (size_t i = 0; i < students.size(); i++)
    {
        string studentName = toLower(students[i].getName());

        if (studentName.find(name) != string::npos)
        {
            students[i].displayStudent();
            displayLine();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Students Found.\n";
    }
}
void StudentManagement::searchByDepartment()
{
    string department;
    bool found = false;

    cout << "Enter Department: ";
    getline(cin, department);
    department = toLower(department);

    for (size_t i = 0; i < students.size(); i++)
    {
        string studentDepartment = toLower(students[i].getDepartment());
        if (studentDepartment.find(department) != string::npos )
        {
            students[i].displayStudent();
            displayLine();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Students Found.\n";
    }
}
void StudentManagement::displaySearchMenu(){
        cout<<"1-Search by ID\n"
        <<"2-Search by Name\n"
        <<"3-Search by Department\n\n"
        <<"Enter your Choice:";
}
void StudentManagement::searchStudent()
{

    char choice;

    displaySearchMenu();

    cin>>choice;
    cin.ignore(1000, '\n');

    switch(choice){
    case '1':
        searchById();
        break;
    case '2':
        searchByName();
        break;
    case '3':
        searchByDepartment();
    break;
    default:
        cout << "Invalid Choice.\n";



    }
}
void StudentManagement::displayUpdateMenu(){
        cout << "\n===== Update Menu =====\n";
        cout << "1. Update Name\n";
        cout << "2. Update Age\n";
        cout << "3. Update Department\n";
        cout << "4. Update GPA\n";
        cout << "5. Update All\n";
        cout << "Choose: ";
}
void StudentManagement::updateStudent()
{
    int UpdateID;
    bool found = false;
    cout<<"Enter the Student ID you want to Update: ";
    cin>>UpdateID;
    for(size_t i = 0 ; i < students.size(); i++){

        if(students[i].getId() == UpdateID){

            found = true;

            int choice;


            displayUpdateMenu();

            cin >> choice;

            cin.ignore();

            switch (choice)
            {
            case 1:
                {
                    students[i].setName(students[i].readName());
                    break;
                }
            case 2:
                {
                    students[i].setAge(students[i].readAge());
                    break;
                }
            case 3:
                {
                    students[i].setDepartment(students[i].chooseDepartment());
                    break;
                }
            case 4:
                {
                    students[i].setGpa(students[i].readGpa());
                    break;
                }
            case 5:
                {
                    students[i].setName(students[i].readName());
                    students[i].setAge(students[i].readAge());
                    students[i].setDepartment(students[i].chooseDepartment());
                    students[i].setGpa(students[i].readGpa());
                    break;
                }
                default:
                cout << "Invalid Choice.\n";
                return;
            }

            cout << "Student Updated Successfully.\n";
            break;
        }
    }
    if(!found){
        cout<<"Student not found.\n";
    }

    sortStudents();
    saveStudents();

}

void StudentManagement::deleteStudent()
{
    int DeleteID;
    bool found = false;
    cout<<"Enter the Student ID you want to Delete: ";
    cin>>DeleteID;
    for(size_t i = 0 ; i < students.size(); i++){

        if(students[i].getId() == DeleteID){

            students.erase(students.begin() + i);
            cout<<"Student Deleted Successfully.\n";
            found = true;
            break;
        }

    }

    if(!found){
        cout<<"Student not found.\n";
    }

    sortStudents();
    saveStudents();



}

int StudentManagement::NumberOfStudents(){

    return (students.size());

}
float StudentManagement::Avg_GPA(){

    if (students.empty()){
        cout<<"Not Found!!";
        return 0;
    }
    float sum = 0;
    for(size_t i = 0;students.size() > i;i++){
        sum += students[i].getGpa();
    }
    return sum / students.size();

}
bool StudentManagement::HighestGPA(Student& highestStudent){

    if (students.empty()) {

        cout<<"Not Found!!";
        return false;
    }

    highestStudent = students[0];

    for(size_t i = 1;students.size() > i;i++){

        if(students[i].getGpa()> highestStudent.getGpa()){

            highestStudent = students[i];

        }
    }
    return true;
}
bool StudentManagement::LowestGPA(Student& lowestStudent){

    if (students.empty()){

        cout<<"Not Found!!";
        return false;
    }

    lowestStudent = students[0];

    for(size_t i = 1;students.size() > i;i++){

        if(students[i].getGpa() < lowestStudent.getGpa()){

            lowestStudent = students[i];
        }
    }

    return true;
}
void StudentManagement::displayStatisticsMenu(){
    cout << "1. Number Of Students.\n";
    cout << "2. Highest GPA Student.\n";
    cout << "3. Lowest GPA Student.\n";
    cout << "4. Average GPA.\n";
    cout << "5. back.\n";

    cout << "Enter Your Choice: ";
}
void StudentManagement::statistics()
{
    char choice;

    displayStatisticsMenu();

    cin >> choice;

    switch(choice)
    {
    case '1':
        cout<<"The Number of Student Is: "<<NumberOfStudents()<<endl;
        break;
    case '2':
    {


        Student highestStudent;
        if(HighestGPA(highestStudent))
        {
            cout<<"The student with the highest GPA is:\n";
            displayLine();
            highestStudent.displayStudent();
        }
        else
        {
            cout << "No Students Found.\n";
        }
        break;
    }
    case '3':
    {
        Student lowestStudent;
        if(LowestGPA(lowestStudent))
        {
            cout<<"The student with the lowest GPA is:\n";
            displayLine();
            lowestStudent.displayStudent();
        }
        else
        {
            cout << "No Students Found.\n";
        }
        break;
    }
    case '4':
        cout<<"The Average Of GPA Is: "<<Avg_GPA()<<endl;
        break;
    case '5':
        return;
    default:
        cout<<"Wrong choice!!";
    }
}
void StudentManagement::sortStudents()
{

    sort(students.begin(), students.end(),
        [this](Student a, Student b)
        {
        string name1 = a.getName();
        string name2 = b.getName();

        toLower(name1);
        toLower(name2);

        return name1 < name2;
    });
}
void StudentManagement::saveStudents()
{
    ofstream file("students.txt");

    for(size_t i=0;i<students.size();i++)
    {
        file<<students[i].getId()<<"|";
        file<<students[i].getName()<<"|";
        file<<students[i].getAge()<<"|";
        file<<students[i].getDepartment()<<"|";
        file<<students[i].getGpa()<<endl;
    }

    file.close();
}
void StudentManagement::loadStudents()
{
    ifstream file("students.txt");

    if (!file.is_open())
    {
        return;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string name;
        string age;
        string department;
        string gpa;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, age, '|');
        getline(ss, department, '|');
        getline(ss, gpa, '|');


        Student student;

        student.setId(stoi(id));
        student.setName(name);
        student.setAge(stoi(age));
        student.setDepartment(department);
        student.setGpa(stof(gpa));

        students.push_back(student);
    }

    file.close();
}

void StudentManagement::displayMainMenu(){
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Statistics\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
}
StudentManagement::~StudentManagement()
{
    //dtor
}
