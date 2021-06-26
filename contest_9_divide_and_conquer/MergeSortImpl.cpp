#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) {
  // assumes arr[l..m] and arr[m+1..r] are sorted
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1];
  int R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }

  for (int i = 0; i < n2; i++) {
    R[i] = arr[m + 1 + i];
  }

  int i = 0, j = 0;

  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      arr[k] = L[i];
      i++;
    } else if (L[i] > R[j]) {
      arr[k] = R[j];
      j++;
    }

    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int l, int r) {
  if (l >= r)
    return;

  int m = l + (r - l) / 2;
  merge_sort(arr, l, m);
  merge_sort(arr, m + 1, r);

  merge(arr, l, m, r);
}

int main() {
  int arr[10] = {1, 3, 2, 4, 5, 7, 6, 9, 10, 8};

  merge_sort(arr, 0, 9);

  for (int c : arr) {
    cout << c << " ";
  }

  cout << endl;
}
