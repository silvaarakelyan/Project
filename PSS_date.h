#ifndef PSS_DATE_H
#define PSS_DATE_H


#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;

class Graph;

class PSS_date{
	friend class Graph;
private:
	string week_day;
	double start;
	double end;
public:
	PSS_date(string week_day, double start, double end);
	~PSS_date(){};

};

#endif
