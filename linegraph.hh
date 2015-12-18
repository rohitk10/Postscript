#ifndef _LINEGRAPH_HH
#define _LINEGRAPH_HH

#include "graph.hh"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LineGraph: public Graph
{
private:
	ofstream line;
 public:
	LineGraph(const char filename[])
	{
		line.open(filename);
    	}

	void linegraph1(string title, string h_label, string v_label, int num_of_variables, double intervalh, double intervalv, string label[], double l1[])
		{
			line << "30 30 moveto \n";
			line<< "550 30 lineto \n";
			line<< "30 30 moveto \n";
			line<< "30 550 lineto \n";
			line<< "stroke \n";
			line<< "/Helvetica findfont \n";
			line<< "40 scalefont setfont \n";
			line<< "200 550 moveto \n";
			line<< "(" << title << ") show \n";
			line<< "/Helvetica findfont \n";
			line<< "15 scalefont setfont \n";
			line<< "250 5 moveto \n";
			line<< "(" << h_label << ") show \n";
			line<< "gsave \n";
			line<< "14 250 moveto \n";
			line<< "90 rotate \n";
			line<< "(" << v_label << ") show \n";
			line<< "grestore \n";
			line<< "/Helvetica findfont \n";
			line<< "8 scalefont \n";
			line<< "setfont \n";

			for(int i = 0; i < num_of_variables; i++)
									{
										line << 30+((i+1)*intervalh) << " 22 moveto \n"
											 << "(" << label[i] << ")" << " show \n";
									}
			line << "30 30 moveto \n";

			for(int i = 0; i < num_of_variables; i++)
									{
										line << 30+((i+1)*intervalh) << " " << l1[i] * intervalv << " lineto \n";
									}


			for(int i = 0; i < num_of_variables; i++)
								    {
								    	line << "gsave \n"
										     << "28 " << (l1[i] * intervalv) + 25<< " moveto \n"
											 << "90 rotate \n"
								    		 << "(" << l1[i] << ") show \n"
											 << "grestore \n";
								    }
			line << "stroke";
		}

	void linegraph2(string title, string hl, string vl, int num_of_variables, double intervalh, double intervalv, string label[], double l1[], double l2[])
		{
			line << "30 30 moveto \n";
			line<< "550 30 lineto \n";
			line<< "30 30 moveto \n";
			line<< "30 550 lineto \n";
			line<< "stroke \n";
			line<< "/Helvetica findfont \n";
			line<< "40 scalefont setfont \n";
			line<< "200 550 moveto \n";
			line<< "(" << title << ") show \n";
			line<< "/Helvetica findfont \n";
			line<< "15 scalefont setfont \n";
			line<< "250 5 moveto \n";
			line<< "(" << h_label << ") show \n";
			line<< "gsave \n";
			line<< "14 250 moveto \n";
			line<< "90 rotate \n";
			line<< "(" << v_label << ") show \n";
			line<< "grestore \n";
			line<< "/Helvetica findfont \n";
			line<< "8 scalefont \n";
			line<< "setfont \n";

			for(int i = 0; i < num_of_variables; i++)
												{
													line << 30+((i+1)*intervalh) << " 22 moveto \n"
														 << "(" << label[i] << ")" << " show \n";
												}

			line << "1 0 0 setrgbcolor \n";
			line << "30 30 moveto \n";
									for(int i = 0; i < num_of_variables; i++)
									{
										line << 30+((i+1)*intervalh) << " " << l1[i] * intervalv << " lineto \n";
									}
									line << "stroke \n";
									line << "0 0 1 setrgbcolor \n";
									line << "30 30 moveto \n";
									for(int i = 0; i < num_of_variables; i++)
									{
										line << 30+((i+1)*intervalh) << " " << l2[i] * intervalv << " lineto \n";
									}
									line << "1 0 0 setrgbcolor \n";
									for(int i = 0; i < num_of_variables; i++)
														    {
																line << "gsave \n"
																     << "28 " << (l1[i] * intervalv) + 25<< " moveto \n"
																	 << "90 rotate \n"
															   		 << "(" << l1[i] << ") show \n"
																	 << "grestore \n";
													   	    }
															line << "0 0 1 setrgbcolor \n";
															for(int i = 0; i < num_of_variables; i++)
															{
																line << "gsave \n"
																     << "28 " << (l2[i] * intervalv) + 25<< " moveto \n"
																	 << "90 rotate \n"
															   		 << "(" << l2[i] << ") show \n"
																	 << "grestore \n";
													   	    }


				line << "stroke";
		}

	void closefile()
							{
								line.close();
							}
};

#endif
