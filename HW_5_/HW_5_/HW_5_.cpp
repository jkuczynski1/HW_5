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
#include <fstream>
#include <string>
#include <iterator>//used in bubble, insertion, merge sort methods.
#include <time.h>//for shell sort, soring time of all other algorithms. (http://www.cplusplus.com/reference/ctime/time/)
using namespace std;

const int MAX = 126;
const int MaxNum = 10001;//for a file of any size < max integer is 10,000.
int timecounter = 0; //counter to check the number of steps for each sort method.
time_t timer;
time_t resultTimer;
//*Merge sort code*\\-lines 28-72
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
	/*if (last - first == 0)
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
	unneeded code.*/
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
//*end of code*\\

//Bubble sort code\\-74 to 124

//template <typename RandomAccessIterator>
/*int bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
bool swapped = true;
while (begin != end-- && swapped) {
swapped = false;
for (auto i = begin; i != end; ++i) {
if (*(i + 1) < *i) {
std::iter_swap(i, i + 1);
swapped = true;
}
}
}
}

int bubble_main() {
int a[] = { 100, 2, 56, 200, -52, 3, 99, 33, 177, -199 };
bubble_sort(std::begin(a), std::end(a));
copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
std::cout << "\n";
}*\
//*end of code*\\



//*Insertion sort code*\\
/*template <typename RandomAccessIterator, typename Predicate>
/*
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
                    Predicate p) {
  for (auto i = begin; i != end; ++i) {
    std::rotate(std::upper_bound(begin, i, *i, p), i, i + 1);
  }
}
 
template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  insertion_sort(
      begin, end,
      std::less<
          typename std::iterator_traits<RandomAccessIterator>::value_type>());
}
 
int main() {
  int a[] = { 100, 2, 56, 200, -52, 3, 99, 33, 177, -199 };
  insertion_sort(std::begin(a), std::end(a));
  copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}*/
//*end of code*\\

//*Quick sort code*\\-126-145
//template<typename RandomAccessIterator,
//	typename Order>
/*	void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator split = std::partition(first + 1, last, std::bind2nd(order, *first));
		std::iter_swap(first, split - 1);
		quicksort(first, split - 1, order);
		quicksort(split, last, order);
	}
}

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
	quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}*/
//*end of code*\\

//*Shell sort code*\\-147-222
/*class shell
{
public:
	shell()
	{
		_gap[0] = 1750; _gap[1] = 701; _gap[2] = 301; _gap[3] = 132; _gap[4] = 57; _gap[5] = 23; _gap[6] = 10; _gap[7] = 4; _gap[8] = 1;
	}

	void sort(int* a, int count)
	{
		_cnt = count;
		for (int x = 0; x < 9; x++)
			if (count > _gap[x])
			{
				_idx = x; break;
			}

		sortIt(a);
	}

private:
	void sortIt(int* arr)
	{
		bool sorted = false;
		while (true)
		{
			sorted = true;
			int st = 0;
			for (int x = _gap[_idx]; x < _cnt; x += _gap[_idx])
			{
				if (arr[st] > arr[x])
				{
					swap(arr[st], arr[x]); sorted = false;
				}
				st = x;
			}
			if (++_idx >= 8) _idx = 8;
			if (sorted && _idx == 8) break;
		}
	}

	void swap(int& a, int& b) { int t = a; a = b; b = t; }

	int _gap[9], _idx, _cnt;
};
//--------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	srand(static_cast<unsigned int>(time(NULL))); int arr[MAX];
	for (int x = 0; x < MAX; x++)
		arr[x] = rand() % MAX - rand() % MAX;

	cout << " Before: \n=========\n";
	for (int x = 0; x < 7; x++)
	{
		for (int a = 0; a < 18; a++)
		{
			cout << arr[x * 18 + a] << " ";
		}
		cout << endl;
	}
	cout << endl; shell s; s.sort(arr, MAX);

	cout << " After: \n========\n";
	for (int x = 0; x < 7; x++)
	{
		for (int a = 0; a < 18; a++)
		{
			cout << arr[x * 18 + a] << " ";
		}
		cout << endl;
	}
	cout << endl << endl; return system("pause");
}*/
//*end of code*\\



int main()
{
	string fileInput = " ";//grabs file name, and is reused to grab lines from file. 
	string sortInput = " ";//lets the user select which sorting method they wish to use.
	ifstream in;//need an ifstream to read the file.
	int * A;//array from file, and resulting array that is printed to screen after a sort. 
	A = new int[10001];//needs to contain 10,000 #'s.
	cout << "enter one of the following: \nRandom\nReversed\nNearlySorted\nFewUnique\n" << endl; //asks which file to open.
	cin >> fileInput;
	fileInput = fileInput + ".txt"; //since all are .txt, adds the ending.
	in.open(fileInput);//opens file
	while (!in.is_open()) //if file cannot be opened, promts user to enter the name correctly.
	{
		cout << "Cannot open file. please enter the correct file name." << endl;
		fileInput = "";//resets fileInput for new selection.
		cout << "\nEnter one of the following: \nRandom\nReversed\nNearlySorted\nFewUnique\n" << endl; //asks which file to open.
		cin >> fileInput;
		fileInput = fileInput + ".txt"; //since all are .txt, adds the ending.
		in.open(fileInput);//opens file
	}
	if (in.is_open())
	{
		cout << "file " << fileInput << "opened.\nPick a search method." << endl; // prompts user for search method to be used.
		cin >> sortInput;
		cout << "You have selected " << sortInput << " as your search method.\n" << endl; //confirms method with user, then reads in the file.
		string fileInputToInt = " "; //changes file strings to int.
		int A_counter = 0; //counter to help add lines of code to A.
		int A_adder = 0; //for atoi conversion below.
		while (in.peek() != EOF)
		{
			getline(in, fileInput, ' ');//places each # in fileInput; would place the entire line, but the ' ' makes it only grab items between spaces.
			int A_adder = atoi(fileInput.c_str()); //converts fileInput to int via atoi.  http://www.cplusplus.com/forum/general/13135/
			A[A_counter] = A_adder;//adds atoi'd string (now int) to array.
			A_counter++;//increments counter.
		}
		in.clear(); in.close();//clears and closes file.
	}
	//Merge_sort( 1, 3);
    return 0;

	/*Now, seeing as I have run out of time, or am close to it, I plan to outline how I would have went 
	about the rest of my code. Most of the code for the individual functions above is not mine-
	I did not get a chance to edit the code, and please note that I do NOT implement code that
	is not mine without crediting sources. 
	
	Only the timecounter  and time implementation belong to me exclusively, after researching how the time aspect works.
	I would apply these to each iteration of the search functions, such that the time one started the search and the time 
	that a search was finished would be displayed to a user on the console.

	From there, I would implement each algorithm such that the timecounter would be used after 
	each sorting step, resulting in a correctly working counter-one for the number of exchanges. 
	For the number of comparisons, I would apply it to each test of the numbers in question instead of after each step.

	From there, at the end of a sort, I would write out the following to the console:

	cout << sortName << "\n" <<" Number of comparisons: " << NumOfComparisions << "\n" <<" Number of exchanges: " << NumOfEexchanges << endl;
wich I would then write into the table.

	*/
}

