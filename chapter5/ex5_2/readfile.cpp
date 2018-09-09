#include "readfile.h"
#include "split.h"


using std::vector;   using std::string;
using std::list;     using std::getline;
using std::stod;     using std::ifstream;

vector<Student_info> vectorret_read(ifstream& f){
    vector<Student_info> vec_s;
    vector<string> v;
    Student_info student;
    string s;
    while(getline(f, s)){
        v = split(s);
        student.name = v[0];
        student.midterm = stod(v[1]);
        student.final = stod(v[2]);
        for(vector<string>::size_type i = 3; i != v.size(); i++){
            student.homework.push_back(stod(v[i]));
        }
        vec_s.push_back(student);
    }
    return vec_s;
}


list<Student_info> listret_read(ifstream& f){
    list<Student_info> list_s;
    vector<string> v;
    Student_info student;
    string s;
    while(getline(f, s)){
        v = split(s);
        student.name = v[0];
        student.midterm = stod(v[1]);
        student.final = stod(v[2]);
        for(list<string>::size_type i = 3; i != v.size(); i++){
            student.homework.push_back(stod(v[i]));
        }
        list_s.push_back(student);
    }
    return list_s;
}
