#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S {
     S(T v = 0) : val{ v } { }

    S& operator=(const T&);

    T& get();
    const T& get() const;
    void set(T new_t) { val = new_t; }

private:
    T val;
};

template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    
    for (T val; is >> val; ) 
    {
        v.push_back(val);
        is >> ch;
        if (ch == '.') break;
    }

    return is;
}

template<typename T> 
void read_val(T& v)
{
    std::cin >> v;
}

int main()
{
    S<int> int_s{ 19 };
    S<char> char_s{ 'x' };
    S<double> double_s{ 3.14 };
    S<std::string> string_s{ "Hello!" };
    S<std::vector<int>> vector_s{ std::vector<int>{10,20,30,40,50} };

    std::cout << "S<int> : " << int_s.get() << std::endl;
    std::cout << "S<char> : " << char_s.get() << std::endl;
    std::cout << "S<double> : " << double_s.get() << std::endl;
    std::cout << "S<string> : " << string_s.get() << std::endl;
    std::cout << "S<vector<int>> : " << vector_s.get() << std::endl<<std::endl;
    
    char_s.set('s');
    std::cout << "S<char> .set : " << char_s.get() << '\n';
    
    int_s = 5;
    std::cout << "S<int> '=': " << int_s.get() << '\n';
    std::cout<<std::endl;
    
    std::cout << "Integer: ";
    int i;
    read_val(i);
    S<int> int_s2 {i};

    std::cout << "Char: ";
    char c;
    read_val(c);
    S<char> char_s2 {c};

    std::cout << "Double: ";
    double d;
    read_val(d);
    S<double> double_s2 {d};

    std::cout << "String: ";
    std::string st;
    read_val(st);
    S<std::string> string_s2 {st};
    std::cout << std::endl;

    std::cout << "S<int> value: " << int_s2.get() << '\n';
    std::cout << "S<char> value: " << char_s2.get() << '\n';
    std::cout << "S<double> value: " << double_s2.get() << '\n';
    std::cout << "S<string> value: " << string_s2.get() << '\n';
   
    std::cout << "Vector<int>: (format:  val1, val2, val3 .) ";
    std::vector<int> vec2;
    read_val(vec2);
    S<std::vector<int>> vector_s2{ vec2 };

    std::cout << "S<vector<int>> value: " << vector_s2.get() << '\n';
}