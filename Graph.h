#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<iomanip>
//Here we create the graph, with storing our Groups and PSS_dates in it


#include <stdio.h>
#include<string>
using namespace std;



class Group;
class PSS_date;

class Graph {
	friend class Instructor;
	friend class Student;
private:
     int number_of_groups;
     int number_of_time_intervals;

     int** AdjMatrix;
	 Group** vertex1; 
	 PSS_date** vertex2;  
public:
	Graph();
	~Graph();

	void get_free_days(string instructor_id, string group_code);
	void get_pss_of_given_class(string group_id);
	void set_pss(string instructor_id, string group_id);
	void get_pss_by_weekday(string student_id, string day);
	void get_info_about_TA( string subject_id);
	void get_schedule(string student_id);
	
	
	
	


};




#endif