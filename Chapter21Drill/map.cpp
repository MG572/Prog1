//g++ map o- map

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename X, typename Y>
void print(const std::map<X, Y>& map) {

    for (auto const& e : map) {
        std::cout << e.first << endl << e.second << endl;
    }
}

void read(std::map<string, int>& map) {
    string key;
    int value;
    std::cin >> key >> value;
    map[key] = value;
}

int main() {
    
        std::map<string, int> msi;
        msi["nm"] = 1441;
        msi["dasd"] = 1321;
        msi["xcvxc"] = 7647;
        msi["ad"] = 13;
        msi["gd"] = 47;
        msi["gfsd"] = 1121;
        msi["asdq"] = 6478;
        msi["hfggh"] = 414;
        msi["jhdgjghj"] = 14;
        msi["sqsdqsa"] = 67;
        print(msi);

        //msi.erase(msi.begin(), msi.end()); this is the erase
        msi.clear();

        //ten is way too much for debugging in my irrelevant opinion
        std::cout << endl << "Insert 10 value pairs use space between" << endl;
        for (int i = 0; i < 10; i++)
        {
            read(msi);
        }
        print(msi);
        
        int sum = 0;
        for (const auto& e : msi)
        {
            sum += e.second;
        }
        std::cout << "Integer values sum: " << sum << endl;

        std::map<int, string> mis;
        for (const auto& e : msi)
        {
            mis[e.second] = e.first;
        }
        std::cout << "mis map: " << endl;
        print(mis);

        return 0;
}