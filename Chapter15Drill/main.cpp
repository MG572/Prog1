/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main()
{
    using namespace Graph_lib;
    	
    	constexpr int xmax = 600;
	constexpr int ymax = 600;
	
	constexpr int x_orig = xmax/2;
	constexpr int y_orig = ymax/2;
	const Point orig {x_orig,y_orig};  //whats wrong with you
	
	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int n_points = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	
	Simple_window win {Point{100,100},xmax,ymax,"Function graphing"};

	Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s4 {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
	
	Text text1 {Point{100,390},"x/2"};
	
	constexpr int xlength = 400;
	constexpr int ylength = 400;
	
	Axis x {Axis::x,Point{20,y_orig},
	xlength, x_scale, "one notch == 1"};
	Axis y {Axis::y,Point{x_orig, ylength+20},
	ylength, y_scale, "one notch == 1"};
	
    	y.set_color(Color::red);
    	x.set_color(Color::red);
    	
    	win.attach(x);
    	win.attach(y);
	win.attach(s);
	win.attach(s2);
	win.attach(text1);
	win.attach(s3);
	win.attach(s4);
	
    win.wait_for_button();

}
