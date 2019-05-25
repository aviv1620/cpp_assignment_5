

namespace itertools{
	
	template<typename T>
	class powerset{
		typename T::iterator iterator_begin;
		typename T::iterator iterator_end;				
		
		public:
			powerset(T it):
			iterator_begin( it.begin() ),
			iterator_end( it.end() )
			{
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
			
			iterator begin() const {
				return iterator(iterator_begin);
			}
			
			iterator end() const {
				return iterator(iterator_end);
			}			
	};
	

	
}