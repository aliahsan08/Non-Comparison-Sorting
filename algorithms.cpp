#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

// generate random numbers within a range
vector<int> generateRandomVector(int n, int minVal, int maxVal) {
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);
    for (int &x : arr) x = dis(gen);
    return arr;
}

// counting sort non-stable
void countingSortNonStable(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    for (int x : arr) count[x]++;
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) arr[idx++] = i;
    }
}

// counting sort stable
void countingSortStable(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    for (int x : arr) count[x]++;
    for (int i = 1; i <= maxVal; i++) count[i] += count[i - 1];
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    arr = output;
}

// get digit for radix sort
int getDigit(int num, int place) {
    return (num / place) % 10;
}

// LSD radix sort
void radixSortLSD(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int place = 1; maxVal / place > 0; place *= 10) {
        vector<vector<int>> buckets(10);
        for (int x : arr) buckets[getDigit(x, place)].push_back(x);
        int idx = 0;
        for (int i = 0; i < 10; i++)
            for (int x : buckets[i]) arr[idx++] = x;
    }
}

// bucket sort
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<vector<int>> buckets(n);
    for (int x : arr) {
        int idx = (long long)x * n / (maxVal + 1);
        buckets[idx].push_back(x);
    }
    int pos = 0;
    for (auto& b : buckets) {
        sort(b.begin(), b.end());
        for (int x : b) arr[pos++] = x;
    }
}

// pigeonhole sort
void pigeonholeSort(vector<int>& arr) {
    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());
    int range = mx - mn + 1;
    vector<int> holes(range, 0);
    for (int x : arr) holes[x - mn]++;
    int idx = 0;
    for (int i = 0; i < range; i++)
        while (holes[i]--) arr[idx++] = i + mn;
}

// test function
void runExperiment(string title, vector<int> arr) {
    cout << "\n" << title << "\n";

    {
        auto a = arr;
        auto start = chrono::high_resolution_clock::now();
        countingSortNonStable(a, *max_element(arr.begin(), arr.end()));
        auto end = chrono::high_resolution_clock::now();
        cout << "Counting Sort (Non-Stable): "
             << chrono::duration<double, milli>(end - start).count() << " ms\n";
    }

    {
        auto a = arr;
        auto start = chrono::high_resolution_clock::now();
        countingSortStable(a, *max_element(arr.begin(), arr.end()));
        auto end = chrono::high_resolution_clock::now();
        cout << "Counting Sort (Stable): "
             << chrono::duration<double, milli>(end - start).count() << " ms\n";
    }

    {
        auto a = arr;
        auto start = chrono::high_resolution_clock::now();
        radixSortLSD(a);
        auto end = chrono::high_resolution_clock::now();
        cout << "Radix Sort (LSD): "
             << chrono::duration<double, milli>(end - start).count() << " ms\n";
    }

    {
        auto a = arr;
        auto start = chrono::high_resolution_clock::now();
        bucketSort(a);
        auto end = chrono::high_resolution_clock::now();
        cout << "Bucket Sort: "
             << chrono::duration<double, milli>(end - start).count() << " ms\n";
    }

    {
        auto a = arr;
        auto start = chrono::high_resolution_clock::now();
        pigeonholeSort(a);
        auto end = chrono::high_resolution_clock::now();
        cout << "Pigeonhole Sort: "
             << chrono::duration<double, milli>(end - start).count() << " ms\n";
    }
}

int main() {
    int n = 30000;

    auto randomCase = generateRandomVector(n, 0, 9999);
    auto sortedCase = randomCase;
    sort(sortedCase.begin(), sortedCase.end());
    auto reverseCase = sortedCase;
    reverse(reverseCase.begin(), reverseCase.end());
    auto smallRangeCase = generateRandomVector(n, 0, 20);
    auto largeRangeCase = generateRandomVector(n, 0, 1000000);

    runExperiment("Random Case (0–9999)", randomCase);
    runExperiment("Already Sorted Case", sortedCase);
    runExperiment("Reverse Sorted Case", reverseCase);
    runExperiment("Small Range Case (0–20)", smallRangeCase);
    runExperiment("Large Range Case (0–1,000,000)", largeRangeCase);

    return 0;
}
