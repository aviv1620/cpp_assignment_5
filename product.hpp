

using namespace std;


namespace itertools{


	template<typename T1,typename T2>
	class product{
		T1 iterable_left;
		T2 iterable_right;
				
		public:
			product(T1 left,T2 right):iterable_left(left),iterable_right(right){
			}
						
			class iterator{
				typename T1::iterator iterator_left;
				typename T2::iterator iterator_right;
				
				//product logic
				typename T1::iterator iterator_left_end;
				typename T2::iterator iterator_right_end;
				typename T2::iterator iterator_right_begin;
				
				public:
					iterator(typename T1::iterator left,typename T2::iterator right,typename T1::iterator left_end,typename T2::iterator right_end,typename T2::iterator right_begain)
					:iterator_left(left),iterator_right(right),iterator_left_end(left_end),iterator_right_end(right_end),iterator_right_begin(right_begain){						
					}
					
					bool operator!=(const iterator& other)const{						
						return iterator_left != other.iterator_left || iterator_right != other.iterator_right;
					}

					bool operator==(const iterator& other)const{
						return !(this!=other);
					}
					
					iterator& operator++() {																						
						++iterator_right;						
						return *this;
					}
					
						
					
					auto operator*() {	
						//i finish the right i back to begin and add the left.
						//but if the left is and i need finish.
						if(iterator_right == iterator_right_end && iterator_left != iterator_left_end){	
							++iterator_left;
							iterator_right = iterator_right_begin;
						}
					
						return make_pair(*iterator_left,*iterator_right);
					}
					
					
					
					
			};
			
			iterator begin() {
				return iterator(iterable_left.begin(),iterable_right.begin(),iterable_left.end(),iterable_right.end(),iterable_right.begin());
			}
			
			iterator end() {
				return iterator(iterable_left.end(),iterable_right.end(),iterable_left.end(),iterable_right.end(),iterable_right.begin());
			}
			
	
						
	};
		
}