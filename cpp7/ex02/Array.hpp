#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array{
	private:
		T *array;
		unsigned int sizee;
	public:
		Array(): array(NULL),sizee(0){}
		Array(unsigned int n){
			array = new T[n]();
			sizee = n;
		}
		Array& operator=(const Array& arr)
		{
			if (this != &arr){
				array = new T[arr.sizee];
				sizee = arr.sizee;
			}
			return *this;
		}
		Array(const Array& arr):array(new T[arr.sizee]), sizee(arr.sizee){}
	
		unsigned int size()const{
			return sizee;
		}
		T& operator[](size_t  ind){
			if (ind > sizee)
				throw std::runtime_error("out of bounds ");
			return array[ind];
		}
		~Array(){
			delete [] array;
		}
};


#endif 
