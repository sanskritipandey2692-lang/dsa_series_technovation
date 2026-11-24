
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 2; i++) {

        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while(left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0) {

                ans.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                while(left < right && nums[left] == nums[left - 1]) {
                    left++;
                }

                while(left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            }

            else if(sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets whose sum is zero are:" << endl;

    for(auto triplet : result) {
        cout << "[";
        for(int i = 0; i < 3; i++) {
            cout << triplet[i];
            if(i < 2) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
