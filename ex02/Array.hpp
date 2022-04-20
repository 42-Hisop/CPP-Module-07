#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array
{
	private :
		T *data;
		unsigned int len;
	public :
		Array() : data(new T()), len(0)
		{}
		Array(unsigned int n) : data(new T[n]), len(n)
		{}
		Array(Array const &other) : len(other.len)
		{
			this->data = new T[other.len];
			for (int i = 0; i < static_cast<int>(other.len); i++)
				this->data[i] = other.data[i];
		}
		
		~Array()
		{
			delete [] data;
		}

		Array const &operator=(Array const &other)
		{
			if (this->len)
				delete [] data;
			this->len = other.len;
			this->data = new T[this->len];
			for (int i = 0; i < static_cast<int>(this->len); i++)
				this->data[i] = other.data[i];
			return (*this);
		}

		class Segfault: public std::exception
		{
			const char	*what() const throw()
			{
				return ("Segmentation fault");
			}
		};

		T	&operator[](unsigned int i)
		{
			if (this->len <= i)
				throw Segfault();
			else
				return (this->data[i]);
		}

		int	size() const
		{
			return (this->len);
		}
};

#endif
