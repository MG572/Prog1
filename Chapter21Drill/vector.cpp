//g++ vector.cpp -o vector

#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <algorithm>

class Less_than {
    double v;
public:
    Less_than(double vv) : v{vv} { }

    bool operator()(const double val) { return val < v; }
};

template<typename T> void print(const T& t, char br = '\n') //endl doesnt work here? :(
{
    std::cout << "Elements: "<< std::endl;

    for (const auto ele : t)
        std::cout << ele << br;

    std::cout << std::endl;
}

int main()
{
    const std::string input {"input1.txt"};
    std::ifstream ifs {input};
    std::vector<double> vd;
    for (double x; ifs >> x; )
    {
        vd.push_back(x);
    }
    print(vd);

    std::vector<int> vi (vd.size());
    std::copy(vd.begin(), vd.end(), vi.begin());

    for (int i = 0; i < vd.size(); ++i)
    {
        std::cout << vd[i] << " " << vi[i] << std::endl;
    }

    // 5
    double sumofvd = std::accumulate(vd.begin(), vd.end(), 0.0);
    std::cout << "Sum of Vector: " << sumofvd << std::endl;

    // 6
    double difference =
        std::inner_product(vd.begin(), vd.end(),
            vi.begin(),0.0,std::plus<double>(),std::minus<double>());
    std::cout << "Difference of sums: " << difference << std::endl;

    // 7
    std::reverse(vd.begin(), vd.end());
    print(vd);

    // 8. Compute the mean value of vd and output it
    double meanvd = sumofvd / vd.size();

    std::cout << "The mean of vd is: " << meanvd << '\n';

    // 9.
    std::vector<double> vd2 (vd.size());

    auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(),
            Less_than(meanvd));
    vd2.resize(std::distance(vd2.begin(), it));
    print(vd2);

    // 10
    std::sort(vd.begin(), vd.end());
    print(vd);

    return 0;
}