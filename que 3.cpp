#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMissingElement(int N, vector<int>& A) {
    sort(A.begin(), A.end());

    for (int i = 0; i < N - 1; ++i) {
        if (A[i] != i + 1) {
            return i + 1;
        }
    }

    return N; 
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<int> A(N - 1);
    cout << "Enter the elements of the array (distinct integers): ";
    for (int i = 0; i < N - 1; ++i) {
        cin >> A[i];
    }

    int missingElement = findMissingElement(N, A);

    cout << "Missing Element: " << missingElement << endl;

    return 0;
}
