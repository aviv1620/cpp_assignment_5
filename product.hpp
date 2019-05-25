

using namespace std;


namespace itertools{


	template<typename T1,typename T2>
	class product{
		typename T1::iterator iterator_left_begin;
		typename T2::iterator iterator_right_begin;
		typename T1::iterator iterator_left_end;
		typename T2::iterator iterator_right_end;

				
		public:
			product(T1 left,T2 right):
			iterator_left_begin( left.begin() ),
			iterator_right_begin( right.begin() ),
			iterator_left_end( left.end() ),
			iterator_right_end( right.end() )
			{
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
							cout << "left end is " << *left_end << endl;
					}
					
					bool operator!=(const iterator& other)const{						
						return iterator_left != other.iterator_left ;//|| iterator_right != other.iterator_right;
					}

					bool operator==(const iterator& other)const{
						return !( iterator_left != other.iterator_left );//|| iterator_right != other.iterator_right );
					}
					
					iterator& operator++() {																						
						++iterator_right;
						//i finish the right i back to begin and add the left.
						//but if the left is end i need finish.
						if(iterator_right == iterator_right_end && iterator_left != iterator_left_end){	
							++iterator_left;
							iterator_right = iterator_right_begin;
						}
						
						return *this;
					}
					
						
					
					auto operator*() {	
						
					
						return make_pair(*iterator_left,*iterator_right);
					}
	
			};
			
			iterator begin() const {
				return iterator(iterator_left_begin,iterator_right_begin,iterator_left_end,iterator_right_end,iterator_right_begin);
			}
			
			iterator end() const{
				return iterator(iterator_left_end,iterator_right_end,iterator_left_end,iterator_right_end,iterator_right_begin);
			}
			
	
						
	};
	
	template<typename T1,typename T2>
	ostream& operator<< (ostream& os, const product<T1,T2>& zi) {
		os << "test";
		return os;
	}
		
}