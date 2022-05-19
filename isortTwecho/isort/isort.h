#ifndef _isort_H_
#define _isort_H_
__BEGIN_DECLS
int*  mkarr(int n); 
void sort_integer_array(int *begin, int *end, int ascending); 
void printarr( int *arr, int n);
void copyarrs(int *main, int *copy1, int *copy2, int n);
int comparatorA(const void *p, const void *q);
int comparatorD(const void *p, const void *q);
void isort(int n);
__END_DECLS

#endif 
