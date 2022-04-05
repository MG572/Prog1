/*
    g++ main.cpp -o main
    
    	1. Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
	2. Define a vector<int> with those ten elements.
	3. Define a list<int> with those ten elements.
	
	4. Define a second array, vector, and list, each initialized as a copy of the first array, vector, and list, respectively.
	5. Increase the value of each element in the array by 2; increase the value of each element in the vector by 3; increase the
	value of each element in the list by 5. FIX THE LIST ONE
	6. Write a simple copy() operation,
	
*/
//template<typename Iter1, typename Iter2>

#include "std_lib_facilities.h"

int main()
{
    int array[10];
    int a=0;
    for(int i=0; i<10; i++)
    {
    	array[i]=a;
    	a++;
    }
    vector<int>v1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int>l1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    int array2[10];
    for(int i=0; i<10; i++)
    {
    	array2[i]=array[i]+2;
    }
    vector<int>v2=v1;
    
    for(int i=0; i<10; i++) //probably not as it was meant to be done?
    {
    v2[i]=i+3;
    }
    list<int>l2=l1;
    
    //parasztdebug begins
    for(int i=0; i<10; i++)
    {
    cout<<array[i]<<endl;
    }
    
    cout<<"Array end" << endl;
    
    for(int i=0; i<10; i++)
    {
    cout<<array2[i]<<endl;
    }
    
    cout<<"Array2 end" << endl;
    for(int i=0; i<10; i++)
    {
    cout<<v1[i]<<endl;
    
    }
    cout<<"V1 end" << endl;
    for(int i=0; i<10; i++)
    {
    cout<<v2[i]<<endl;
    }
    cout<<"v2 end"<< endl;
	
	return 0;
}
