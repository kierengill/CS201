void plusminus (int *x, int *y){
    int sum, difference;
    sum = *x + *y;
    difference = *x - *y;
    *x = sum;
    *y = difference;
} 