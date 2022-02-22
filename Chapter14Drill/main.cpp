//#include "Simple_window.h"
//#include "Graph.h"
#include <iostream>

struct B1 {

public:
void f() const { std::cout << "B1::f()"; }
virtual void vf() const { std::cout << "B1::vf()"; }

};

struct D1 : B1 {
void vf() const { std::cout << "overriden"; }
};

int main()
{

	

	//B1.f();
	//B1.vf();
    //using namespace Graph_lib;
    
    //win.wait_for_button();

}
