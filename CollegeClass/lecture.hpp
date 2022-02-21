#ifndef lecture_hpp
#define lecture_hpp

#include<string>
#include <vector>
using namespace std;


class Student{
    int index, n;
    string name;
    int matrikelnummer;
public:
    Student();
    void set_name(const string student_name);
    string get_name() const;
    void set_matrikel(const int new_matrikel);
};

class Kurs{
    string lvtitle;
    vector<Student>students;
public:
    void set_lvtitle(const string new_title);
    void set_student(vector<Student>&students);
    void course_list(vector<string>&course_list);
    Kurs get_course(vector<string>&course_list);
    void add_student(vector<Student>&students,vector<string>&course_list,Kurs &course);
    void rmv_student(vector<Student>&students);
};

class Grade{
    Kurs gkurs;
    Student gstudent;
    double grade;
public:
    Grade();
    void set_grade();
    void change_grade();
    void avarage_student();
    void avarage_class();
};

#endif
