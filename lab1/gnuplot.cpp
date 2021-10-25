#include "gnuplot.h"

Gnuplot::Gnuplot()
{
	#ifdef WIN32
		gnuplotpipe = _popen(GNUPLOT_NAME, "w");
	#else
		gnuplotpipe  = popen(GNUPLOT_NAME, "w");
	#endif

	if (!gnuplotpipe) {
		cerr << ("Gnuplot not found!");
	}
}

Gnuplot::~Gnuplot()
{
	fprintf(gnuplotpipe,"exit\n");

	#ifdef WIN32
	   _pclose(gnuplotpipe);
	#else
		pclose(gnuplotpipe);
	#endif
}

void Gnuplot::operator()(const string &command)
{
	fprintf(gnuplotpipe, "%s\n", command.c_str());
	fflush(gnuplotpipe);
}

void Gnuplot::operator()(const double x, const double y)
{
	fprintf(gnuplotpipe, "%f\t%f\n", x, y);
	fflush(gnuplotpipe);
}