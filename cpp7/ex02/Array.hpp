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
				T *new_array = new T[arr.sizee];
				for(unsigned int i =0;i<arr.sizee;i++)
					new_array[i] = arr.array[i];
				delete [] array;
				array = new_array;
				sizee = arr.sizee;
			}
			return *this;
		}
		Array(const Array& arr):array(new T[arr.sizee]), sizee(arr.sizee)
		{
			for(unsigned int i =0; i<sizee;i++)
				array[i] = arr.array[i];
		}
	
		unsigned int size()const{
			return sizee;
		}
		T& operator[](size_t  ind){
			if (ind >= sizee)
				throw std::runtime_error("out of bounds ");
			return array[ind];
		}
		~Array(){
			delete [] array;
		}
};


#endif 
