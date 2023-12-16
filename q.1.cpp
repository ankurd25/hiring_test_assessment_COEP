#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSubarray(int arr[], int n) {
    int max_subarray_sum = arr[0];
    int current_subarray_sum = arr[0];
    int max_subsequence_sum = arr[0] > 0 ? arr[0] : 0;

    for (int i = 1; i < n; ++i) {
        
        current_subarray_sum = max(arr[i], current_subarray_sum + arr[i]);
        max_subarray_sum = max(max_subarray_sum, current_subarray_sum);

        
        if (arr[i] > 0) {
            max_subsequence_sum += arr[i];
        }
    }

    return {max_subarray_sum, max_subsequence_sum};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> result = maxSubarray(arr, n);

       
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}
