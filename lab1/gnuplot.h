#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <cstdio>
#include <string>
#include <iostream>

#ifdef WIN32
	#define GNUPLOT_NAME "pgnuplot -persist"
#else
	#define GNUPLOT_NAME "gnuplot -persist"
#endif

using std::string;
using std::cerr;

class Gnuplot
{
public:
	Gnuplot() ;
	~Gnuplot();

	void initF(const std::string ttl, const std::string lbl1, const std::string lbl2);
	void initf(const std::string ttl, const std::string lbl1, const std::string lbl2);

	void operator()(const string &command);
	void operator()(const double x, const double y);

protected:
	FILE *gnuplotpipe;
};

#endif