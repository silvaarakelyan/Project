
#ifndef GROUP_H
#define GROUP_H


#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;


class Instructor;
class Student;
class TA;

class Group {
	friend class Graph;
private:
	string group_code;
	string subject_name;
	string section;
	int number_of_students;

	TA* teacher_asistent;
	Instructor* instructor;
	Student** students;

public:
	Group(string groupCode, string subjectName, string section);
	~Group();

	void setTA(string fn, string ln);
	void setInstructor (string fn, string ln, string id);
	void addStudent(string fn, string ln, string id);
	
	
};


#endif