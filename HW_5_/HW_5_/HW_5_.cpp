/* HW_5_.cpp : Defines the entry point for the console application.

my sources are Rosettacode and the textbook. I am not directly applying rosettacode code as my own, 
but used it to double-check my thought process and influence my own. 

I will mention what each  piece of code does, and if it was influenced by rosettacode.
rosettacode links:
https://rosettacode.org/wiki/Sorting_algorithms/Bubble_sort#C.2B.2B
https://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort#C.2B.2B
https://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C.2B.2B
https://rosettacode.org/wiki/Sorting_algorithms/Shell_sort#C.2B.2B
*/
//first thing-includes...these are the same as rosettacode as I fould including these made things much easier overall.

#include "stdafx.h"//basic header
#include <algorithm> // for std::partition in quicksort...generally used across all algorithms.
#include <functional> // for std::less in quicksort, merge sort
#include <iostream>
#include <iterator>//used in bubble, insertion, merge sort methods.
#include <time.h>//for shell sort, soring time of all other algorithms. (http://www.cplusplus.com/reference/ctime/time/)
using namespace std;

const int MAX = 126;
const int MaxNum = 10001;//for a file of any size < max integer is 10,000.
int timecounter = 0; //counter to check the number of steps for each sort method.
time_t timer;
time_t resultTimer;
//
//lines 28-40 and 50, 52, 54 (excet timecounter++;) came from rosettacode.
template<typename RandomAccessIterator, typename Order>
void Merge_sort(RandomAccessIterator first, RandomAccessIterator last, Order Merge_order)
{
	
	if (last - first > 1)//if second # picked is larger than first
	{
		RandomAccessIterator mid = first + (last - first) / 2; //create a value middle that is > first but < last
		Merge_sort(first, mid, Merge_order);
		timecounter++;
		Merge_sort(mid, last, Merge_order);
		timecounter++;
		inplace_merge(first, mid, last, Merge_order);
		timecounter++;
	}
	if (last - first == 0)
	{
		cout << "There is a problem with " << last << "and " << first << ".../nThey are equal, so we cannot sort them." << endl;
		timecounter++;
			break;
	}
	if (last - first < 0)//have it drop last before first, as last - first < 0 == that LAST is SMALLER than first.
	{
		RandomAccessIterator mid = last + (first- last) / 2; //create a value middle that is (>) last but (<) first
		Merge_sort(last, mid, Merge_order);
		timecounter++;
		Merge_sort(mid, first, Merge_order);
		timecounter++;
		inplace_merge(last, mid, first, Merge_order);
		timecounter++;
	}
}

template<typename RandomAccessIterator>
void Merge_sort(RandomAccessIterator first, RandomAccessIterator last)
{
	timer = time(NULL);
	cout << "Merge sort beginning on: " << timer << endl;;
	Merge_sort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());//supposed to merge sort first, last, and less.
	resultTimer= time(NULL);
	cout << "Merge sort number of steps : " << timecounter << ", and finished by" << resultTimer <<" . "<< endl;
}
int main()
{
	Merge_sort(1, 3);
    return 0;
}

