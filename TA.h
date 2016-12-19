#ifndef TA_H
#define TA_H


#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;

class Group;
class Graph;
class TA{
	friend class Group;
	friend class Graph;
private:
	string first_name;
	string last_name;

public:
	TA(){};
	~TA() {};
};


#endif