void swap (int *A, int *B, int *C){
    int temp;
    temp = *A;
    *A = *B;
    *B = *C;
    *C = temp;
} 