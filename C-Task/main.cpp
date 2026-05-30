#include<iostream>
#include"class/newclass.h"
#include"output.h"

using namespace std;

int main() {

	struct AX {
		int x{};
		string name{};

		AX(int x,string name = "Null") :
			x(x),name(name) {}

		operator string() const {
			return to_string(x);
		}

		string get_name()const {
			return name;
		}
	};

	const char name = 'a';
	OutPut::output("HelloWorld!!");
	OutPut::output(name);
	OutPut::output(AX(100).get_name());

	newclass A;

	return 0;
}