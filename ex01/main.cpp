#include "iter.hpp"

int main()
{
	int *arr = new int[10];
	float *arr_f = new float[10];

	std::cout << "before ";
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "before_f ";
	for (int i = 0; i < 10; i++)
	{
		arr_f[i] = i / (float)2;
		std::cout << arr_f[i] << " ";
	}
	std::cout << std::endl;

	::iter(arr, 10, &::plus_one);
	std::cout << "after ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	::iter(arr_f, 10, &::plus_one);
	std::cout << "before_f ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr_f[i] << " ";
	}
	std::cout << std::endl;

	delete [] arr;
	delete [] arr_f;

	return (0);



}
