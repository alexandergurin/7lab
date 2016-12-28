 
#include "list.h"
int main()
{
	int i = 0;
	int val = 0;
	List<int> a;
	a(1, 1);
	a(3, -1);
	a(2,1);
	cout << "List A: "; 
	a.show();
	a.sred();
	a(0);
	cout << "List A: "; 
	a.show();
	/*List<char*> b;
	b("asd", 0);
	b("as", 0);
	b("aas", 0);
	b("zxc", 1);
	cout << "List B: "; 
	b.show();
	b.sred();*/
	List<double>c;
	c(2.21, 0);
	c(2.23, -1);
	cout << "List C: ";
	c.show();
	c.sred();
	List<Object> d;

	Object test1("asd", 1);
	Object test2("asd", 2);
	Object test3("asd", 3);


	d(test1, 0);
	d(test2, 1);
	d(test3, -1);
	cout << "List D: ";
	d.showData();
	d.sred();
	system("pause"); 
}