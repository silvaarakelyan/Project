#ifndef MEMBER_STUDENT_H
#define MEMBER_STUDENT_H


#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;

class Group;
class Graph;
class Student{
	friend class Graph;
	friend class Group;
private:
	string first_name;
	string last_name;
	string student_id;

public:
	Student() {};
	~Student(){};

	
};

#endif