/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "GUI.h"
#include "Lines_window.h"

using namespace Graph_lib;

int main()
{
	try {
	Lines_window win {Point{100,100},600,400,"lines"};
	return gui_main();
}
	catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
	catch (...) {
	cerr << "Some exception\n";
	return 2;
}

}
