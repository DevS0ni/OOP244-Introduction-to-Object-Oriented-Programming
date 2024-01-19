//Consider the following function, which calculates and returns the multiplication of the set of values 
//pointed to by x.

double mult(const double* x, int n)

{

    double mult = 1.0;

    for (int i = 0; i < n; i++)

        mult *= x[i];

    return mult;

}



Q. Write a function template that extends this definition to any fundamental type.














/*
template <typename T>
T mult(const T* x, int n)

{

    T mult = 1.0;

    for (int i = 0; i < n; i++)

        mult *= x[i];

    return mult;

}











*/