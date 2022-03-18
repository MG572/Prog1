/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using Graph_lib::Font;

double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double cosi(double x){return cos(x)+slope(x);}


int main(){

     using namespace Graph_lib;

    int maxx = 600;
    int maxy = 600;

    Point tl(600,50);
    Simple_window win(tl,maxx,maxy,"Function graphs"); //even if I keep renaming it, it changes to something horrible upon pressing next
    

    int origox = 300;
    int origoy = 300;
    
    Point origo(origox,origoy);

    int rangemin = -10;
    int rangemax = 11;

    int n_points = 400;

    int scalex = 20;
    int scaley = 20;

    int xlength = maxx - 200;
    int ylength = maxy - 200;

    Axis xaxis(Axis::x,Point(100,origoy),xlength,xlength/scalex,"1 == 20 pixels");
    xaxis.set_color(Color::red);
    
    win.attach(xaxis);
    Axis yaxis(Axis::y,Point(origox,500),ylength,ylength/scaley,"1 == 20 pixels");
    yaxis.set_color(Color::red);
    
    win.attach(yaxis);
    win.wait_for_button();

    Function lin(one,rangemin,rangemax,origo,n_points,scalex,scaley);
    
    win.attach(lin);
    win.wait_for_button();

    Function slop(slope,rangemin,rangemax,origo,n_points,scalex,scaley);
    Text text1 {Point{100,390},"x/2"};
    
    win.attach(slop);
    win.attach(text1);
    win.wait_for_button();

    Function para(square,rangemin,rangemax,origo,n_points,scalex,scaley);
    
    win.attach(para);
    win.wait_for_button();

    Function cosinus(cos,rangemin,rangemax,origo,n_points,scalex,scaley);
    cosinus.set_color(Color::blue);
    
    win.attach(cosinus);
    win.wait_for_button();

    Function sloping_cos(cosi,rangemin,rangemax,origo,n_points,scalex,scaley);
    
    win.attach(sloping_cos);
    win.wait_for_button();
}