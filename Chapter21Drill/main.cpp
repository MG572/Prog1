/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

    
*/
#include "Graph.h"

struct Item { 
	string name; 
	int iid;
	double value;
	};
/* this made everything even worse.
struct name 
{
	bool operator()(const string & x, const string & y) const t
	{
		for (int i =0; i<x.length(); i++)
		{
.
		}
	}
};
*/
struct iid {

	};

struct value {

	};

int main()
{

    using namespace Graph_lib;

	string from;
	cin >> from;
	ifstream is {from};
	istream_iterator<Item> ii {is};
    Vector<Item> vi {ii};
    
    void sort(Vector <Item> & vi) 
    {
    	sort(vi.begin(),vi.end());
    }

    //WIP doesn't say insert into where so I'm going to assume that its the end of the vector
    iterator p = vi.begin(); 
    for (int i=0; i <vi.lenght(); i++)
    	{
    		p++;
    	}
    p=vi.insert(p,Item("horse shoe",99,12.34));

    //WIP same here so the vector is 12 now
    iterator p2 = vi.begin();

    for (int i=0; i <vi.lenght(); i++)
    	{
    		p2++;
    	}

    p2=vi.insert(p2,ItemItem("Canon S400", 9988,499.95));

    return 0;
}
