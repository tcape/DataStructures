//
#include <iostream>
#include <crtdbg.h>
using namespace std;
#define _CRTDBG_MAP_ALLOC

template<class T>
void shellSort(T &, const int size);
template<class T>
void heapify(T &, int n, int i);
template<class T>
void heapSort(T &, int n);
template<class T>
void selectionSort(T &, const int size);
template <class T>
inline void quickSort(T & a, int left, int right);
template<class T>
inline int partition(T & a, int left, int right);

int main()
{
	int a[4] = { 10, 20, 15, 18 };
	quickSort(a, 15, 10);
	cin.get();
	return 0;
}

template<class T>
inline void heapify(T & arr, int n, int i)
{
	for (auto a : arr)
		cout << a << " ";
	cout << endl;
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
template<class T>
inline void heapSort(T & arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

//QUICKSORT
template <class T>
inline void quickSort(T & a, int left, int right)
{

	if (left < right)
	{
		cout << a << endl;
		int p = partition(a, left, right);
		quickSort(a, left, p - 1);
		quickSort(a, p + 1, right);
	}
}

//PARTITION
template<class T>
inline int partition(T & a, int left, int right)
{
	int p = a[left], l = left + 1, r = right;
	while (l < r)
	{
		while (l < right && a[l] < p) l++;
		while (r > left && a[r] >= p) r--;
		if (l < r)
		{
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
	}
	a[left] = a[r];
	a[r] = p;
	return r;
}

//SHELLSORT
template<class T>
inline void shellSort(T & a, const int size)
{
	int j;
	for (int h = size / 2; h > 0; h /= 2)
	{
		for (int i = h; i < size; i++)
		{
			int tmp = a[i];
			for (j = i; j >= h && tmp < a[j - h]; j -= h)
			{
				a[j] = a[j - h];
			}
			a[j] = tmp;
		}
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}


}

// SELECTION SORT
template<class T>
inline void selectionSort(T & a, const int size)
{

	for (int i = size - 1; i >= 1; i--)
	{
		int index = i; // i is the last item position and
					   // index is the largest element position 
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[index])
				index = j; // j is the current largest item
		}
		// swap the largest item a[index] with the last item a[i]
		int temp = a[index];
		a[index] = a[i];
		a[i] = temp;
		cout << a[i] << ' ';
	}
}
//
////int main()
////{
////	{
////		AVL<int> test;
////			test.Insert(8);
////			test.Insert(9);
////			test.Insert(10);
////			test.Insert(2);
////			test.Insert(1);
////			test.Insert(5);
////			test.Insert(3);
////			test.Insert(6);
////			test.Insert(4);
////			test.Insert(7);
////			test.Insert(11);
////
////			test.Delete(5);
////			test.Delete(3);
////			test.Delete(8);
////			test.Delete(9);
////
////
////		cout << "Breadth First:\t";
////		test.BreadthFirst();
////		cout << endl << "In Order:\t";
////		test.InOrder();
////		cout << endl << "Post Order:\t";
////		test.PostOrder();
////		cout << endl << "Pre Order:\t";
////		test.PreOrder();
////		cout << endl;
////	}
////
////	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
////	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
////	_CrtDumpMemoryLeaks();
////	cin.get();
////
////	return 0;
////}
//
///*BST<int> test;
//test.Insert(27);
//test.Insert(93);
//test.Insert(11);
//test.Insert(32);
//test.Insert(69);
//test.Insert(77);
//test.Insert(2);
//test.Insert(49);
//test.Insert(33);
//test.Insert(42);
//test.Insert(80);
//test.Insert(75);*/
////int main()
////{
////	const int nums[10] = { 27, 93, 11, 32, 69, 77, 2, 49, 33, 42 };
////							//3, 6, 45, 22, 55, 23, 75, 29, 63, 1 };
////	BST<int> tree;
////	for (size_t i = 0; i < 10; i++)
////		tree.Insert(nums[i]);
////
////	cout << "\nInOrder:2 11 27 32 33 42 49 69 77 93\n\t";
////	tree.InOrder();
////	cout << endl;
////	cout << "\nPrOrder:27 11 2 93 32 69 49 33 42 77\n\t";
////	tree.PreOrder();
////	cout << endl;
////	cout << "\nPsOrder:2 11 42 33 49 77 69 32 93 27\n\t";
////	tree.PostOrder();
////	cout << endl;
////	cout << "\nBrFirst:27 11 93 2 32 69 49 77 33 42\n\t";
////	tree.BreadthFirst();
////	cout << "\n\nHeight: " << tree.Height() << endl << endl;;
////
////	tree.Delete(42);
////	tree.Delete(11);
////	tree.Delete(69);
////
////	cout << "Deleted: 42, 11, 69" << endl;
////
////	cout << "\nInOrder:2 27 32 33 49 77 93\n\t";
////	tree.InOrder();
////	cout << endl;
////	cout << "\nPrOrder:27 2 93 32 49 33 77\n\t";
////	tree.PreOrder();
////	cout << endl;
////	cout << "\nPsOrder:2 33 77 49 32 93 27\n\t";
////	tree.PostOrder();
////	cout << endl;
////	cout << "\nBrFirst:27 2 93 32 49 33 77\n\t";
////	tree.BreadthFirst();
////	cout << "\n\nHeight: " << tree.Height() << endl;
////	cin.get();
////	return 0;
////}
//
//
//
//
////#include <crtdbg.h>
////#include "Windows.h"
////#include <cassert>
////#include <iostream>
////#include "ForwardIterator.h"
////#include "BackwardIterator.h"
////#include "DLList.h"  // Change to your Linked List Header
////#include "Exception.h"
////#include "Minesweeper.h"
////#include "ArrayStack.h"
////
////#define _CRTDBG_MAP_ALLOC
////
////
////int main()
////{
////	ArrayStack<string> test(5);
////	test.Push("0");
////	test.Push("1");
////	test.Push("2");
////	test.Push("3");
////	test.Push("4");
////
////	/*string testString = "";
////	test.Pop();
////	test.Pop();
////	test.Pop();
////	test.Pop();
////	test.Pop();*/
////
////	string testString;
////	for (size_t i = 0; i < 5; i++)
////		testString += test.Pop();
////
////	cout << testString;
////	cin.get();
////	return 0;
////}
////const size_t GREEN = 10;
////const size_t RED = 12;
////const size_t WHITE = 23;
////static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
////void RunTests();
////void PrintTestHeader(const char *);
////void PrintTestPass(const char *);
////void PrintTestFail(const char *, const char *);
////void TestConstructor();
////void TestCopyConstructor();
////void TestAppend();
////void TestFirstAndLast();
////void TestPrepend();
////void TestPurge();
////void TestInsertBefore();
////void TestInsertAfter();
////void TestExtract();
////void TestAssignmentOperator();
////void TestAccessors();
//
////int main()
////{
////	RunTests();
////
////	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
////	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
////	_CrtDumpMemoryLeaks();
////
////	system("pause");
////	return 0;
////}
//
////void RunTests()
////{
////	SetConsoleTextAttribute(hConsole, WHITE);
////	TestConstructor();
////	TestCopyConstructor();
////	TestAppend();
////	TestFirstAndLast();
////	TestPrepend();
////	TestPurge();
////	TestInsertBefore();
////	TestInsertAfter();
////	TestExtract();
////	TestAssignmentOperator();
////	TestAccessors();
////}
////
////void PrintTestHeader(const char *testName)
////{
////	std::cout << "\n********** " << testName << " **********" << std::endl;
////}
////
////void PrintTestPass(const char * test)
////{
////	SetConsoleTextAttribute(hConsole, GREEN);
////	std::cout << "\t" << test << ": TEST PASS" << std::endl;
////	SetConsoleTextAttribute(hConsole, WHITE);
////}
////
////void PrintTestFail(const char * test, const char * message)
////{
////	SetConsoleTextAttribute(hConsole, RED);
////	std::cerr << message << std::endl;
////	std::cerr << "\t" << test << ": TEST FAIL" << std::endl;
////	SetConsoleTextAttribute(hConsole, WHITE);
////}
////
////void TestConstructor()
////{
////	const char * test = "Constructor";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<int> list;
////
////		assert(list.isEmpty() == true);
////		assert(list.getHead() == nullptr);
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestCopyConstructor()
////{
////	const char * test = "Copy Constructor";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<int> aList;
////		aList.Append(5);
////
////		DLList<int> bList(aList);
////
////		assert(bList.isEmpty() != true);
////		assert(bList.First() == 5);
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestAssignmentOperator()
////{
////	const char * test = "Assignment Operator";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////		DLList<size_t> bList;
////
////		size_t i;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////
////		for (i = 0; i < 5; ++i)
////		{
////			aList.Append(values[i]);
////		}
////
////		bList = aList;
////
////		i = 0;
////		for (DLLNode<size_t> * node = bList.getHead(); node != nullptr; node = node->getNext())
////		{
////			assert(node->getData() == values[i++]);
////		}
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestAccessors()
////{
////	const char * test = "Accessors";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////		size_t i;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////		for (i = 0; i < 5; ++i)
////		{
////			aList.Append(values[i]);
////		}
////
////		assert(aList.getHead()->getData() == 5);
////		assert(aList.getTail()->getData() == 45);
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestAppend()
////{
////	const char * test = "Append";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////		size_t i;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////		for (i = 0; i < 5; ++i)
////		{
////			aList.Append(values[i]);
////		}
////
////		i = 0;
////		for (DLLNode<size_t> * node = aList.getHead(); node != nullptr; node = node->getNext())
////		{
////			assert(node->getData() == values[i++]);
////		}
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestFirstAndLast()
////{
////	const char * test = "First and Last";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////		for (size_t i = 0; i < 5; ++i)
////		{
////			aList.Append(values[i]);
////		}
////
////		assert(aList.First() == 5);
////		assert(aList.Last() == 45);
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestPrepend()
////{
////	const char * test = "Prepend";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////		size_t i;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////		for (i = 0; i < 5; ++i)
////		{
////			aList.Prepend(values[i]);
////		}
////
////		i = 5;
////		for (DLLNode<size_t> * node = aList.getHead(); node != nullptr; node = node->getNext())
////		{
////			assert(node->getData() == values[--i]);
////		}
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestPurge()
////{
////	const char * test = "Purge";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////		for (size_t i = 0; i < 5; ++i)
////		{
////			aList.Append(values[i]);
////		}
////
////		aList.Purge();
////
////		assert(aList.getHead() == nullptr);
////		assert(aList.getTail() == nullptr);
////		assert(aList.isEmpty() == true);
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestInsertBefore()
////{
////	const char * test = "InsertBefore";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////		int i;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////
////		aList.Append(values[4]);
////		for (i = 3; i >= 0; --i)
////		{
////			aList.InsertBefore(values[i], values[i + 1]);
////		}
////
////		i = 0;
////		for (DLLNode<size_t> * node = aList.getHead(); node != nullptr; node = node->getNext())
////		{
////			assert(node->getData() == values[i++]);
////		}
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestInsertAfter()
////{
////	const char * test = "InsertAfter";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> aList;
////		int i;
////
////		size_t values[] = { 5, 15, 25, 35, 45 };
////
////		aList.Append(values[0]);
////		for (i = 1; i < 5; ++i)
////		{
////			aList.InsertAfter(values[i], values[i - 1]);
////		}
////
////		i = 0;
////		for (DLLNode<size_t> * node = aList.getHead(); node != nullptr; node = node->getNext())
////		{
////			assert(node->getData() == values[i++]);
////		}
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
////
////void TestExtract()
////{
////	const char * test = "Extract";
////	PrintTestHeader(test);
////
////	try
////	{
////		DLList<size_t> list;
////
////		list.Append(5);
////		list.Extract(5);
////
////		assert(list.isEmpty() == true);
////		assert(list.getHead() == nullptr);
////
////		list.Append(5);
////		list.Append(10);
////		list.Append(15);
////
////		list.Extract(10);
////
////		assert(list.First() == 5);
////		assert(list.Last() == 15);
////
////		PrintTestPass(test);
////	}
////	catch (Exception exception)
////	{
////		PrintTestFail(test, exception.getMessage());
////	}
////}
//
//
////#include "Pair.h"
//
////#include "Array2DP.h"
////#include "DLList.h"
////#include "CrtDbg.h"
////#include "RowP.h"
////#include "Array2D.h"
////#include "Row.h"
////#include "Minesweeper.h"
////#include <iostream>
////#define _CRTDBG_MAP_ALLOC
//////
//////void TestPairCopyConstructor();
//////void TestArrayOLConstructor();
//////void TestArrayCopyConstructor();
//////void TestArrayAssignOperator();
//////void TestArrayBracketsOperator();
//////void TestArraySetStartIndex();
//////void TestArraySetLength();
////
////
////
//
//
//
//
//
//
//
//
//
//	/*Board board('E', 16, 30, 100);
//	board.genBombPos();
//	board.setBombs();
//	board.setAdjacents();
//	board.setDisplays();
//	board.print();*/
//
//	//board.~Board();
//
//
//	/*Array2D<int> myArray(3, 3);
//
//	int index = 0;
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3; j++)
//			myArray[i][j] = index++;
//
//	myArray.setColumn(2);
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < myArray.getColumn(); j++)
//			std::cout << myArray[i][j] << "\t";
//
//		std::cout << std::endl;
//	}*/
//	
//
//	//{
//	//	//TestPairCopyConstructor();
//	//	//TestArrayOLConstructor();
//	//	
//	//}
//	
//
//	//Array2DP<int> test(5, 5);
//	//int k = 0;
//	//for (int i = 0; i < test.getRow(); i++)
//	//{
//	//	for (int j = 0; j < test.getColumn(); j++)
//	//	{
//	//		test[i][j] = k++;
//	//		std::cout << test[i][j] << std::endl;
//	//	}
//	//}
//
//	//test.purge();
//
//
//	/*int k = 0;
//	bool pass = true;
//	Array2D<int> test(5, 5);
//	for (int i = 0; i < test.getRow(); i++)
//	{
//		for (int j = 0; j < test.getColumn(); j++)
//		{
//			test[i][j] = k++;
//			std::cout << test[i][j] << std::endl;
//		}
//	}
//	
//	std::cout << std::endl;
//
//	Array2D<int> copy(test);
//
//	for (int i = 0; i < copy.getRow(); i++)
//	{
//		for (int j = 0; j < copy.getColumn(); j++)
//		{
//			std::cout << copy[i][j] << std::endl;
//		}
//	}*/
//
//
//	/*for (int i = 0; i < copy.getRow(); i++)
//	{
//		for (int j = 0; j < copy.getColumn(); j++)
//		{
//			if (copy[i][j] != test[i][j])
//			{
//				pass = false;
//			}
//		}
//	}*/
//
//		
//	/*Array<std::string> myStringArray;
//
//	bool pass = true;
//
//	myStringArray.setLength(10);
//
//	for (int i = 0; i < 10; i++)
//		myStringArray[i] = ("Test String " + i);
//	
//	myStringArray.setLength(5);
//
//	for (int i = 0; i < 5; i++)
//	{
//
//		cout << myStringArray[i] << endl;
//		cout << "Test String" + i << endl;
//		if (myStringArray[i] != "Test String " + i)
//		{
//			pass = false;
//		}
//	}
//	
//	cout << "pass = " << pass << endl;*/
//
//	/*test.setLength(5);
//
//	for (int i = 0; i < 5; i++)
//
//	{
//		if (test[i] != "Testing " + to_string(i))
//			pass = false;
//	}
//	
//	cout << "Pass = " << pass << endl;*/
//	
//
//
////void TestPairCopyConstructor()
////{
////	// Arrange
////	Pair<int, int> pair1(5, 10);
////
////	// Act
////	Pair<int, int> pair2(pair1);
////
////
////	// Assert
////	bool pass = (pair1.GetKey() == pair2.GetKey() && 
////				pair1.GetValue() == pair2.GetValue()) 
////		? true : false;
////
////	if (pass)
////	{
////		std::cout << "TestCopyConstructor() PASS" << std::endl;
////	}
////	else
////	{
////		std::cout << "TestCopyConstructor() FAIL" << std::endl;
////	}
////}
////
////void TestArrayOLConstructor()
////{
////	//Arrange
////	Array<int> testArray1(10, 0);
////	Array<int> testArray2(10, -10);
////
////	//Act
////	for (int i = 0; i < 10; i++)
////	{
////		testArray1[i] = i;
////		testArray2[i - 10] = i;
////		std::cout << testArray1[i] << "\t" << testArray2[i - 10] << std::endl;
////	}
////
////	//Assert
////	for (int i = 0; i < 10; i++)
////	{
////		if (testArray1[i] != testArray2[i - 10])
////		{
////			std::cout << "TestArrayOLConstructor() FAIL." << std::endl;
////		}
////		else
////		{
////			std::cout << "TestArrayOLConstructor() PASS." << std::endl;
////		}
////	}
////}
//
