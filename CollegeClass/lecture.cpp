#include <iostream>
#include <string>
#include "lecture.hpp"
using namespace std;

Student::Student()
{
    index = n++;
    name = "N/A";
}
//Setter
void Student::set_name(const string student_name){
    this->name = student_name;
}
void Student::set_matrikel(const int new_matrikel){
    this->matrikelnummer = new_matrikel;
}
//Getter
    string Student::get_name() const{
        return name;
}

//Stetter
void Kurs::set_lvtitle(const string new_title){
    this->lvtitle = new_title;
}

void Kurs::set_student(vector<Student> &students){
    this->students = students;
}

void Kurs::course_list(vector<string> &course_list){
    string lv_title;
    cin.clear();
    cin.ignore();
    cout << " Enter Name of your Lecture: ";
    getline(cin,lv_title);
    course_list.push_back(lv_title);
    cout << " New lecture created. \n\n";
}

Kurs Kurs::get_course(vector<string> &course_list){
    int i{0}, choice;
    Kurs course;
    
    cin.clear();
    cin.ignore();
    cout << " To which Course do you want to assign a Student? \n";
    for(auto elem:course_list) cout << "[" << i++ << "] " << elem << endl;
    
    cin >> choice;
    course.set_lvtitle(course_list[choice]);
    
    return course;
}

void Kurs::add_student(vector<Student> &students, vector<string>&course_list, Kurs &course){
    string student_name;
    int new_matrikel;
    Student new_student;
    get_course(course_list);
    cin.clear();
    cin.ignore();
    
    cout << " Name of the Student: ";
    getline(cin, student_name);
    new_student.set_name(student_name);
    
    cin.clear();
    cin.ignore();
    cout << "Enrollment Number of the Student: ";
    cin >> new_matrikel;
    new_student.set_matrikel(new_matrikel);
    
    students.push_back(new_student);
    course.set_student(students);
    }

void Kurs::rmv_student(vector<Student> &students){
}

Grade::Grade(){
    grade = 0.0;
};
