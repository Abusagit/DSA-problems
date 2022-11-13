# include <iostream>

using namespace std;

void merge(int array[], int p, int q, int r){
    // Create L ← A[p..q] and M ← A[q+1..r]

    int n1 = q - p + 1; // length of left subarray array[p, q]
    int n2 = r - q; // length of right subarray array(q, r]

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++){
        L[i] = array[p + i];
    }

    for (int j = 0; j < n2; j++){
        M[j] = array[q + 1 + j];
    }

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    int i = 0, j = 0, k = p;
    
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            array[k] = L[i++];
        } else {
            array[k] = M[j++];
            }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        array[k++] = L[i++];
    }

    while (j < n2) {
        array[k++] = M[j++];
    }


}

void merge_sort(int array[], int left, int right){
    if (left < right){
        // m is the point where the array is divided into two subarrays
        int middle = left + (right - left) / 2;

        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);

        merge(array, left, middle ,right);
        
    }
}


int main(){
    int n;
    cin >> n;

    int array[n];

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        array[i] = a;
    }

    // for (int x: array){
    //     cout << x << ' ';
    // }
    // cout << "\n******\n";
    merge_sort(array, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << array[i] << ' ';
    }


}