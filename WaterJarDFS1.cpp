#include <bits/stdc++.h>
using namespace std;

// Depth-First Search (DFS) function to find a solution
bool dfs(pair<int, int> curr, pair<int, int> end, vector<pair<int, int>> vec, set<pair<int, int>> &vis, int depth)
{
    // Optional depth limit (uncomment if needed)
    // if (depth > 10)
    //     return false;

    bool ans = false; // To track if a solution is found
    int x = curr.first; // Current state of the first jug
    int y = curr.second; // Current state of the second jug
    vis.insert(curr); // Mark the current state as visited

    // Check if the current state matches the target state
    if (curr == end)
    {
        cout << "Possible solution:" << endl;
        for (auto it : vec) // Print the path leading to the solution
            cout << it.first << " " << it.second << endl;
        return true; // Solution found
    }

    // Generate and explore possible moves from the current state

    // Move 1: Fill the first jug to its capacity (4 liters)
    if (x < 4)
    {
        pair<int, int> node = {4, y};
        if (!vis.count(node)) // Check if the state is not visited
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1)) // Recur for the new state
                ans = true;
            vec.pop_back(); // Backtrack
        }
    }

    // Move 2: Fill the second jug to its capacity (3 liters)
    if (y < 3)
    {
        pair<int, int> node = {x, 3};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }

    // Move 3: Empty the first jug
    if (x > 0)
    {
        pair<int, int> node = {0, y};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }

    // Move 4: Empty the second jug
    if (y > 0)
    {
        pair<int, int> node = {x, 0};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }

    // Move 5: Pour water from the second jug to the first jug until the first jug is full
    if (x + y >= 4 && y > 0)
    {
        pair<int, int> node = {4, y - (4 - x)};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }

    // Move 6: Pour water from the first jug to the second jug until the second jug is full
    if (x + y >= 3 && x > 0)
    {
        pair<int, int> node = {x - (3 - y), 3};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }

    // Move 7: Pour all water from the second jug into the first jug
    if (x + y <= 4 && y > 0)
    {
        pair<int, int> node = {x + y, 0};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }

    // Move 8: Pour all water from the first jug into the second jug
    if (x + y <= 3 && x > 0)
    {
        pair<int, int> node = {0, x + y};
        if (!vis.count(node))
        {
            vec.push_back(node);
            if (dfs(node, end, vec, vis, depth + 1))
                ans = true;
            vec.pop_back();
        }
    }

    return ans; // Return if a solution is found or not
}

int main()
{
    // Initial state (start) and target state (end)
    pair<int, int> start = {0, 0};
    pair<int, int> end = {2, 0};

    // Vector to store the path of the solution
    vector<pair<int, int>> ans;

    // Set to store visited states
    set<pair<int, int>> vis;

    // Call DFS to find the solution
    if (!dfs(start, end, ans, vis, 0))
        cout << "No possible solution." << endl; // Print if no solution is found

    return 0; // Program ends
}
