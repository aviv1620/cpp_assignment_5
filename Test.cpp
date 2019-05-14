#include <iostream>
#include <sstream>


using namespace std;
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace itertools;

template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (auto i: iterable)
		ostr << i;
	return ostr.str();
}

int main() {
	
	cout << iterable_to_string(range(1,9))  << endl;
	
	return 0;
}




