/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
    
    ez most teljes mértékben irreleváns információ, de a virtual machine tárhelye betelt a drill készitése közben az utolsó három sornál,
    a fájl korruptálódott annak rendje szerint, teljesen menthetetlen volt a merevlemez tisztitása után is, a virtuális gép meg brickelte magát.
    Én meg azthittem fölakasztom magamat mert írhattam újra az egészet éjfélkor, miután újraraktam a virtual machine-t és felraktam az fltkt
    és ezért került fel ilyen későn és sírógörcsöt kapok, ez szörnyű és elnézést de ezt muszáj vagyok itthagyni

*/

#include "Simple_window.h"
#include "Graph.h"

int main ()
try
{
    Point tl {100,100};              
	Simple_window win {tl,600,400,"My window"};
	

	Axis xaxis {Axis::x, Point{20,350}, 280, 10, "x axis"}; 
	Axis yaxis {Axis::y, Point{20,350}, 280, 10, "y axis"};

	Function sine {sin,0,100,Point{20,150},1000,50,50};
	

	yaxis.set_color(Color::yellow);                       
	yaxis.label.set_color(Color::dark_blue);
    
    sine.set_color(Color::red);    

	Polygon polygon;                              
	polygon.add(Point{300,200});          
	polygon.add(Point{350,100});
	polygon.add(Point{400,200});

	Rectangle rectangle {Point{200,200}, 150, 100}; 

	Closed_polyline fake_rect;
	fake_rect.add(Point{125,75});
	fake_rect.add(Point{225,75});
	fake_rect.add(Point{225,125});
	fake_rect.add(Point{125,125});
	fake_rect.add(Point{75,100});

	Text text {Point{20,200}, "Hello, graphical world!"};

	text.set_font(Font::times_bold); //müködik de eddig még soha nem müködött ez a sor szóval félek
	text.set_font_size(10);

	Image image {Point{280,230},"cat.jpg"};
	//image.move(20,20); //core dump?
	
	polygon.set_color(Color::magenta);
	polygon.set_style(Line_style::dash);
	rectangle.set_fill_color(Color::blue);
	polygon.set_style(Line_style(Line_style::dash,6));
	fake_rect.set_style(Line_style(Line_style::dash,4));
	fake_rect.set_fill_color(Color::red);
	
	win.attach(xaxis);
	win.attach(yaxis);
	win.attach(sine);
	win.attach(polygon);
	win.attach(rectangle);
	win.attach(fake_rect);
	win.attach(text);
	win.attach(image);

	Circle circle {Point{100,300},20};	//ezek a sorok brickelték az elöző iterációt és nem is biztos hogy kellenek
	Ellipse ellipse {Point{200,200}, 60,15};
	ellipse.set_color(Color::dark_red);
	Mark mark {Point{350,350},'x'};

	win.attach(circle);
	win.attach(ellipse);
	win.attach(mark);

	win.set_label("My window"); //ideírtam az egyiket a teljesség kedvéért  

	win.wait_for_button();  
}
catch(exception& e) {
         
          return 1;
}
catch(...) {
          
          return 2;
}