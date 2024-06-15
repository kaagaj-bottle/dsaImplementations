#include <algorithm>
#include <iostream>
// bubble sort
// insertion sort
// selection sort
// quick sort
// merge sort
// binary tree sort
// heap sort
// shell sort
// radix sort
void printArray(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d \t", a[i]);
  }
  printf("\n");
}

// bubble sort
//--------------------------------------------------------------------
void bubbleSort(int *a, int n) {
  bool switched = true;
  for (int i = 0; (i < (n - 1)) && (switched); ++i) {
    switched = false;
    for (int j = 0; j < n - i - 1; ++j) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        switched = true;
      }
    }
    printArray(a, n);
  }
}
//---------------------------------------------------------------
// selection sort

void selectionSort(int *a, int n) {

  int index = 0;
  for (int i = 0; i < n - 1; ++i) {
    index = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[index] > a[j]) {
        index = j;
      }
    }
    std::swap(a[i], a[index]);
    printArray(a, n);
  }
}
//----------------------------------------------
// insertion sort
void insertionSort(int *a, int n) {
  int j, key;
  for (int i = 1; i < n; ++i) {
    key = a[i];
    j = i - 1;
    while ((j >= 0) && (a[j] > key)) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = key;
    printArray(a, n);
  }
}
// quick sort
int partition(int *a, int lBound, int uBound) {
  int pivot = a[lBound];
  int i = lBound;
  int j = uBound;

  while (i < j) {
    while (pivot >= a[i] and i < uBound) {
      i++;
    }
    while (pivot < a[j] and j > lBound) {
      j--;
    }
    if (i < j)
      std::swap(a[i], a[j]);
  }

  std::swap(a[j], a[lBound]);
  return j;
}

void quickSort(int *a, int lBound, int uBound) {
  if (lBound >= uBound) {
    return;
  }
  int pIndex = partition(a, lBound, uBound);
  quickSort(a, lBound, pIndex - 1);
  quickSort(a, pIndex + 1, uBound);
}
//--------------------------------------------------
// merge sort
void merge(int *a, int left, int mid, int right) {

  int subArrayOne = mid - left + 1;
  int subArrayTwo = right - mid;
  int *leftA = new int[subArrayOne];
  int *rightA = new int[subArrayTwo];
  for (int i = 0; i < subArrayOne; ++i) {
    leftA[i] = a[left + i];
  }
  for (int i = 0; i < subArrayTwo; ++i) {
    rightA[i] = a[mid + 1 + i];
  }
  int j = 0, k = 0, l = left;
  while ((j < subArrayOne) && (k < subArrayTwo)) {
    if (leftA[j] <= rightA[k]) {
      a[l] = leftA[j];
      ++j;
    } else {
      a[l] = rightA[k];
      ++k;
    }
    ++l;
  }

  while (j < mid - left + 1) {
    a[l] = leftA[j];
    ++j;
    ++l;
  }
  while (k < right - mid) {
    a[l] = rightA[k];
    ++k;
    ++l;
  }
}

void mergeSort(int left, int right, int *a) {
  int mid;
  if (left < right) {
    mid = (left + right) / 2;
    mergeSort(left, mid, a);
    mergeSort(mid + 1, right, a);
    merge(a, left, mid, right);
    printArray(a, 7);
  }
}

int main() {
  int a[] = {85, 76, 46, 92, 30, 41, 12};
  int n = sizeof(a) / sizeof(int);
  // bubbleSort(a,n);
  // selectionSort(a,n);
  // insertionSort(a,n);
  // passing he array,its lower bound and the upper bound (index of the last
  // element) quickSort(a,0,n-1);
  mergeSort(0, n - 1, a);
  printArray(a, n);

  std::cin.get();
  return 0;
}
