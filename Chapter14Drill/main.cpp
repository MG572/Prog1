/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

    ki kellet kommentelni az f-funkciókat hogy lefusson az egész egy inditáskor, de előtte teljesen megvolt csinálva az első pár feladat is és még
    mindig ottvannak
*/
#include "Simple_window.h"
#include "Graph.h"

class B1 {

public:
//id f() const { cout << "B1::f()"; }
virtual void vf() const { cout << "B1::vf()"; }
virtual void pvf() =0;

};

class B2 {
public:
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:
void vf() const { cout << "overriden"; }
//void f() { cout << "D1::f"}
void pvf() override { cout << "D1::pvf" << endl; }
};

class D2 : public D1 {
public:
	void pvf() override { cout << "D2::pvf" << endl; }
};

class D21 : public B2 {
public:
	string st = "String";
	void pvf() override { cout << st;}
};


class D22 : public B2
{
public:
	int in=25;
	void pvf() override { cout << in;}
	void f(B2& b2Ref) { b2Ref.pvf(); }
};

int main()
{
    using namespace Graph_lib;

    //B1 b1;
	//b1.vf();
	//b1.f();
	cout << endl;
	D1 d1;
	d1.vf();
	//d1.f();
	cout << endl;
	B1& B1Reference = d1; //mivel B1-re reference ezért nem tud semmit a D1-ről és igy B1 f()-ét fogja hivni
	B1Reference.vf();
	//B1Reference.f();
	cout<< endl;
	D2 d2;
	d2.vf();
	d2.pvf();
	//d2.f();
	cout << endl;
	
	D21 d21;
	D22 d22;

	d22.f(d21);
	cout << endl;
	d22.f(d22);
	cout<<endl;


	keep_window_open();
	return 0;

}
