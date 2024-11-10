// Overall Time Complexity :
// Building the min-heap : O(n)
// Merging the files : O(n log n)
// Overall time complexity is O(n log n).
// space complexity of this algorithm is O(n), where n is the number of files bcoz we store the array of file sizes and use extra space for the heap (which is the same array).
// Greedy approach with min-heap (priority queue)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int optimalMerge(vector<int> &files)
{
    priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());
    int totalCost = 0;
    int iteration = 1;

    while (minHeap.size() > 1)
    {
        int first_smallest = minHeap.top();
        minHeap.pop();
        int second_smallest = minHeap.top();
        minHeap.pop();

        int merge_cost = first_smallest + second_smallest;
        totalCost += merge_cost;

        minHeap.push(merge_cost);

        cout << "Iteration " << iteration++ << ":\n";
        cout << "  Merging files of size " << first_smallest << " and " << second_smallest
             << " -> Cost: " << merge_cost << endl;
        cout << "  Current total cost: " << totalCost << endl;

        priority_queue<int, vector<int>, greater<int>> tempHeap = minHeap;
        cout << "  Heap state: ";
        while (!tempHeap.empty())
        {
            cout << tempHeap.top() << " ";
            tempHeap.pop();
        }
        cout << "\n\n";
    }

    return totalCost;
}

int main()
{
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of files must be a positive integer." << endl;
        return 1;
    }

    vector<int> files(n);

    cout << "Enter the sizes of the " << n << " files separated by spaces:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> files[i];
        if (files[i] <= 0)
        {
            cout << "File sizes must be positive integers." << endl;
            return 1;
        }
    }

    int cost = optimalMerge(files);
    cout << "Total cost for optimal merge: " << cost << endl;

    return 0;
}