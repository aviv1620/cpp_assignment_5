#include <iostream>

namespace itertools{
	
	template<typename T>
	class range{
		T _start;
		T _end;
		
		public:
			range(T start,T end):_start(start),_end(end){
				if( _start >= _end){
					cout << "need throw" << endl;
					//throw string(" range must start < end ");
					//throw not work
					_end = _start + 1;
				}
			}
			
			class iterator{
				T _value;
		
				public:
				iterator( T value) 
				:_value(value){
				}
				
				bool operator!=(const iterator& other)const{
					return _value != other._value;
				}
				
				bool operator==(const iterator& other)const{
					return _value == other._value;
				}
				
				iterator& operator++() {
					++_value;
					return *this;
				}
				
				T& operator*() {
					return _value;
				}
				
			};//end iterator class.
			
			iterator begin() const{
				return iterator{_start};
			}
			
			iterator end() const{
				return iterator{_end};
			}			
	};
	
	
	template<typename T>
	ostream& operator<< (ostream& os, const range<T>& r) {
		os << "test";
		return os;
	}
	

	
}