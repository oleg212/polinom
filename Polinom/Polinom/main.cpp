
#include "stdio.h"
#include <iostream>

#include "mono.h"
#include "poli.h"

int main() {
	polinom p;
	for (int i = 0;i < 10;i++) {
		monom m(10 - i, i, i / 3, i / 2);
		p.push(m);
	}



	monom m(42, 3, 1, 2);
	p.push(m);
	cout << p << endl;
	p.save("polinom.txt");
	polinom lfile;
	ifstream file("polinom.txt");
	file >> lfile;
	lfile.push(m);
	polinom p3 = lfile + p;

	polinom a1;
	a1.push(monom(1, 1, 1, 1));
	a1.push(monom(1, 1, 2, 2));
	cout << a1 << endl;
	polinom a2;
	a2.push(monom(1, -1, 1, 3));
	a2.push(monom(1, 1, 3, 2));
	cout << a2 << endl;
	polinom a3;
	a3 = a2;
	a3 = a2 * a1;
	cout << a3;







	return 0;
}