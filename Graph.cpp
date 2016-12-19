#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<string>
using namespace std;


#include "Graph.h"
#include "Student.h"
#include "Instructor.h"
#include "TA.h"
#include "Group.h"
#include "PSS_date.h"

//constructor
Graph::Graph(){
	//for the beginning we just have 3 groups, and 15 time intervals, which are already defined
	number_of_groups=3;
	number_of_time_intervals=15;

	vertex1 = new Group*[number_of_groups];

	vertex1[0] = new Group("CS102", "Calculus" ,"A");
	vertex1[0]->setTA("Vazgen", "Melqonyan");
	vertex1[0]->setInstructor("Karen" ,"Navasardyan", "44545545");
	vertex1[0]->addStudent("Silva", "Arakelyan", "A09150394" );
	vertex1[0]->addStudent("Naira", "Matosyan", "A09150121" );
	vertex1[0]->addStudent("Syuzanna", "Loretsyan", "09150111" );
				 
	vertex1[1] = new Group( "CSE241", "Data mining", "B");
	vertex1[1]->setTA("Artyom", "Yepremyan");
	vertex1[1]->setInstructor("Habet" , "Madoyan", "45487888");
	vertex1[1]->addStudent("Silva", "Arakelyan", "A09150394" );
	vertex1[1]->addStudent("Shushanna", "Arakelyan", "A09150125" );
	vertex1[1]->addStudent("Hilda", "Karakhanyan", "09150562" );
			     
	vertex1[2] =new Group("COMP121", "Data Structures", "A");
	vertex1[2]->setTA("Yeranuhi", "Margaryan");
	vertex1[2]->setInstructor("Satenik" , "Mnatsakanyan", "15457200");
	vertex1[2]->addStudent("Silva", "Arakelyan", "A09150394" );
	vertex1[2]->addStudent("Shushanna", "Arakelyan", "A09150125" );
	vertex1[2]->addStudent("Hilda", "Karakhanyan", "09150562" );

				 
				
	vertex2 = new PSS_date*[15];

	vertex2[0]= new PSS_date("Monday",    15.00, 16.00);
	vertex2[1]= new PSS_date("Monday",    16.00, 17.00);
	vertex2[2]= new PSS_date("Monday",    17.00, 18.00);
	vertex2[3]= new PSS_date("Tuesday",   15.00, 16.00);
	vertex2[4]= new PSS_date("Tuesday",   16.00, 17.00);
	vertex2[5]= new PSS_date("Tuesday",   17.00, 18.00);
	vertex2[6]= new PSS_date("Wednesday", 15.00, 16.00);
	vertex2[7]= new PSS_date("Wednesday", 16.00, 17.00);
	vertex2[8]= new PSS_date("Wednesday", 17.00, 18.00);
	vertex2[9]= new PSS_date("Thuesday",  15.00, 16.00);
	vertex2[10]= new PSS_date("Thuesday", 16.00, 17.00);
	vertex2[11]= new PSS_date("Thuesday", 17.00, 18.00);
	vertex2[12]= new PSS_date("Friday",   15.00, 16.00);
	vertex2[13]= new PSS_date("Friday",   16.00, 17.00);
	vertex2[14]= new PSS_date("Friday",   17.00, 18.00);

	//creating adj matrix , there are no setted pss-s

	AdjMatrix = new int*[number_of_time_intervals];

	for(int i=0; i<number_of_time_intervals; i++)
	{
		AdjMatrix[i] = new int[number_of_groups]; 
		for(int j=0; j<number_of_groups;j++)
		{
			AdjMatrix[i][j]=0;
		}
	}
	
}



//destructor
Graph::~Graph(){
	for (int i=0; i<number_of_groups; i++)
	{
		
			delete [] AdjMatrix[i];
			delete [] AdjMatrix;
	}

	delete [] vertex1;
	delete [] vertex2;


}



void Graph::get_free_days(string instructor_id, string group_code) {
	//this function is for instructors, to see free days, if he/she wants, he/she can set pss
	cout<<endl;
	int i;
	bool isFree;
	for(i=0; i<number_of_time_intervals; i++)
	{
		isFree = true;
		for(int j=0; j < number_of_groups; j++){
			if(AdjMatrix[i][j] == 1) {
				isFree = false;
				break;
			}
		}
		if(isFree) {
			cout<<i+1<<"."<<" "<<vertex2[i]->week_day<<setw(25)<<vertex2[i]->start<<":00"<<"-"<<vertex2[i]->end<<":00"<<endl;
		}
	}

	bool x;
	int free;
	bool count=false;
	cout<<"Do you want to set PSS from these suggested intervals?"<<endl;
	cout<<"Yes-0 : No-1"<<endl;
	cin>>x;


	if(x == 0 ){
		cout<<"Enter which interval"<<endl;
		cin>>free;

		for(int k=0; k < number_of_groups; k++)
		{
			if(vertex1[k]->instructor->inst_id == instructor_id && vertex1[k]->group_code ==group_code )
			{
				AdjMatrix[free-1][k] = 1;
				count=true; //this is done just for checking weather he is instructor  or not
				break;
			}
		}
	
		if(count) 
		{
			cout<<"PSS was successfully added"<<endl;

			for(i=0; i<number_of_time_intervals; i++)
			{
				isFree = true;
				for(int j=0; j < number_of_groups; j++){
					if(AdjMatrix[i][j] == 1) {
						isFree = false;
						break;
					}
				}
				if(isFree) {
					cout<<i+1<<"."<<" "<<vertex2[i]->week_day<<setw(25)<<vertex2[i]->start<<":00"<<"-"<<vertex2[i]->end<<":00"<<endl;
				}
			}
		} //and we see that the curtain date is already not included in free-days list
		else 
		{ 
			cout<<"There isnt instructor with your given ID"<<endl;
		}
	}

	cout<<endl;
}


void  Graph::set_pss( string instructor_id, string group_id){
//function is for instructor, to set pss
		cout<<endl;
		bool answer; 
		int m;
			cout<<"Here are suggested time_intervals"<<endl;
			for(int i=0; i<number_of_time_intervals;i++)
			{
				cout<<i+1<<"."<<vertex2[i]->week_day<<setw(25)<<vertex2[i]->start<<":00"<<"-"<<vertex2[i]->end<<":00"<<endl;
			}

			cout<<"Select which interval do you want"<<endl;
			cin>>m; 


			for(int j=0; j<number_of_groups; j++){
				if(vertex1[j]->instructor->inst_id==instructor_id){
					AdjMatrix[m-1][j]=1;
					answer=true;
					break;
				}
			}
			
				cout<<"PSS was successfully added"<<endl;
		
			
		   cout<<endl;
	
}



void Graph::get_pss_by_weekday(string student_id, string day)
{ //function is for student, to give his/her id and the week day 
  //and see weather he/she has a pss on mentioned day
	cout<<endl;
	for(int i=0; i<number_of_groups; i++)
	{ //for each group
		for(int j=0; j<vertex1[i]->number_of_students; j++)
		{ //the first identify weather a student is a member of that group

			if(vertex1[i]->students[j]->student_id==student_id){ //if student is a member of that group
				
				for(int k=0; k<number_of_time_intervals; k++)
				{ //find his/her given day, if there is a pss print it
					if((vertex2[k]->week_day==day)&&(AdjMatrix[i][k]==1))
					{   cout<<"You have a PSS on :";
						cout<<vertex2[k]->week_day<<setw(25)<<vertex2[k]->start<<":00"<<"-"<<vertex2[k]->end<<":00"<<endl;
					}
				}
				break;
			}
		}
	}
}


void Graph::get_pss_of_given_class(string group_id) 
{   //function prints pss of the mentiond class 
	cout<<endl;
	for(int i=0; i<number_of_groups; i++)
	{   //the first find the group among the groups
		if(vertex1[i]->group_code==group_id) 
		{   //if it is found, now find its pss-s
			cout<<"PSS-s of "<< vertex1[i]->group_code <<" " <<vertex1[i]->subject_name<<"  "<<"section  "<<vertex1[i]->section<<" is"<<endl;
			for(int j=0; j<number_of_time_intervals; j++)
			{
				if(AdjMatrix[j][i]==1)
				{
					cout<<vertex2[j]->week_day<<setw(25)<<vertex2[j]->start<<":00"<<"-"<<vertex2[j]->end<<":00"<<endl;
				}
			}
		}
	}
}


void Graph::get_schedule(string student_id)
{  //function is for students, to see their schedul'only by taking student id
	cout<<endl;
	cout<<"Your schedule is"<<endl;
	//the first for all the classes
	for(int i=0; i<number_of_time_intervals; i++)
	{
		for(int j=0; j<number_of_groups; j++)
		{   //for each time inteval, for each group, first see weather student is in that group
			if(AdjMatrix[i][j]==1)
			{
				for(int k=0; k< vertex1[j]->number_of_students; k++)
				{ //if yes, print date, and lets notice that as dates are already in increasing order we already dont need to sort them
					if(vertex1[j]->students[k]->student_id==student_id)
					{
						cout<<vertex1[j]->subject_name<<" :" <<vertex2[i]->week_day<<" "<<vertex2[i]->start<<":00"<<"- "<<vertex2[i]->end<<":00"<<endl;
				    }
			    }
		   }
	   }
   }
}


void Graph::get_info_about_TA(string subject_id){
	//function is for getting info about TA, by giving subjects id
	for(int i=0; i<number_of_groups; i++)
	{
		if(vertex1[i]->group_code==subject_id)
		{ 
			cout<< "TA is:" << vertex1[i]->teacher_asistent->first_name<<"  "<<vertex1[i]->teacher_asistent->last_name<<endl;
		}
	}
}





