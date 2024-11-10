#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int optimalMerge(vector<int> &files)
{
    // Initialize min-heap priority queue with file sizes
    priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());
    int totalCost = 0;

    // Merge files until only one merged file remains
    while (minHeap.size() > 1)
    {
        // Extract two smallest elements
        int first_smallest = minHeap.top();
        minHeap.pop();
        int second_smallest = minHeap.top();
        minHeap.pop();

        // Calculate merge cost and add to total cost
        int merge_cost = first_smallest + second_smallest;
        totalCost += merge_cost;

        // Insert the merged file size back into the heap
        minHeap.push(merge_cost);
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
    cout << "Enter the sizes of the files:\n";
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
