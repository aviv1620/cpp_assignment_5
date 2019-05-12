#include <iostream>
#include <string>

using namespace std;


namespace itertools{


	template<typename T1,typename T2>
	class Zip{
		T1 iterable_left;
		T2 iterable_right;
				
		public:
			Zip(T1 left,T2 right):iterable_left(left),iterable_right(right){
			}
			
			
			class iterator{
				typename T1::iterator iterator_left;
				typename T2::iterator iterator_right;
				
				public:
					iterator(typename T1::iterator left,typename T2::iterator right,typename T1::iterator left_end,bool is_left)
					:iterator_left(left),iterator_right(right){
						
					}
					
					bool operator!=(const iterator& other)const{
						return iterator_left != other.iterator_left || iterator_right != other.iterator_right;
						
					}
					
					bool operator==(const iterator& other)const{
						return !(this!=other);
					}
					
					iterator& operator++() {
						++iterator_left;
						++iterator_right;	
						return *this;
					}
					
					string operator*() {
						string s = to_string(*iterator_left);
						s += ",";
						s += to_string(*iterator_right);
						return s;
					}
					
					
					
					
			};
			
			iterator begin() {
				return iterator(iterable_left.begin(),iterable_right.begin()
				,iterable_left.end(),true);
			}
			
			iterator end() {
				return iterator(iterable_left.end(),iterable_right.end(),
				iterable_left.end(),false);
			}
			
	
						
	};
	

	
	
	template<typename T1,typename T2>
	Zip<T1,T2> zip(T1 left,T2 right){
		return Zip(left,right);
	}
		
}