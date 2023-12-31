void ssort(int arr[], int n);
void swap(int *a, int *b);

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = NULL;

    ssort(nums, numsSize);

    int maxTrip = numsSize * numsSize;
    result = (int **)malloc(maxTrip * sizeof(int*));
    *returnColumnSizes = (int *)malloc(maxTrip * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < numsSize - 2; i++)
    {
        if(i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int left = i + 1;
            int right = numsSize - 1;
            int target = -nums[i];

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    result[*returnSize] = (int *)malloc(3 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[left];
                    result[*returnSize][2] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    result = (int **)realloc(result, (*returnSize) * sizeof(int*));
    *returnColumnSizes = (int *)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));

    return result;
}

void ssort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}