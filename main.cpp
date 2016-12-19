#include<iostream>
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
#include<string>
using namespace std;

#include "Student.h"
#include "Instructor.h"
#include "Graph.h"
#include "Group.h"
#include "PSS_date.h"

int main(){
	

	Graph* graph = new Graph();

	//function taking instructor id, and class _code 
	graph->get_free_days("45487888", "CSE241");
	graph->get_pss_of_given_class("CSE241");
	graph->get_info_about_TA("CSE241");
	graph->set_pss("44545545", "CS102");
	graph->get_pss_of_given_class("CS102");
	graph->set_pss ("15457200", "COMP121");
	graph->get_pss_of_given_class("COMP121");
	graph->get_pss_by_weekday("A09150394", "Monday");
	graph->get_pss_by_weekday("A09150394", "Friday");
	graph->get_schedule("A09150394");
    

	while (true){
		
		_sleep(1000);
	}

	

	return 0;


	system("pause");
}

