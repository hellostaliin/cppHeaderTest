#include <iostream>
#include <vector>
using namespace std;

class Sorter {
private:
    int numComparisons; // Private member variable

protected:
    int numSwaps; // Protected member variable

public:
    Sorter() : numComparisons(0), numSwaps(0) {}

    int getNumComparisons() const {
        return numComparisons;
    }

    int getNumSwaps() const {
        return numSwaps;
    }

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                numComparisons++; // Increment numComparisons (private member)
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    numSwaps++; // Increment numSwaps (protected member)
                }
            }
        }
    }
};

class CustomSorter : public Sorter {
public:
    void displayStats() {
        // Access and display both protected and public members from the base class
        cout << "Number of comparisons: " << getNumComparisons() << endl;
        cout << "Number of swaps: " << getNumSwaps() << endl;
    }
};

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    CustomSorter sorter;
    sorter.bubbleSort(arr);

    sorter.displayStats();

    return 0;
}
