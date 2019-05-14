

namespace itertools{
	
	template<typename T>
	class powerset{
		T _iterable;
		
		public:
			powerset(T it):_iterable(it){
			}
			
			class iterator{
				typename T::iterator _iterator;
		
				public:
				iterator(typename T::iterator iter) 
				:_iterator(iter){
				}
				
				bool operator!=(const iterator& other)const{
					return _iterator != other._iterator;
				}
				
				bool operator==(const iterator& other)const{
					return _iterator == other._iterator;
				}
				
				iterator& operator++() {
					++_iterator;
					return *this;
				}
				
				auto& operator*() {
					return *_iterator;
				}
				
			};//end iterator class.
			
			iterator begin() {
				return iterator(_iterable.begin());
			}
			
			iterator end() {
				return iterator(_iterable.end());
			}			
	};
	

	
}