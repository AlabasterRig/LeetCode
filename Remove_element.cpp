#include <iostream>
#include <vector>
using namespace std;

int removeDuplicate(vector<int>& nums, int val)
{
    int i = 0, j = 0;

    while(j < nums.size())
    {
        if(nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    return i;
}

int main()
{
    vector<int> nums = {0,1,3,3,5,2,3,4};
    int val = 3;

    int result = removeDuplicate(nums, val);

    cout << "Modified Array";
    for(int i = 0; i < result; i++)
    {
        cout << nums[i] << " ";
    }
}