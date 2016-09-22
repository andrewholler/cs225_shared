#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        Student();
        void setName(string newName);
        void setGrade(int newGrade);
        string getName();
        int getGrade();
    private:
        string name;
        int grade;
};

Student::Student(){name = "Jill"; grade = 3;}
void Student::setName(string newName){name = newName;}
void Student::setGrade(int newGrade){grade = newGrade;}
string Student::getName(){return name;}
int Student::getGrade(){return grade;}

void graduate(Student & student){
    student.setGrade(student.getGrade() + 1);
}

int main(){
    Student Sally;
    Sally.setName("Sally");
    Sally.setGrade(5);
    cout << Sally.getName() << " is in grade " << Sally.getGrade() << "." << endl;
    graduate(Sally);
    cout << Sally.getName() << " is in grade " << Sally.getGrade() << "." << endl;
    return 0;
}
