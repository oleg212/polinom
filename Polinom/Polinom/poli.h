
#pragma once
#include <iostream>
#include "stdio.h"
#include "fstream"
#include "mono.h"
#include <string>

class polinom {
	monom* start;


	void purge() {
		if (isempty())return;
		monom* tmp = start;
		while (tmp->next != nullptr) {
			monom* del = tmp;
			tmp = tmp->next;
			delete del;
		}
		delete tmp;

		start = nullptr;

	}
	polinom clean(polinom poli) {
		polinom res;
		monom* tmp = poli.start;
		while (tmp != nullptr) {
			if (tmp->getc() != 0) res.push(*tmp);
			tmp = tmp->next;
		}
		return res;
	}
public:
	bool isempty() {
		if (start == nullptr) {
			return 1;
		}
		return 0;
	}
	polinom() {
		start = nullptr;
	}

	~polinom() {
		purge();
		delete start;
	}
	polinom(const polinom& poli) {
		start = nullptr;
		if (&poli == this) { return; }
		monom* tmp = poli.start;
		while (tmp->next != nullptr) {
			monom n(tmp->c, tmp->pow);
			push(n);
			tmp = tmp->next;
		};
		monom n(tmp->c, tmp->pow);
		push(n);
	}
	void push(monom _m) {

		if (_m.getc() == 0) { return; }
		monom* val = new monom(_m.c, _m.pow);
		if (isempty()) {
			start = val;
			return;
		}
		if (start->getpow() > _m.getpow()) {
			monom* tmp = start;
			*start = _m;
			_m.next = tmp;
			delete tmp;
		}
		monom* tmp = start;
		while (tmp->next != nullptr) {
			if (tmp->getpow() == _m.getpow()) {
				tmp->setc(tmp->getc() + _m.getc());
				return;
			}
			if (tmp->next->getpow() > _m.getpow()) {
				val->next = tmp->next;
				tmp->next = val;
				return;
			}
			tmp = tmp->next;
		}
		if (tmp->getpow() == _m.getpow()) {
			tmp->setc(tmp->getc() + _m.getc());
			return;
		}
		val->next = tmp->next;
		tmp->next = val;
	}

	friend ostream& operator <<(ostream& out, const polinom& m) {

		monom* tmp = m.start;
		while (tmp->next != nullptr) {
			out << *tmp << "+";
			tmp = tmp->next;
		}
		out << *tmp;
		return out;

	}
	void save(string filename) {
		std::ofstream out;
		out.open(filename);
		if (out.is_open())
		{
			out << *this;
		}
	}

	polinom & operator=(const polinom &poli) {
		if (&poli == this) { return *this; }
		purge();
		monom* tmp = poli.start;
		while (tmp->next != nullptr) {
			monom n(tmp->c, tmp->pow);
			this->push(n);
			tmp = tmp->next;
		}
		monom n(tmp->c, tmp->pow);
		this->push(n);
		return *this;
	}
	polinom operator+(polinom poli) {
		polinom res;
		monom* tmp1 = this->start;
		while (tmp1->next != nullptr) {
			res.push(*tmp1);
			tmp1 = tmp1->next;
		}
		res.push(*tmp1);
		monom* tmp2 = poli.start;
		while (tmp2->next != nullptr) {
			res.push(*tmp2);
			tmp2 = tmp2->next;
		}
		res.push(*tmp2);
		return (res);
	}

	polinom operator* (const polinom poli) {
		polinom res;
		monom* tmp = poli.start;
		while (tmp != nullptr) {
			monom* tmp2 = start;
			while (tmp2 != nullptr) {
				monom n = *tmp * *tmp2;
				res.push(n);

				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
		}
		return res;


	}
	friend istream& operator>>(istream& istr, polinom& poli)
	{
		poli.purge();
		string tmp;
		istr >> tmp;
		char const sep = '+';
		int size = tmp.size();
		string elem = "";
		for (int i = 0;i < size;i++) {
			if (tmp[i] == sep) {
				monom m(elem);
				poli.push(m);
				elem = "";
			}
			else {
				elem += tmp[i];
			}
		}
		monom m(elem);
		poli.push(m);
		return istr;
	}
};