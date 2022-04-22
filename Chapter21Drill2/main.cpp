//g++ main.cpp -o main
//This one had to be labeled it was too big and I didn't use the library always used  
//(I probably should have asked if its even allowed)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>

// 1
struct Item {
    std::string name;
    int iid;
    double value;
};

std::ostream& operator<<(std::ostream& out, const Item& it)
{
    return out << it.name << '\t'
              << it.iid << '\t'
              << it.value;
}

std::istream& operator>>(std::istream& in, Item& it)
{
    std::string ss;
    int ii;
    double dd;
    in >> ss >> ii >> dd;
    Item itt {ss, ii, dd};
    it = itt;
    return in;
}

// 4 (the others were done without this)
struct by_val { 
    bool operator()(const Item& x, const Item& y)
    {
        return x.value > y.value;
    }
};

// 6
class by_name {
    std::string name;
public:
    by_name(const std::string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

// 7
class by_iid {
    int iid;
public:
    by_iid(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};

template<typename T>
void print(const T& t, char br = ' ')
{
    for (const auto& x : t)
        std::cout << x << br;
    std::cout << std::endl;
}

int main()
{
    // 1
    const std::string input {"input.txt"};

    std::ifstream ifs {input};

    std::vector<Item> vi;
    for (Item ii; ifs >> ii; )
        vi.push_back(ii);

    // 2
    std::sort(vi.begin(), vi.end(),
            [](const Item& x, const Item& y) { return x.name < y.name; });

    // 3
    std::sort(vi.begin(), vi.end(),
            [](const Item& x, const Item& y) { return x.iid < y.iid; });

    // 4
    std::sort(vi.begin(), vi.end(), by_val());

    // 5. does not say where to put it so i will use push back
    Item tmp {"horse shoe", 99, 1.34};
    vi.push_back (tmp);

    tmp = Item{"canon S400", 9988, 499.95};
    vi.push_back(tmp);

    // 6
    vi.erase(std::find_if(vi.begin(),vi.end(),by_name("water")));
    vi.erase(std::find_if(vi.begin(),vi.end(),by_name("chair")));

    // 7
    vi.erase(std::find_if(vi.begin(),vi.end(),by_iid(91)));
    vi.erase(std::find_if(vi.begin(),vi.end(),by_iid(21)));

    // 8
    std::list<Item> l (vi.size());
    std::copy(vi.begin(), vi.end(), l.begin());

    print(l, '\n');

    l.sort([](const Item& x, const Item& y) { return x.name < y.name; });
    l.sort([](const Item& x, const Item& y) { return x.iid < y.iid; });
    l.sort([](const Item& x, const Item& y) { return x.value > y.value; });

    tmp = {"horse", 99, 1.34};
    l.push_back (tmp);

    tmp = {"canon", 9988, 499.95};
    l.push_back (tmp);

    l.erase(std::find_if(l.begin(), l.end(), by_name("ship")));
    l.erase(std::find_if(l.begin(), l.end(), by_name("phone")));
    l.erase(std::find_if(l.begin(), l.end(), by_iid(25)));
    l.erase(std::find_if(l.begin(), l.end(), by_iid(91)));

    print(l, '\n');

    return 0;
}