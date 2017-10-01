#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) { // O(n)
    vector<int> result;
    unordered_map <int, int> mp;
    for (int i = 0; i < nums.size(); i++) { // O(n)
        mp[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) { // O(n)
        int temp = target - nums[i];
        if (mp.find(temp) != mp.end() && mp[temp] != i) { // O(1)
            result.push_back(i);
            result.push_back(mp[temp]);
            return result;
        }
    }
    return result;
}

int main() {
    // test case 1
    vector<int> vc, result;
    vc.push_back(2);
    vc.push_back(7);
    vc.push_back(11);
    vc.push_back(15);
    result = twoSum(vc, 9);
    for (int i = 0; i < result.size(); i++) { // expect [0, 1]
        cout << result[i] << ' ';
    }
    
    cout << endl;
    
    // test case 2
    vc.clear();
    vc.push_back(4);
    //vc.push_back(4);
    vc.push_back(2);
    vc.push_back(6);
    result = twoSum(vc, 8);
    for (int i = 0; i < result.size(); i++) { // expect [0, 1]
        cout << result[i] << ' ';
    }
    return 0;
}
