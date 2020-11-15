// Name: Jessica Runandy
// Date: November 21, 2019
// Program 4: Sorting
// Description: This program implements the bubble sort, insertion sort, merge sort,
// iterative merge sort, quick sort, and shell sort.


#ifndef SORTIMPLS_H
#define SORTIMPLS_H

using namespace std;
#include <vector>
#include <string>
#include <iostream>

void BubbleSort(vector<int> &items, int first, int last);
void Swap(int& num1, int& num2);
void InsertionSort(vector<int>& items, int first, int last);
void Merge(vector<int> &items, int first, int mid, int last);
void MergeSort(vector<int> &items, int first, int last);
void IterativeMergeSort(vector<int> &items, int first, int last);
void IterativeMerge(int first, int mid, int last, vector<int> &items, vector<int> &tempVector);
int Minimum(int num1, int num2);
void QuickSort(vector<int> &items, int first, int last);
void ShellSort(vector<int> &items, int first, int last);
void ErrorMessage(int first, int last, vector<int>& items);


void BubbleSort(vector<int> &items, int first, int last) {
	ErrorMessage(first, last, items);
    bool sorted = false;
    int size = last + 1;
    int pass = 1;
    while (!sorted && (pass < size)) {
        sorted = true;
        for (int index = first; index < size - pass; index++) {
            int nextIndex = index + 1;
            if (items[index] > items[nextIndex]) {
                Swap(items[index], items[nextIndex]);
                sorted = false;
            }
        }
        pass++;
    }
}


// Postcondition: Swaps num1 and num2
void Swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void InsertionSort(vector<int> &items, int first, int last) {
	ErrorMessage(first, last, items);
    int size = last + 1;
	for (int unsorted = first + 1; unsorted < size; unsorted++) {
		int nextItem = items[unsorted];
		int insertionIndex = unsorted;
		while ((insertionIndex > first) && (items[insertionIndex - 1] > nextItem)) {
			items[insertionIndex] = items[insertionIndex - 1];
			insertionIndex--;
		}
		items[insertionIndex] = nextItem;
	}
}


void Merge(vector<int> &items, int first, int mid, int last) {
    vector<int> tempVector(items.size()); // Temporary vector

    int first1 = first;
    int last1 = mid;

    // mid + 1 = beginning of the 2nd segment
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;
    while ((first1 <= last1) && (first2 <= last2)) {
        if (items[first1] <= items[first2]) {
            tempVector[index] = items[first1];
            first1++;
        } else {
            tempVector[index] = items[first2];
            first2++;
        }
        index++;
    }

    while (first1 <= last1) {
        tempVector[index] = items[first1];
        first1++;
        index++;
    }

    while (first2 <= last2) {
        tempVector[index] = items[first2];
        first2++;
        index++;
    }

    for (index = first; index <= last; index++) {
        items[index] = tempVector[index];
    }
}


void MergeSort(vector<int> &items, int first, int last) {
	ErrorMessage(first, last, items);
    if (first < last) {
        int mid = first + (last - first) / 2; // Midpoint
        MergeSort(items, first, mid);
        MergeSort(items, mid + 1, last);
        Merge(items, first, mid, last);
    }
}

// IterativeMergeSort: Non-recursive, one extra array merge sort.
void IterativeMergeSort(vector<int> &items, int first, int last) {
	ErrorMessage(first, last, items);
    vector<int> tempVector(items.size());

    for (int i = 1; i <= last; i = 2 * i) {
        for (int j = first; j < last; j += 2 * i) {
			int leftIndex = j;
            int middleIndex = Minimum(i + j - 1, last);
			int endIndex = Minimum(2 * i + j - 1, last);
            IterativeMerge(leftIndex, middleIndex, endIndex, items, tempVector);
        }
    }
}

void IterativeMerge(int first, int mid, int last, vector<int> &items, vector<int> &tempVector) {
	int first1 = first;
	int last1 = mid;

	// mid + 1 = beginning of the 2nd segment
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2)) {
		if (items[first1] <= items[first2]) {
			tempVector[index] = items[first1];
			first1++;
		}
		else {
			tempVector[index] = items[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1) {
		tempVector[index] = items[first1];
		first1++;
		index++;
	}

	while (first2 <= last2) {
		tempVector[index] = items[first2];
		first2++;
		index++;
	}

	for (index = first; index <= last; index++) {
		items[index] = tempVector[index];
	}
}

int Minimum(int num1, int num2) {
    if (num1 <= num2) {
        return num1;
    } else {
        return num2;
    }
}

void QuickSort(vector<int> &items, int first, int last) {
	ErrorMessage(first, last, items);
    if (last - first < 4) {
        InsertionSort(items, first, last);
        return;
    }
	int mid = first + (last - first) / 2;
	if (items[first] > items[last]) {
		Swap(items[first], items[last]);
	}
    if (items[first] > items[mid]) {
        Swap(items[first], items[mid]);
    } else if (items[mid] > items[last]) {
        Swap(items[mid], items[last]);
    }

    int pivot = items[mid];
    Swap(items[mid], items[last - 1]);

    int indexFromLeft = first + 1;
    int indexFromRight = last - 2;
    bool done = false;
    while (!done) {
        while (items[indexFromLeft] < pivot) {
            indexFromLeft++;
        }
        while (items[indexFromRight] > pivot) {
            indexFromRight--;
        }
        if (indexFromRight > indexFromLeft) {
            Swap(items[indexFromLeft], items[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        } else {
            done = true;
        }
    }
    Swap(items[indexFromLeft], items[last - 1]);
    QuickSort(items, first, indexFromLeft - 1);
    QuickSort(items, indexFromLeft + 1, last);
    
}


void ShellSort(vector<int> &items, int first, int last) {
	ErrorMessage(first, last, items);
    int size = last - first + 1;
    for (int gap = size / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2)) {
        for (int i = gap; i < size; i++) {
            int temp = items[i + first];
            int j = i;
            for ( ; (j >= gap) && (temp < items[j - gap + first]); j -= gap) {
                items[j + first] = items[j - gap + first];
            }
            items[j + first] = temp;
        }
    }
}

// Prints error message if index is out of bounds.
void ErrorMessage(int first, int last, vector<int>& items) {
    if (first < 0 || last < 0) {
        cerr << "Error: Index needs to be 0 or greater." << endl;
	}
	else if (first > last) {
		cerr << "Error: First index needs to be greater than the last index." << endl;
	}
	else if (last > (items.size() - 1)) {
		cerr << "Error: Index out of bounds." << endl;
	}
	return;
}
#endif