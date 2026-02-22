void moveZeroes(int* nums, int numsSize) {
    int lastNonZero = 0; // Index to place the next non-zero element

    // Move all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[lastNonZero] = nums[i];
            lastNonZero++;
        }
    }

    // Fill the remaining positions with 0
    for (int i = lastNonZero; i < numsSize; i++) {
        nums[i] = 0;
    }
}
