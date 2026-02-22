int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0; // F(0)
    int b = 1; // F(1)
    int c = 0;

    for(int i = 2; i <= n; i++){
        c = a + b; // F(i) = F(i-1) + F(i-2)
        a = b;     // Shift for next iteration
        b = c;
    }

    return c;
}
