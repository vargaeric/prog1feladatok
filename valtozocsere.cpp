#include <iostream>
int main()
{
	int a=3, b=10;
	std::cout<<"a="<<a<<" b="<<b<<"\n";
	a ^= b;
	b ^= a;
	a ^= b;
	std::cout<<"a="<<a<<" b="<<b<<"\n";
}
