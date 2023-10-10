// NAME: Michael Bermeo
// Project #: 02
// Professor: Dr. V
// Date 10 Oct 2023
// Description:
// To create an iheratence program that will create a data structure that will take studet and proofessors
// infromation by using a superclass and subclasses. For the student it will take in name and courses.
// For the professors it will take name and office loction. The end product is to display all of the info in
// the main function.

#include <iostream>
#include <string>

using namespace std;

// Person Classicication (Parent Class)
class Person

{
public:
    Person(const string& name) : name(name) {}

    string getName()
    {
        return name;
    }

private:
    string name;
};

// Student Classification (Child Class)
class Student :
public Person
{
public:
    Student(const string& name) : Person(name) {}

    // Method to add a course to the student's list
    void addCourse(const string& course) 
    {
        if (courses.size() < 10) 
        {
            courses.push_back(course);
            cout << "Course added: " << course << endl;
        }
        
        else
        {
            cout << "Course limit reached." << endl;
        }
    }

    //This will take in all of the course the student will be taking
    void listCourses()
    {
        if (courses.empty()) 
        {
            cout << getName() << " has not enrolled." << endl;
        } 
        else
        {
            cout << getName() << " has enrolled in the following courses"<< ":" << endl;
            for (const string& course : courses) 
            {
                cout << course << endl;
            }
        }
    }

private:
    vector<string> courses;
};

// Professor Classicaction (Child Class)
class Professor :
public Person
{
public:
    Professor(const string& name, const string& officeRoom)
        : Person(name), officeRoom(officeRoom) {}

    // This will give us the location of where the professor is
    void displayofficeRoom()
    {
        cout << getName() << "'s office is located at " << officeRoom << endl;
    }

private:
    string officeRoom;
};

// Main function test
int main()
{
    Student student("Mike");
    student.addCourse("Science");
    student.addCourse("Physcology");
    student.addCourse("Math");
    student.listCourses();

    Professor professor("Prof. Smith", "is in Room 100");
    professor.displayofficeRoom();

    return 0;
}
