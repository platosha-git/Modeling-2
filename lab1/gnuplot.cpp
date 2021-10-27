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

void Gnuplot::initF(const string ttl, const string lbl1, const string lbl2)
{
	string title = "set title '" + ttl + "'";
	fprintf(gnuplotpipe, "%s\n", title.c_str());

	string label1 = "set label '" + lbl1 + "' at 3,0.1";
	fprintf(gnuplotpipe, "%s\n", label1.c_str());

	string label2 = "set label '" + lbl2 + "' at 3,0";
	fprintf(gnuplotpipe, "%s\n", label2.c_str());

	fprintf(gnuplotpipe, "set xlabel 'x'\n");
	fprintf(gnuplotpipe, "set ylabel 'F(x)'\n");

	fprintf(gnuplotpipe, "set grid\n");
	fprintf(gnuplotpipe, "set yrange [-0.1:1.1]\n");    

	fprintf(gnuplotpipe, "plot '-' using 1:2 notitle with lines\n");
	
	fflush(gnuplotpipe);
}

void Gnuplot::initF(const string ttl, const string lbl)
{
	string title = "set title '" + ttl + "'";
	fprintf(gnuplotpipe, "%s\n", title.c_str());

	string label = "set label '" + lbl + "' at 16,0.1";
	fprintf(gnuplotpipe, "%s\n", label.c_str());

	fprintf(gnuplotpipe, "set xlabel 'x'\n");
	fprintf(gnuplotpipe, "set ylabel 'F(x)'\n");

	fprintf(gnuplotpipe, "set grid\n");
	fprintf(gnuplotpipe, "set yrange [-0.1:1.1]\n");    

	fprintf(gnuplotpipe, "plot '-' using 1:2 notitle pt 7 ps 0.5\n");
	
	fflush(gnuplotpipe);
}

void Gnuplot::initf(const string ttl, const string lbl1, const string lbl2)
{
	string title = "set title '" + ttl + "'";
	fprintf(gnuplotpipe, "%s\n", title.c_str());

	string label1 = "set label '" + lbl1 + "' at 3,1";
	fprintf(gnuplotpipe, "%s\n", label1.c_str());

	string label2 = "set label '" + lbl2 + "' at 3,0.9";
	fprintf(gnuplotpipe, "%s\n", label2.c_str());

	fprintf(gnuplotpipe, "set xlabel 'x'\n");
	fprintf(gnuplotpipe, "set ylabel 'f(x)'\n");

	fprintf(gnuplotpipe, "set grid\n");
	fprintf(gnuplotpipe, "set yrange [-0.1:1.1]\n");    
	
	fprintf(gnuplotpipe, "plot '-' using 1:2 notitle with lines\n");
	
	fflush(gnuplotpipe);
}

void Gnuplot::initf(const string ttl, const string lbl)
{
	string title = "set title '" + ttl + "'";
	fprintf(gnuplotpipe, "%s\n", title.c_str());

	string label = "set label '" + lbl + "' at 16,1";
	fprintf(gnuplotpipe, "%s\n", label.c_str());

	fprintf(gnuplotpipe, "set xlabel 'x'\n");
	fprintf(gnuplotpipe, "set ylabel 'f(x)'\n");

	fprintf(gnuplotpipe, "set grid\n");
	fprintf(gnuplotpipe, "set yrange [-0.1:1.1]\n");    
	
	fprintf(gnuplotpipe, "plot '-' using 1:2 notitle pt 7 ps 0.5\n");
	
	fflush(gnuplotpipe);
}