/*
    g++ main.cpp -o main
*/
#include "std_lib_facilities.h" //remélem ez még mindig használható

template<typename S>
void out(const S& s, const string& label)
{
    cout << label;
    for (auto& i : s)
    {
        cout << i << ' ';
    }
    cout << endl;
}

template<typename S>
void add(S& s, int n = 1)
{
    for (auto& i : s)
    {
        i += n;
    }
}

template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while(f1!=e1)
    {
        *f2=*f1;
        ++f1;
        ++f2;
    }
    return f2;
}


int main()
{
    constexpr int size = 10;
    int numbers[size]={0,1,2,3,4,5,6,7,8,9}; //itt hogy csak másolni kelljen

    cout << endl;//csak hogy szebb legyen

    cout<< "Initialization (using default copy)"<< endl;;
    array<int, size> ai;
    copy(numbers, numbers + size, ai.begin()); //standard copy
    out(ai, "Array: ");

    vector<int> vi(size);
    copy(numbers, numbers + size, vi.begin());
    out(vi, "Vector: ");

    list<int> li(size);
    copy(numbers, numbers + size, li.begin());
    out(li, "List: ");
    cout << endl;

    cout << "Writing out the second versions"<< endl;;
    array<int, size> ai2 = ai; //fapados copy
    vector<int> vi2 = vi;
    list<int> li2 = li;
    out(ai2, "Array2: ");
    out(vi2, "Vector2: ");
    out(li2, "List2: ");
    cout << endl;

    cout << "Additions" << endl;;
    add(ai2, 2);
    add(vi2, 3);
    add(li2, 5);
    out(ai2, "Array: ");
    out(vi2, "Vector: ");
    out(li2, "List: ");
    cout << endl;

    cout << "Using own copy"<<endl;
    copy2(ai2.begin(), ai2.end(), vi2.begin());
    copy2(li2.begin(), li2.end(), ai2.begin());
    out(ai2, "Array: ");
    out(vi2, "Vector: ");
    out(li2, "List: ");
    cout << endl;

    cout<< "Search" << endl;
    cout<<"Searching for 3: ";
    vector<int>::iterator vit;
    vit = find(vi2.begin(), vi2.end(), 3);
    if (vit != vi2.end())
        cout << "Found! Index: " << distance(vi2.begin(), vit) << endl;
    else
        cout << "Not found!"<< endl;

    cout << "Searching for 27: ";
    list<int>::iterator lit;
    lit = find(li2.begin(), li2.end(), 27);
    
    if (lit != li2.end())
        cout << "Found! Index: " << distance(li2.begin(), lit) << endl;
    else
        cout << "Not found!"<< endl;

    return 0;
}