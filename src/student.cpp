#include "student.h"
#include <cctype>
#include <limits>
Student::Student()
{
    //ctor
    id = 0;
    name = " ";
    age = 0;
    department = " ";
    gpa = 0.0;

}
//setter
void Student::setId(int i) {
    id = i;
}

void Student::setName(string n){
    name = n;
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setDepartment(string d)
{
    department = d;
}

void Student::setGpa(float g)
{
    gpa = g;
}

//getter
int Student::getId() const
{
    return id;
}

string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

string Student::getDepartment() const
{
    return department;
}

float Student::getGpa() const
{
    return gpa;
}
bool Student::isValidName(string name){
    for (char ch : name)
    {
        if (!isalpha(ch) && ch != ' ')
        {
            return false;
        }
    }

    return true;
}

int Student::readId()
{

    while (true)
    {
        cout << "Enter ID: ";
        cin >> id;

        if (cin.fail())
        {
            cout << "Invalid ID. Enter numbers only.\n";

            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            cin.ignore(1000, '\n');
            return id;
        }
    }
}
string Student::readName()
{
    string tempName;

    do
    {
        cout << "Enter Name: ";
        getline(cin, tempName);

        if (!isValidName(tempName))
        {
            cout << "Invalid Name. Name must not contain numbers.\n";
        }

    } while (!isValidName(tempName));

    return tempName;
}
char Student::readAge(){
    while (true)
    {
        cout << "Enter Age: ";
        cin >> age;

        if (cin.fail())
        {
            cout << "Invalid Age. Numbers only.\n";

            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (age < 0 || age > 100)
        {
            cout << "Invalid Age. Please enter a valid age.\n";

            cin.ignore(1000, '\n');
        }
        else
        {
            cin.ignore(1000, '\n');
            return age;
        }
    }
}
float Student::readGpa(){
    while(true){
        cout << "Enter GPA: ";
        cin >> gpa;
        if(cin.fail()){

            cout<<"Invalid Age. Numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(gpa < 0 || gpa > 4){

            cout << "Invalid GPA.";
            cin.ignore(1000, '\n');

        }else {

            cin.ignore(1000, '\n');
            return gpa;
        }
    }


}
string Student::chooseDepartment()
{
    char choice;

    while(true){
        cout << "Choose Department\n";
        cout << "1. Computer Science\n";
        cout << "2. Information Technology\n";
        cout << "3. Artificial Intelligence\n";
        cout << "4. Information Systems\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            return "Computer Science";

        case '2':
            return "Information Technology";

        case '3':
            return "Artificial Intelligence";

        case '4':
            return "Information Systems";

        default:
            cout << "Invalid Choice\n";
        }
    }

}
void Student::inputStudent()
{
        setId(id);
        setName(readName());
        setAge(readAge());
        setDepartment(chooseDepartment());
        setGpa(readGpa());

}

void Student::displayStudent()
{
    cout << "\nStudent Information\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Department: " << department<< endl;
    cout << "GPA: " << gpa << endl;
}

Student::~Student()
{
    //dtor
}
