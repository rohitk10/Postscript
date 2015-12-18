#ifndef _LINEGRAPHINPUT_HH
#define _LINEGRAPHINPUT_HH

#include "LineGraph.hh"

#include <iostream>
using namespace std;

void line_input()
{
	LineGraph l("linegraph.ps");
	string title, h_label, v_label;
	int num_of_values,num_of_variables;
	cout << "Enter Graph Title \n";
	cin >> title;
	cout << "Enter Horizontal axis label and Vertical axis label \n";
	cin >> h_label;
	cin >> v_label;
	cout << "Enter number of lines (1 or 2) \n";
	cin >> num_of_variables;
	
	switch(num_of_variables)
	{
		case 1 :
		{
			cout << "Enter number of values on horizontal axis \n";
			cin >> num_of_values;
			double l1[num_of_values];
			string label[num_of_values];
			double intervalh;
			intervalh = 500 / num_of_values;
			for(int i = 0; i < num_of_values; i ++)
			{
				cout << "Enter label " << i+1 << '\n';
				cin >> label[i];
				cout << "Enter value " << i+1 << '\n';
				cin >> l1[i];
			}
			double max;
			max = l1[0];
			for(int i = 0; i < num_of_values-1; i++)
			{
			if(l1[i+1] > max)
				{
					max = l1[i+1];
				}
			}
			double intervalv;
			intervalv = 500/max;
			l.linegraph1(title, h_label, v_label, num_of_values, intervalh, intervalv, label, l1);
			break;
			}

		case 2 :
		{
			cout << "Enter number of values on horizontal axis \n";
			cin >> num_of_values;
			double l1[num_of_values];
			string label[num_of_values];
			double intervalh;
			intervalh = 500 / num_of_values;
			double l2[num_of_values];
			for(int i = 0; i < num_of_values; i ++)
			{
				cout << "Enter label " << i+1 << '\n';
				cin >> label[i];
			}
			for(int i = 0; i < num_of_values; i ++)
			{
				cout << "Enter value " << i+1 << " for Bar 1 " << '\n';
				cin >> l1[i];
				cout << "Enter value " << i+1 << " for Bar 2 " << '\n';
				cin >> l2[i];
			}
			double max;
			max = l1[0];
			for(int i = 0; i < num_of_values-1; i++)
			{
				if(l1[i+1] > max)
				{
					max = l1[i+1];
				}
				if(l2[i+1] > max)
				{
					max = l2[i+1];
				}
			}
			double intervalv;
			intervalv = 500 / max;
			l.linegraph2(title, h_label, v_label, num_of_values, intervalh, intervalv, label, l1, l2);
			break;
		}
	}
}

#endif
