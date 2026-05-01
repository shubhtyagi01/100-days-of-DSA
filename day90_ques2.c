int canSplit(int* nums, int numsSize, int k, long long maxSum) {
    int count = 1;
    long long currSum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (currSum + nums[i] > maxSum) {
            count++;
            currSum = nums[i];
        } else {
            currSum += nums[i];
        }
    }

    return count <= k;
}

int splitArray(int* nums, int numsSize, int k) {
    long long low = nums[0], high = 0, ans = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)ans;
}
