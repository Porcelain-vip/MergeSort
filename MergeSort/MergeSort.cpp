#include<iostream>
#include<memory>
using namespace std;

template<typename Type>
void MergeSortHelp(Type* a, Type* b, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;                                     //also    int mid = (left + right) / 2;
		MergeSortHelp<Type>(a, b, left, mid);                    //sort left part
		MergeSortHelp<Type>(a, b, mid + 1, right);          //sort right part

		int i = left, low = left, high = mid + 1;
		for (; low <= mid && high <= right;)                            //merge two parts
		{
			if (a[low] <= a[high]) { b[i] = a[low]; ++low; ++i; }
			else { b[i] = a[high]; ++high; ++i; }
		}
		for (; low <= mid;) { b[i] = a[low];  ++low; ++i; }
		for (; high <= right;) { b[i] = a[high]; ++high; ++i; }
		for (i = left; i <= right; ++i) a[i] = b[i];
	}
}

template<typename Type>
void MergeSort(Type* a, int n)
{
	unique_ptr<Type[]>up(new Type[n]);
	MergeSortHelp<Type>(a, up.get(), 0, n - 1);
}

int main()
{
	int a[10];
	cout << "Please enter 10 numbers as you like: ";
	for (auto& value : a) cin >> value;
	MergeSort<int>(a, 10);
	cout << "Low-to-High: ";
	for (int& value : a) cout << value << "   "; cout << endl;
	return EXIT_SUCCESS;
}