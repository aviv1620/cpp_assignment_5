#include <iostream>
#include <string>

using namespace std;


namespace itertools{


	template<typename T1,typename T2>
	class zip{
		T1 iterable_left;
		T2 iterable_right;
				
		public:
			zip(T1 left,T2 right):iterable_left(left),iterable_right(right){
			}
			
			
			class iterator{
				typename T1::iterator iterator_left;
				typename T2::iterator iterator_right;
				
				public:
					iterator(typename T1::iterator left,typename T2::iterator right)
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
					
					auto operator*() {//fixme			
						return make_pair(*iterator_left,*iterator_right);

					}
					
					
					
					
			};
			
			iterator begin() {
				return iterator(iterable_left.begin(),iterable_right.begin());
			}
			
			iterator end() {
				return iterator(iterable_left.end(),iterable_right.end());
			}
			
	
						
	};
	

	template<typename T1,typename T2>
	ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
		os << p.first << "," << p.second;
		return os;
	}
	

		
}