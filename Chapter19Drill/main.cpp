/*
    g++ main.cpp -o main

    Remélem az std_lib_facilities még mindig használható
*/
#include "std_lib_facilities.h"

template<typename T> 

struct S 
{  
	S(T t): val(t) {}

	T& get();
	T& read_val();

	void set (T t) {val = t;}
	
	const T& get() const {return val;}

	private:
		T val;
};

template<typename T> //its outside the class
T& S<T>::get(){
	return val; //it returns val
}

template<typename T> 
void read_val(T& v)
{
	cin >> v;
}

int main()
{
    using namespace std;

    S<int> si {2};
    cout << "The integer: "<<endl;
    cout << si.get()<<endl;

    S<char> sc {'g'};
    cout << "The character: "<<endl;
    cout << sc.get()<<endl;

    S<double> sd {5.2};
    cout << "The double: "<<endl;
    cout << sd.get()<<endl;

    S<string> st {"idk"};
    cout << "The string: " << endl;
    cout << st.get()<<endl;

    S<vector<int>> svi {{5,15,25,40,50,80,120}};
    cout << "The vector: " << endl;
    for (auto& value: svi.get())
    {
    	cout << value << ' ';
    }
    cout << endl;

    st.set("Does it actually work?"); //it does
    cout << "Changed string with set: " << st.get()<<endl;

    cout << endl;
    cout << "Input part begins" <<endl;
    cout << endl;

    int inputinteger;
    cout << "Input a new integer: " << endl;
    read_val(inputinteger);
    si=inputinteger;

    char inputcharacter;
    cout << "Input a new character: " << endl;
    read_val(inputcharacter);
    sc=inputcharacter;

    double inputdouble;
    cout << "Input a new double: " << endl;
    read_val(inputdouble);
    sd=inputdouble;

    string inputstring;
    cout << "Input a new string: (no spaces)" << endl;
    read_val(inputstring);
    st=inputstring;

    cout << endl;
    cout << "Writing out input:" << endl;
    cout << "The integer: "<<endl;
    cout << si.get()<<endl;
    cout << "The character: "<<endl;
    cout << sc.get()<<endl;
    cout << "The double: "<<endl;
    cout << sd.get()<<endl;
	cout << "The string: "<< endl;
    cout << st.get()<<endl;

    return 0;

}