#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;

#include "Group.h"
#include "TA.h"
#include "Student.h"
#include "Instructor.h"


Group::Group(string groupCode, string subjectName, string section) {
	this->group_code = groupCode;
	this->subject_name = subjectName;
	this->section = section;
	this->number_of_students = 0;

	this->instructor = new Instructor;
	this->teacher_asistent = new TA;
	this->students = new Student*[5];
}

void Group::setTA(string fn, string ln){
	teacher_asistent->first_name=fn;
	teacher_asistent->last_name=ln;
}

void Group::setInstructor(string fn, string ln, string id) {
	instructor->first_name = fn;
	instructor->last_name = ln;
	instructor->inst_id = id;
}


void Group::addStudent(string fn, string ln, string id) {
	if(this->number_of_students < 4) {
		Student* st = new Student();
		st->first_name = fn;
		st->last_name = ln;
		st->student_id = id;

		this->students[this->number_of_students] = st;
		this->number_of_students++;
	}
}


Group::~Group (){
	delete teacher_asistent;
	delete instructor;
	delete [] students;
}
