/* Author : Rohit Kulkarni
   Description : This is a header file containing a method bar_input().
                 It is responsible for taking user inputs such as Graph title, axes' labels
                 and finally, the values to be plotted on the bar graph.
                 It then calls one of the two functions from class BarGraph depending on the user inputs.
*/                 
#ifndef _BARGRAPHINPUT_HH
#define _BARGRAPHINPUT_HH

#include "BarGraph.hh"

#include <iostream>
using namespace std;

void bar_input()
{
                        	BarGraph b("bargraph.ps");
	                        string title, h_label, v_label;// string variables to store horizontal and vertical axes labels
				int num_of_values,num_of_variables;// integer variables to store number of bars and number of vairbles on x axis
				cout << "Enter Graph Title \n";
				cin >> title;
				cout << "Enter Horizontal axis label and Vertical axis label \n";
				cin >> h_label;
				cin >> v_label;
				cout << "Enter number of bars (1 or 2) \n";
				cin >> num_of_variables;
				switch(num_of_variables)
				{
				case 1 :
				{
					cout << "Enter number of values on horizontal axis \n";
					cin >> num_of_values;
					double b1[num_of_values];
					string label[num_of_values];
					double intervalh;// double variable to store horizontal gap between 2 bars on x axis
					intervalh = 500 / num_of_values;
					for(int i = 0; i < num_of_values; i ++)
					{
						cout << "Enter label " << i+1 << '\n';
						cin >> label[i];
						cout << "Enter value " << i+1 << '\n';
						cin >> b1[i];
					}
					double max;
					max = b1[0];
					for(int i = 0; i < num_of_values-1; i++)
					{
						if(b1[i+1] > max)
						{
							max = b1[i+1];
						}
					}
					double intervalv;// double variable to store vertical gap between to values on y axis
					intervalv = 500/max;
					b.bargraph1(title, h_label, v_label, num_of_values, intervalh, intervalv, label, b1);
					break;
				}

				case 2 :
				{
					cout << "Enter number of values on horizontal axis \n";
					cin >> num_of_values;
					double b1[num_of_values];
					string label[num_of_values];
					double intervalh;// double variable to store horizontal gap between 2 bars on x axis
					intervalh = 500 / num_of_values;
					double b2[num_of_values];
					for(int i = 0; i < num_of_values; i ++)
					{
						cout << "Enter label " << i+1 << '\n';
						cin >> label[i];
					}
					for(int i = 0; i < num_of_values; i ++)
					{
						cout << "Enter value " << i+1 << " for Bar 1 " << '\n';
						cin >> b1[i];
						cout << "Enter value " << i+1 << " for Bar 2 " << '\n';
						cin >> b2[i];
					}
					double max;
					max = b1[0];
					for(int i = 0; i < num_of_values-1; i++)
					{
						if(b1[i+1] > max)
						{
							max = b1[i+1];
						}
						if(b2[i+1] > max)
						{
							max = b2[i+1];
						}
					}
					double intervalv;// double variable to store vertical gap between to values on y axis
					intervalv = 500 / max;
					b.bargraph2(title, h_label, v_label, num_of_values, intervalh, intervalv, label, b1, b2);
					break;
				}
				}
}

#endif
