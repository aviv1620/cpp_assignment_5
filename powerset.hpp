

namespace itertools{
	
	template<typename T>
	class powerset{
		T iterable;
		public:
			powerset(T it):
			iterable( it ){
			}
			
			class iterator{
				T iterable;
		
				public:
				iterator(T it) 
				:iterable(it){
				}
				
				bool operator!=(const iterator& other)const{
					return false;
				}
				
				bool operator==(const iterator& other)const{
					return true;
				}
				
				iterator& operator++() {
					return *this;
				}
				
				auto& operator*() {
					return iterable;
				}
				
			};//end iterator class.
			
			iterator begin() const {
				return iterator(iterable);
			}
			
			iterator end() const {
				return iterator(iterable);
			}			
	};
	

	
}