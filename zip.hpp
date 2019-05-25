

using namespace std;


namespace itertools{


	template<typename T1,typename T2>
	class zip{
		typename T1::iterator iterator_left_begin;
		typename T2::iterator iterator_right_begin;
		typename T1::iterator iterator_left_end;
		typename T2::iterator iterator_right_end;
				
		public:
			zip(T1 left,T2 right):
			iterator_left_begin( left.begin() ),
			iterator_right_begin( right.begin() ),
			iterator_left_end( left.end() ),
			iterator_right_end( right.end() )
			{
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
					
					auto operator*() {			
						return make_pair(*iterator_left,*iterator_right);

					}
					
					
					
					
			};
			
			iterator begin() const {
				return iterator(iterator_left_begin,iterator_right_begin);
			}
			
			iterator end() const {
				return iterator(iterator_left_end,iterator_right_end);
			}
			
	
						
	};
	

	template<typename T1,typename T2>
	ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
		os << p.first << "," << p.second;
		return os;
	}
	
	template<typename T1,typename T2>
	ostream& operator<< (ostream& os, const zip<T1,T2>& zi) {
		os << "test";
		return os;
	}
	

		
}