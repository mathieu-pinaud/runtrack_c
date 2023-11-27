int sqrt(int n){
    int i = 0;
    while (i * i < n) {
        i += 1;
    }
    if (i * i == n)
        return (i);
    return (0);
}