#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;

#include "PSS_date.h"

PSS_date::PSS_date(string week_day, double start, double end){
	this->week_day = week_day;
	this->start = start;
	this->end = end;
}
