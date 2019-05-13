#include <iostream>
#include <string>

using namespace std;


namespace itertools{


	template<typename T1,typename T2>
	class Product{
		T1 iterable_left;
		T2 iterable_right;
				
		public:
			Product(T1 left,T2 right):iterable_left(left),iterable_right(right){
			}
			
			
			class iterator{
				typename T1::iterator iterator_left;
				typename T2::iterator iterator_right;
				
				//product logic
				typename T1::iterator iterator_left_end;
				T2 iterable_right;
				
				public:
					iterator(typename T1::iterator left,typename T2::iterator right,typename T1::iterator left_end,T2 it_right)
					:iterator_left(left),iterator_right(right),iterator_left_end(left_end),iterable_right(it_right){
						
					}
					
					bool operator!=(const iterator& other)const{						
						return iterator_left != other.iterator_left || iterator_right != other.iterator_right;
					}
					
					
					bool test(const iterator& other)const{	
						//cout << " iterator_left " <<  to_string( *iterator_left )  << endl;
						//cout << " other.iterator_left " << to_string( *(other.iterator_left) )  << endl;	
						cout << " iterator_right " << to_string( *iterator_right ) << endl;
						cout << " other.iterator_right " << to_string( *(other.iterator_right) ) << endl;
						return iterator_left != other.iterator_left || iterator_right != other.iterator_right;
					}
					
					bool operator==(const iterator& other)const{
						return !(this!=other);
					}
					
					iterator& operator++() {																
						++iterator_right;
						
						if(iterator_right == iterable_right.end()){				
							++iterator_left;
							iterator_right = iterable_right.begin();
						}
																																					
						return *this;
					}
					
					auto operator*() {			
						return make_pair(*iterator_left,*iterator_right);
					}
					
					
					
					
			};
			
			iterator begin() {
				return iterator(iterable_left.begin(),iterable_right.begin(),iterable_left.end(),iterable_right);
			}
			
			iterator end() {
				return iterator(iterable_left.end(),iterable_right.end(),iterable_left.end(),iterable_right);
			}
			
	
						
	};
	
	template<typename T1,typename T2>
	Product<T1,T2> product(T1 left,T2 right){
		return Product(left,right);
	}
		
}