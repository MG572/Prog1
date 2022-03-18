/*
    g++ classdef.cpp -o classdef
*/
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

struct Person{
    public:

        Person(){};
        
        Person(string f, string l, int a) : f{f}, l{l}, a{a}{
            if (a < 0 || 150 <=a)
            {
                throw runtime_error ("Error! Invalid age!");
            }
            string name = f + l;
            for (int i = 0; i < name.length(); ++i)
            {
                if (name[i] == ';' || name[i] == ':' || name[i] == '"' || name[i] == '[' || name[i] == 96 || name[i] == ']' 
                    || name[i] == '*' || name[i] == '&' || name[i] =='^' || name[i] == '%' || name[i] == '$'|| name[i] == '#' 
                    || name[i] == '@' || name[i] == '!')
                {
                    throw runtime_error ("Error! Invalid name!");
                }
            }
        };
        
        string first_name() const{
            return f;
        }
        string last_name() const{
            return l;
        }
        int age() const{
            return a;
        }
    
    private:

        string f;
        string l;
        int a;
};

ostream& operator<< (ostream& os, const Person& p){return os << p.first_name() << " " << p.last_name() << " " << p.age();}

istream& operator>> (istream& in, Person& p){
    string f;
    string l;
    int a;
    in >> f >> l >> a;
    p=Person(f, l, a);
    return in;
}

int main(){

    Person person1;
    
    person1 = Person("Goofy", "Goofy", 63); //I assume I should initalize both to Goofy
    
    cout << person1.first_name() << " " << person1.last_name() << " " << person1.age() << endl;

    cout << "Please give first name, last and then age 3 times" << endl; 

    Person person2;
    Person person3;
    Person person4;

    cin >> person2 >> person3 >> person4;
    
    cout << person2 << " " << person3 << "  " << person4 << endl;

    vector<Person> vec;

    for (Person p; cin >> p;)
    {
        if (p.first_name() == "end") break;
        vec.push_back(p);
    }

    for (Person p: vec)
    {
        cout << p << endl;
    }

}