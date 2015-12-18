#ifndef _BARGRAPH_HH
#define _BARGRAPH_HH

#include "graph.hh"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BarGraph: public Graph
{
private:

	ofstream bar;

 public:

	BarGraph(const char filename[])
	{
		bar.open(filename);
        }
        
        //this function prints a bar graph containing one variable using postscript command

	void bargraph1(string title, string h_label, string v_label, int num_of_variables, double intervalh, double intervalv, string label[], double b1[])
	{
	                                             bar << "30 30 moveto \n"
	    	                                         << "550 30 lineto \n"
			                                 << "30 30 moveto \n"
			                                 << "30 550 lineto \n"
							 << "stroke \n"
							 << "/Helvetica findfont \n"
							 << "40 scalefont setfont \n"
							 << "200 550 moveto \n"
							 << "(" << title << ") show \n"
							 << "/Helvetica findfont \n"
							 << "15 scalefont setfont \n"
							 << "250 5 moveto \n"
							 << "(" << h_label << ") show \n"
							 << "gsave \n"
							 << "14 250 moveto \n"
							 << "90 rotate \n"
							 << "(" << v_label << ") show \n"
							 << "grestore \n"
						     << "/Helvetica findfont \n"
							 << "8 scalefont setfont \n";
							 
							 // for loop to display labels on the x-axis
							 
						for(int i = 0; i < num_of_variables; i++)
						{
							bar << 30+((i+1)*intervalh) << " 22 moveto \n"
								 << "(" << label[i] << ")" << " show \n";
						}
						
						// for loop to display n number of bars
						
						for(int i = 0; i < num_of_variables; i++)
						{
							bar << 30+((i+1)*intervalh) << " 30 5 " << b1[i] * intervalv << " rectfill \n";
						}
						
						// for loop to display corresponding values on y-axis
						
					    for(int i = 0; i < num_of_variables; i++)
					    {
					    	bar << "gsave \n"
							     << "28 " << (b1[i] * intervalv) + 25<< " moveto \n"
								 << "90 rotate \n"
					    		 << "(" << b1[i] << ") show \n"
								 << "grestore \n";
					    }

					}

					void bargraph2(string title, string hl, string vl, int num_of_variables, double intervalh, double intervalv, string label[], double b1[], double b2[])
					{
						
						//this function prints a bargraph containing 2 variables using postscript commands
						
						bar << "30 30 moveto \n"
							 << "550 30 lineto \n"
							 << "30 30 moveto \n"
							 << "30 550 lineto \n"
							 << "stroke \n"
							 << "/Helvetica findfont \n"
							 << "40 scalefont setfont \n"
							 << "200 550 moveto \n"
							 << "(" << title << ") show \n"
							 << "/Helvetica findfont \n"
							 << "15 scalefont setfont \n"
							 << "250 5 moveto \n"
							 << "(" << hl << ") show \n"
							 << "gsave \n"
							 << "14 250 moveto \n"
							 << "90 rotate \n"
							 << "(" << vl << ") show \n"
							 << "grestore \n"
						     << "/Helvetica findfont \n"
							 << "8 scalefont setfont \n";
							 
							 // for loop to display labels on x axis
							 
						for(int i = 0; i < num_of_variables; i++)
						{
							bar << 30+((i+1)*intervalh) << " 22 moveto \n"
								 << "(" << label[i] << ")" << " show \n";
						}
						
						// setting the bar color to red
						
						bar << "1 0 0 setrgbcolor \n";
						
						// for loop to draw first bar
						
						for(int i = 0; i < num_of_variables; i++)
						{
							bar << 30+((i+1)*intervalh) << " 30 5 " << b1[i] * intervalv << " rectfill \n";
						}
						
						//setting the bar color to blue
						
						bar << "0 0 1 setrgbcolor \n";
						
						//for loop to draw the second bar

						for(int i = 0; i < num_of_variables; i++)
						{
							bar << 30+((i+1)*intervalh) + 5 << " 30 5 " << b2[i] * intervalv << " rectfill \n";
						}
						
						// for loop to display corresponding values on y axis
						
						bar << "1 0 0 setrgbcolor \n";
						for(int i = 0; i < num_of_variables; i++)
					    {
							bar << "gsave \n"
							     << "28 " << (b1[i] * intervalv) + 25<< " moveto \n"
								 << "90 rotate \n"
						   		 << "(" << b1[i] << ") show \n"
								 << "grestore \n";
				   	    }
						bar << "0 0 1 setrgbcolor \n";
						for(int i = 0; i < num_of_variables; i++)
						{
							bar << "gsave \n"
							     << "28 " << (b2[i] * intervalv) + 25<< " moveto \n"
								 << "90 rotate \n"
						   		 << "(" << b2[i] << ") show \n"
								 << "grestore \n";
				   	    }

					}

					void closefile()
						{
							bar.close();
						}
};

#endif
