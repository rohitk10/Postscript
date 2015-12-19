/* Author : Rohit Kulkarni
   Description : This is a parent class Graph that is inherited by two child classes BarGraph and LineGraph
*/   
#ifndef _GRAPH_HH
#define _GRAPH_HH

#include <string>
using namespace std;

class Graph
{
public:
	string title, h_label, v_label;//string variables to store graph title, horizontal and vertical axes label
	int num_of_variables, num_of_values;//integer variables to store number of variables and number of values on x axis

};

#endif

