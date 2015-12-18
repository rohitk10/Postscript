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
	void bargraph1(string title, string h_label, string v_label, int num_of_variables, double intervalh, double intervalv, string label[], double b1[])
	{
		bar << "30 30 moveto \n"
		bar << "550 30 lineto \n"
		bar << "30 30 moveto \n"
		bar << "30 550 lineto \n"
		bar << "stroke \n"
		bar << "/Helvetica findfont \n"
		bar << "40 scalefont setfont \n"
		bar << "200 550 moveto \n"
		bar << "(" << title << ") show \n"
		bar << "/Helvetica findfont \n"
		bar << "15 scalefont setfont \n"
		bar << "250 5 moveto \n"
		bar << "(" << h_label << ") show \n"
		bar << "gsave \n"
		bar << "14 250 moveto \n"
		bar << "90 rotate \n"
		bar << "(" << v_label << ") show \n"
		bar << "grestore \n"
		bar << "/Helvetica findfont \n"
		bar << "8 scalefont setfont \n";
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << 30+((i+1)*intervalh) << " 22 moveto \n"
			 << "(" << label[i] << ")" << " show \n";
		}
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << 30+((i+1)*intervalh) << " 30 5 " << b1[i] * intervalv << " rectfill \n";
		}
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << "gsave \n"
			bar << "28 " << (b1[i] * intervalv) + 25<< " moveto \n"
			bar << "90 rotate \n"
			bar << "(" << b1[i] << ") show \n"
			bar << "grestore \n";
		    }
		}

		void bargraph2(string title, string hl, string vl, int num_of_variables, double intervalh, double intervalv, string label[], double b1[], double b2[])
		{
		bar << "30 30 moveto \n"
		bar << "550 30 lineto \n"
		bar << "30 30 moveto \n"
		bar << "30 550 lineto \n"
		bar << "stroke \n"
		bar << "/Helvetica findfont \n"
		bar << "40 scalefont setfont \n"
		bar << "200 550 moveto \n"
		bar << "(" << title << ") show \n"
		bar << "/Helvetica findfont \n"
		bar << "15 scalefont setfont \n"
		bar << "250 5 moveto \n"
		bar << "(" << hl << ") show \n"
		bar << "gsave \n"
		bar << "14 250 moveto \n"
		bar << "90 rotate \n"
		bar << "(" << vl << ") show \n"
		bar << "grestore \n"
		bar << "/Helvetica findfont \n"
		bar << "8 scalefont setfont \n";
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << 30+((i+1)*intervalh) << " 22 moveto \n"
			bar << "(" << label[i] << ")" << " show \n";
		}
		bar << "1 0 0 setrgbcolor \n";
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << 30+((i+1)*intervalh) << " 30 5 " << b1[i] * intervalv << " rectfill \n";
		}
		bar << "0 0 1 setrgbcolor \n";
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << 30+((i+1)*intervalh) + 5 << " 30 5 " << b2[i] * intervalv << " rectfill \n";
		}
		bar << "1 0 0 setrgbcolor \n";
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << "gsave \n"
			bar << "28 " << (b1[i] * intervalv) + 25<< " moveto \n"
			bar << "90 rotate \n"
			bar << "(" << b1[i] << ") show \n"
			bar << "grestore \n";
	  	}
		bar << "0 0 1 setrgbcolor \n";
		for(int i = 0; i < num_of_variables; i++)
		{
			bar << "gsave \n"
			bar << "28 " << (b2[i] * intervalv) + 25<< " moveto \n"
			bar << "90 rotate \n"
			bar << "(" << b2[i] << ") show \n"
			bar << "grestore \n";
		}
	}

	void closefile()
	{
		bar.close();
	}
};

#endif
