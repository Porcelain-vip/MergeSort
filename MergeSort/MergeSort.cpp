#include<iostream>

template<typename Type>
void MergeSortHelp(Type* a, Type* b, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;                //also    int mid = (left + right) / 2;
		MergeSortHelp<Type>(a, b, left, mid);
		MergeSortHelp<Type>(a, b, mid + 1, right);

		int i, low, high;
		for (i = left, low = left, high = mid + 1; low <= mid && high <= right;)
		{
			if (a[low] <= a[high]) { b[i] = a[low]; ++low; }
			else { b[i] = a[high]; ++high; }
			++i;
		}
		for (; low <= mid;) { b[i] = a[low];  ++low; ++i; }
		for (; high <= right;) { b[i] = a[high]; ++high; ++i; }
		for (i = left; i <= right; ++i) a[i] = b[i];
	}
}

template<typename Type>
void MergeSort(Type* a, int n)
{
	Type* b = new Type[n];
	MergeSortHelp<Type>(a, b, 0, n - 1);
	delete[]b;
}

int main()
{
	using namespace std;
	int a[10];
	cout << "Please enter 10 numbers as you like: ";
	for (int& value : a) cin >> value;
	MergeSort<int>(a, 10);
	cout << "Low-to-High: ";
	for (int& value : a) cout << value << "   "; cout << endl;
	return 0;
}