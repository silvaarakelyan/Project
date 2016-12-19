#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;


class Graph;
class Group;

class Instructor{
	friend class Graph;
	friend class Group;
private:
	string  first_name; 
	string  last_name;
	string  inst_id;
public:
	Instructor(){};
	Instructor(string ,string);
	~Instructor(){};
};





#endif
