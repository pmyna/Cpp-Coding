#include <iostream>
#include <string>
#include <vector>
#include "lecture.hpp"

using namespace std;

int main(){
    Kurs new_entry;
    vector<Student>std_list;
    vector<string>course_list;
    int menu;
    bool keep_run{true};
    
    do{
        cout << " [0] Entry Lecture \n [1] Entry Student \n [2] Grading \n [3] Average Grades \n\n What would you like to do? ";
        cin >> menu;
        
        switch (menu) {
            case 0:
                new_entry.course_list(course_list);
                break;
            case 1:
                new_entry.add_student(std_list,course_list, new_entry);
            default: cout << "Program closed";
                keep_run = false;
                break;
        }
    }while(keep_run);
    
    return 0;
}

