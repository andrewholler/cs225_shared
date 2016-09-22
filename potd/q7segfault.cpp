int main(){
    int * x = 0;    // equivalent to int * x = NULL;
    int y = *x;
    return 0;
}   // you cannot dereference null pointers, this leads to a segfault
