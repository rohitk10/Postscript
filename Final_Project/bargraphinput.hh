#ifndef _BARGRAPHINPUT_HH
#define _BARGRAPHINPUT_HH

#include "BarGraph.hh"

#include <iostream>
using namespace std;

void bar_input()
{
	BarGraph b("bargraph.ps");
	string title, h_label, v_label;
	int num_of_values,num_of_variables;
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
			double intervalh;
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
			double intervalv;
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
			double intervalh;
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
			double intervalv;
			intervalv = 500 / max;
			b.bargraph2(title, h_label, v_label, num_of_values, intervalh, intervalv, label, b1, b2);
			break;
		}
	}
}

#endif
