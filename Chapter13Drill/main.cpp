/*

	SZÁNDÉKOSAN ZÁRÓDIK BE 5 NEXT UTÁN HOGY NE KELLJEN KONZOLLAL KILÉPNI, remélem ez nem nagy baj mostmár nem törlöm ki hogy megcsináltam, a break-et
	commentelve nem fog bezáródni, meg van csinálva hogy a végtelenségig menjen

    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {tl,xmax,ymax,"My window"};

    int x_size = 801;
	int y_size = 801;
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
	grid.add(Point{x,0},Point{x,y_size});
	for (int y = y_grid; y<y_size; y+=y_grid)
	grid.add(Point{0,y},Point{x_size,y});

	//Despair ahead
	Rectangle rect1 {Point{0,0},100,100};
	Rectangle rect2 {Point{100,100},100,100};
	Rectangle rect3 {Point{200,200},100,100};
	Rectangle rect4 {Point{300,300},100,100};
	Rectangle rect5 {Point{400,400},100,100};
	Rectangle rect6 {Point{500,500},100,100};
	Rectangle rect7 {Point{600,600},100,100};
	Rectangle rect8 {Point{700,700},100,100};

	rect1.set_fill_color(Color::red);
	rect1.set_color(Color::invisible);
	rect2.set_fill_color(Color::red);
	rect2.set_color(Color::invisible);
	rect3.set_fill_color(Color::red);
	rect3.set_color(Color::invisible);
	rect4.set_fill_color(Color::red);
	rect4.set_color(Color::invisible);
	rect5.set_fill_color(Color::red);
	rect5.set_color(Color::invisible);
	rect6.set_fill_color(Color::red);
	rect6.set_color(Color::invisible);
	rect7.set_fill_color(Color::red);
	rect7.set_color(Color::invisible);
	rect8.set_fill_color(Color::red);
	rect8.set_color(Color::invisible);

	Image bonfire1{Point{200,0},"bonfire.gif"}; //I'm so incredibly dissapointed that the animation doesn't actually work
	Image bonfire2{Point{0,200},"bonfire.gif"};
	Image bonfire3{Point{0,500},"bonfire.gif"};
	Image bonfire4{Point{500,0},"bonfire.gif"};

	

	win.attach(grid);
	win.attach(rect1);
	win.attach(rect2);
	win.attach(rect3);
	win.attach(rect4);
	win.attach(rect5);
	win.attach(rect6);
	win.attach(rect7);
	win.attach(rect8);
	win.attach(bonfire1);
	win.attach(bonfire2);
	win.attach(bonfire3);
	win.attach(bonfire4);

	int current=0;
	int max = 6; //after 5 "Next" clicks the program terminates so the poor user doesn't get stuck, it's intentional
	
	int random = (rand()%8)*100, random2 = (rand()%8)*100;
	
	while (random==700 && random2==100) //if these are the coordinates then the next button becomes unclickable and the user gets stuck
	{random = (rand()%8)*100, random2 = (rand()%8)*100;} //so I do a new random if it happens
	
	while(true){
		
		Image cat{Point{random,random2},"cat.gif"};
		
		random=(rand()%8)*100, random2= (rand()%8)*100;
		
		while (random==700 && random2==100) //same as before these coordinates would be a problem
		{random = (rand()%8)*100, random2 = (rand()%8)*100;}
		
		win.attach(cat);
		
		current++;
		if (current==max) //No one said I have to do this but I think it can't be a problem, just some extra effort
			break; //if it is a problem if this is commented it works perfectly
		
		win.wait_for_button();
	}

    win.wait_for_button();

}
