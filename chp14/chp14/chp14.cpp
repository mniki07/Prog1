#include <iostream>
#include <string>
#include "std_lib_facilities.h"
class B1
{
public:
	virtual void vf() const { std::cout << "B1::vf()\n"; }
	void f() const { std::cout << "B1::f()\n"; }
	virtual void pvf() = 0;

};
class D1 :public B1
{
	void vf() const override { std::cout << "D1::vf()\n"; };
	void f() { std::cout << "D1::f()\n"; }
	virtual void pvf() { std::cout << "D1::pvf\n"; }
};
class D2 :public D1
{
	virtual void  pvf() override { std::cout << "D2::pvf()\n"; }

};
class B2
{
public:
	virtual void pvf() = 0;
	void f() { std::cout << "B2::f\n"; }
};

class D21 :public B2
{
	string str = "override";
	virtual void pvf() override { std::cout << str << std::endl; }
};
class D22 :public B2
{
	int str = 5;
	virtual void pvf() override { std::cout << str << std::endl; }
	void f() { std::cout << "D22::f\n"; }
};

void call(B1& b)
{
	b.vf();
	b.f();
	b.pvf();

}
void call2(B2& b)
{
	b.f();
	b.pvf();
}
int main()
{
	//B1 b1;
	D1 d1;
	D2 d2;
	/*b1.vf();
	b1.f();*/
	/*d1.vf();
	d1.f();*/
	//call(b1);
	call(d1);
	call(d2);
	D21 d21;
	D22 d22;
	call2(d21);
	call2(d22);


}