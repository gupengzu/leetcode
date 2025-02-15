#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int len = gas.size();
        int total_tank = 0;
        int curr_tank = 0;
        int starting_station = 0;
        for (int i = 0; i < len;i++)
        {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            if(curr_tank<0)
            {
                starting_station = i + 1;
                curr_tank = 0;
            }
        }
        return total_tank >= 0 ? starting_station : -1;
    }
};

int main() {
    Solution solution;
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Test Case 1: " << solution.canCompleteCircuit(gas1, cost1) << endl; // Expected output: 3

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Test Case 2: " << solution.canCompleteCircuit(gas2, cost2) << endl; // Expected output: -1

    vector<int> gas3 = {5, 1, 2, 3, 4};
    vector<int> cost3 = {4, 4, 1, 5, 1};
    cout << "Test Case 3: " << solution.canCompleteCircuit(gas3, cost3) << endl; // Expected output: 4

    vector<int> gas4 = {1, 2, 3, 4, 5};
    vector<int> cost4 = {1, 2, 3, 4, 5};
    cout << "Test Case 4: " << solution.canCompleteCircuit(gas4, cost4) << endl; // Expected output: 0

    vector<int> gas5 = {3, 1, 1};
    vector<int> cost5 = {1, 2, 2};
    cout << "Test Case 5: " << solution.canCompleteCircuit(gas5, cost5) << endl; // Expected output: 0

    return 0;
}