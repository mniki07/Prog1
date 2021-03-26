#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return (x / 2) + cos(x); }
class Bad_name {};
class Bad_age {};
struct Person
{
private:
	//string name;
	string first_name, second_name;
	int age;
public:
	Person()
	{
		//name = "";
		first_name = second_name = "";
		age = 0;
	}
	Person(string f_n, string s_n, int a)
	{
		/*name = n;
		for ( auto i : name)
		{
			if (!isalpha(i)) //ékezetes karaktereket nem kezel
			{
				throw Bad_name{};
			}
		}*/
		first_name = f_n;
		for (auto i : first_name)
		{
			if (!isalpha(i)) //ékezetes karaktereket nem kezel
			{
				throw Bad_name{};
			}
		}
		second_name = s_n;
		for (auto i : second_name)
		{
			if (!isalpha(i)) //ékezetes karaktereket nem kezel
			{
				throw Bad_name{};
			}
		}
		age = a;
		if ((a < 0) || (a > 150))
		{
			throw Bad_age{};
		}
	}
	//6.feladat
	friend ostream& operator<<(ostream& output, const Person& P) {
		//output << "Name: " << P.name << " Age: " << P.age << endl;
		output << "First name: " << P.first_name << endl
			<< "Second name: " << P.second_name << endl
			<< "Age: " << P.age << endl;
		return output;
	}
	friend istream& operator>>(istream& input, Person& P) {
		//string n;
		string f_n, s_n;
		int a;
		//input >> P.name >> P.age;
		input >> P.first_name >> P.second_name >> P.age;
		//n = P.name;
		f_n = P.first_name;
		s_n = P.second_name;
		a = P.age;
		//Person p(n, a);
		Person(f_n, s_n, a);
		return input;
	}

};
int main() 
{
	try {
		/*Person per;
	   per.name = "Goofy";
	   per.age = 63;
	   cout << per.name << " " << per.age << endl;*/

	   /*Person per2;
	   cin >> per2.name >> per2.age;
	   cout << per2.name << " " << per2.age;*/

		Person p;
		cin >> p;
		cout << p;

		/*vector<Person> people;
		for (int i = 0; i < 3; i++)
		{
			cin >> p;
			people.push_back(p);
		}

		for (int i = 0; i < 3; i++)
		{
			cout << people[i];
		}*/
	}
	catch (Bad_age)
	{
		cout << "Invalid age! (0-150)" << endl;
	}
	catch (Bad_name)
	{
		cout << "Invalid name!/No name!" << endl;
	}

    int xmax = 600;
    int ymax = 600;

    int x_orig = xmax / 2;
    int y_orig = ymax / 2;

    int rmin = -10;
    int rmax = 11;

    int n_points = 400;

    Simple_window win{ Point{100,100}, xmax, ymax, "Function graphs" };

    Point origo{ x_orig,y_orig };
    int xlength = 400;
    int ylength = 400;

    int xscale = 20, yscale = 20;

    Axis x{ Axis::x, Point{100,y_orig}, xlength,xlength / xscale,"1==20 pixels" };
    Axis y{ Axis::y, Point{x_orig,ylength+100}, ylength,ylength / yscale,"1==20 pixels" };
    x.set_color(Color::red);
    y.set_color(Color::red);

    Function s(one, rmin, rmax, origo, n_points,0,0);
    s.set_color(Color::blue);
    win.attach(s);

    Function s1(one, rmin, rmax, origo, n_points,xscale,yscale);
    s1.set_color(Color::black);

    Function slp(slope, rmin, rmax, origo, n_points, xscale, yscale);
    slp.set_color(Color::dark_cyan);

    Text t{ Point{500,175},"Text x/2" };
    t.set_color(Color::dark_green);

    Function sqr(square, rmin, rmax, origo, n_points, xscale, yscale);
    sqr.set_color(Color::dark_red);

    Function cos_func([](double x) { return cos(x); }, rmin, rmax, origo, n_points, xscale, yscale);
    cos_func.set_color(Color::blue);

    Function slop_cos(sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);
    slop_cos.set_color(Color::yellow);

    win.attach(slop_cos);
    win.attach(cos_func);
    win.attach(sqr);
    win.attach(t);
    win.attach(slp);
    win.attach(s1);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();
}