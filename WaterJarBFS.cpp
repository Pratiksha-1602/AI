#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initial state (start) and target state (end)
    pair<int, int> start = {0, 0};
    pair<int, int> end = {2, 0};

    // Queue to hold the current state and the path taken to reach that state
    queue<pair<pair<int, int>, vector<pair<int, int>>>> q;

    // Initialize the queue with the start state and the initial path
    q.push({start, {{0, 0}}});

    // BFS loop
    while (!q.empty())
    {
        bool flag = false;  // Flag to check if the solution is found
        int size = q.size();  // Number of elements at the current BFS level

        // Process each element in the queue
        while (size--)
        {
            pair<int, int> curr = q.front().first;  // Current state
            vector<pair<int, int>> vec = q.front().second;  // Path to reach the current state
            int x = curr.first;  // First jug state
            int y = curr.second;  // Second jug state
            q.pop();  // Remove the current element from the queue

            // Check if the current state matches the end state
            if (curr == end)
            {
                cout << "Possible solution:" << endl;
                cout << "Jar 1 \t Jar 2" << endl;
                // Print the path taken to reach the solution
                for (auto it : vec)
                    cout << it.first << " \t " << it.second << endl;
                flag = true;  // Set the flag indicating solution found
                break;  // Exit the loop as the solution is found
            }

            // Generate possible moves from the current state
            // Move 1: Fill the first jug to its capacity (4 liters)
            if (x < 4)
            {
                pair<int, int> node = {4, y};  // New state after the move
                vec.push_back(node);  // Add new state to the path
                q.push({node, vec});  // Add new state and updated path to the queue
                vec.pop_back();  // Remove the last state to backtrack
            }
            // Move 2: Fill the second jug to its capacity (3 liters)
            if (y < 3)
            {
                pair<int, int> node = {x, 3};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            // Move 3: Empty the first jug
            if (x > 0)
            {
                pair<int, int> node = {0, y};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            // Move 4: Empty the second jug
            if (y > 0)
            {
                pair<int, int> node = {x, 0};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            // Move 5: Pour water from the second jug to the first jug until the first jug is full
            if (x + y >= 4 && y > 0)
            {
                pair<int, int> node = {4, y - (4 - x)};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            // Move 6: Pour water from the first jug to the second jug until the second jug is full
            if (x + y >= 3 && x > 0)
            {
                pair<int, int> node = {x - (3 - y), 3};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            // Move 7: Pour all water from the second jug into the first jug
            if (x + y <= 4 && y > 0)
            {
                pair<int, int> node = {x + y, 0};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
            // Move 8: Pour all water from the first jug into the second jug
            if (x + y <= 3 && x > 0)
            {
                pair<int, int> node = {0, x + y};
                vec.push_back(node);
                q.push({node, vec});
                vec.pop_back();
            }
        }

        // If the solution is found, exit the BFS loop
        if (flag)
            break;
    }
    return 0;  // Program ends
}
