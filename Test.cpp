#include <iostream>
#include <sstream>
using namespace std;
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "Complex.hpp"
#include "badkan.hpp"
using namespace itertools;

template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (auto i: iterable)
		ostr << i << ",";
	
	ostr << "\n";
	return ostr.str();
}

int main() {
	Complex c1(1,2), c2(5,2) ,c3(7,3) ,c4(11,3);//complex from leson 4.
	
	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
		
		testcase.setname("test complex from leson 4-range");
		testcase.CHECK_OUTPUT( iterable_to_string(range(c1,c2)),
			"1+2i,2+2i,3+2i,4+2i,\n");
		testcase.setname("test complex from leson 4-chain");
		testcase.CHECK_OUTPUT( iterable_to_string(chain(range(c1,c2),range(c3,c4) )),
			"1+2i,2+2i,3+2i,4+2i,7+3i,8+3i,9+3i,10+3i,\n");
		testcase.setname("test complex from leson 4-zip");
		testcase.CHECK_OUTPUT( iterable_to_string(zip (range(c1,c2),range(Complex(7,8),Complex(11,8))) ),
			"1+2i,7+8i,2+2i,8+8i,3+2i,9+8i,4+2i,10+8i,\n");
		testcase.CHECK_OUTPUT( iterable_to_string(zip (range(c1,c2),string("abcd")) ),
			"1+2i,a,2+2i,b,3+2i,c,4+2i,d,\n");
		testcase.setname("test complex from leson 4-powerset");
		testcase.CHECK_OUTPUT( iterable_to_string( powerset(range(Complex(1,10),Complex(4,10))) ),
			"{},{1+10i},{2+10i},{1+10i,2+10i},{3+10i},{1+10i,3+10i},{2+10i,3+10i},{1+10i,2+10i,3+10i},\n");
		testcase.CHECK_OUTPUT( iterable_to_string( powerset(   chain(range(Complex(1,15),Complex(3,15)),range(Complex(24,15),Complex(26,15))))   ),
			"{},{1+15i},{2+15i},{1+15i,2+15i},{24+15i},{1+15i,24+15i},{2+15i,24+15i},{1+15i,2+15i,24+15i},{25+15i},{1+15i,25+15i},{2+15i,25+15i},{1+15i,2+15i,25+15i},{24+15i,25+15i},{1+15i,24+15i,25+15i},{2+15i,24+15i,25+15i},{1+15i,2+15i,24+15i,25+15i},\n");
		
		
		testcase.setname("test integer-range");
		testcase.CHECK_OUTPUT( iterable_to_string(range(1,4)),
			"1,2,3,\n");
		testcase.setname("test integer-chain");
		testcase.CHECK_OUTPUT( iterable_to_string(chain(range(1,4),range(7,11) )),
			"1,2,3,7,8,9,10,\n");
		testcase.setname("test integer-zip");
		testcase.CHECK_OUTPUT( iterable_to_string(zip (range(1,5),range(7,11)) ),
			"1,7,2,8,3,9,4,10,\n");
		testcase.CHECK_OUTPUT( iterable_to_string(zip (range(1,5),string("abcd")) ) ,
			"1,a,2,b,3,c,4,d,\n");
		testcase.setname("test integer-powerset");
		testcase.CHECK_OUTPUT( iterable_to_string( powerset(range(1,4)) ) ,
			"{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3},\n");
		testcase.CHECK_OUTPUT( iterable_to_string( powerset(   chain(range(1,3),range(24,26)))   ),
			"{},{1},{2},{1,2},{24},{1,24},{2,24},{1,2,24},{25},{1,25},{2,25},{1,2,25},{24,25},{1,24,25},{2,24,25},{1,2,24,25},\n");

						
		testcase.print();
		grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	
	return 0;
}


ostream& operator<< (ostream& os, const Complex& c) {
    return (os << c._re << '+' << c._im << 'i');
}




