

namespace itertools{
	
	template<typename T>
	class range{
		T _start;
		T _end;
		
		public:
			range(T start,T end):_start(start),_end(end){
			}
			
			class iterator{
				T _value;
		
				public:
				iterator( T value) 
				:_value(value){
				}
				
				bool operator!=(const iterator& other)const{
					return _value != other._value;
				}
				
				bool operator==(const iterator& other)const{
					return _value == other._value;
				}
				
				iterator& operator++() {
					++_value;
					return *this;
				}
				
				T& operator*() {
					return _value;
				}
				
			};//end iterator class.
			
			iterator begin() const{
				return iterator{_start};
			}
			
			iterator end() const{
				return iterator{_end};
			}			
	};
	

	
}