

namespace itertools{
	
	template<typename T>
	class Range{
		T _start;
		T _end;
		
		public:
			Range(T start,T end):_start(start),_end(end){
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
			
			iterator begin() {
				return iterator{_start};
			}
			
			iterator end() {
				return iterator{_end};
			}			
	};
	
	//static function range
	template<typename T>
	Range<T> range(T stat,T end){
		return Range(stat,end);
	}
	
}