
namespace itertools{

	template<typename T1,typename T2>
	class chain{
		T1 iterable_left;
		T2 iterable_right;
				
		public:
			chain(T1 left,T2 right):iterable_left(left),iterable_right(right){
			}
			
			
			class iterator{
				typename T1::iterator iterator_left;
				typename T2::iterator iterator_right;
				
				//chain logic
				typename T1::iterator iterator_left_end;
				bool isLeft;
				
				
				public:
					iterator(typename T1::iterator left,typename T2::iterator right,typename T1::iterator left_end,bool is_left)
					:iterator_left(left),iterator_right(right),iterator_left_end(left_end),isLeft(is_left){
						
					}
					
					bool operator!=(const iterator& other)const{
						return iterator_left != other.iterator_left || iterator_right != other.iterator_right;
						
					}
					
					bool operator==(const iterator& other)const{
						return !(this!=other);
					}
					
					iterator& operator++() {
						if(isLeft){
							++iterator_left;
							
							if(iterator_left == iterator_left_end)
								isLeft = false;
						}else
							++iterator_right;	
						
						
						return *this;
					}
					
					auto& operator*() {
						if(isLeft)
							return *iterator_left;
						else
							return *iterator_right;
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
	

	
	
}