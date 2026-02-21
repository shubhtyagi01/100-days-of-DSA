int missingNum(int arr[], int n) {
    int xor_all = 0;
    int xor_arr = 0;

    // XOR from 1 to n+1
    for(int i = 1; i <= n + 1; i++) {
        xor_all ^= i;
    }

    // XOR all array elements
    for(int i = 0; i < n; i++) {
        xor_arr ^= arr[i];
    }

    return xor_all ^ xor_arr;
}
