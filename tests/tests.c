#include <stdio.h>
#include <stdlib.h>
#include "../Matrix.c"
#include "../Matrix_complex.c"
#include "../Matrix_float.c"
#include "../Matrix_int.c"

void test1() {
    int width_1 = 2, width_2 = 2, height_1 = 2, height_2 = 2;
    float testIn_1[4] = {1.0, 2.0, 3.0, 4.0};
    float testIn_2[4] = {4.0, 3.0, 2.0, 1.0};
    float testOut[4] = {5.0, 5.0, 5.0, 5.0};
    matrixmeta *matrixmeta_float_1 = init_matrixmeta_float();
    Matrix *a = matrixmeta_float_1->set_from_arr(height_1, width_1, testIn_1, matrixmeta_float_1);
    Matrix *b = matrixmeta_float_1->set_from_arr(height_2, width_2, testIn_2, matrixmeta_float_1);
    Matrix *t = matrixmeta_float_1->set_from_arr(2, 2, testOut, matrixmeta_float_1);
    Matrix *c = a->meta->sum(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_1: pass\n");
    } else {
        printf("\ntest_1: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_float_1);
}

void test2() {
    int width_1 = 2, width_2 = 2, height_1 = 3, height_2 = 3;
    complex testIn_1[12] = {99.0, 1.0, 88.0, 2.0, 77.0, 3.0, 66.0, 4.0, 55.0, 5.0, 44.0, 4.0};
    complex testIn_2[12] = {33.0, 3.0, 22.0, 2.0, 11.0, 1.0, 0.0, 0.0, -11.0, -1.0, -22.0, -2.0};
    complex testOut[12] = {132.0, 4.0, 110.0, 4.0, 88.0, 4.0, 66.0, 4.0, 44.0, 4.0, 22.0, 2.0};
    matrixmeta *matrixmeta_complex_1 = init_matrixmeta_complex();
    Matrix *a = matrixmeta_complex_1->set_from_arr(height_1, width_1, testIn_1, matrixmeta_complex_1);
    Matrix *b = matrixmeta_complex_1->set_from_arr(height_2, width_2, testIn_2, matrixmeta_complex_1);
    Matrix *t = matrixmeta_complex_1->set_from_arr(3, 2, testOut, matrixmeta_complex_1);
    Matrix *c = a->meta->sum(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_2: pass\n");
    } else {
        printf("\ntest_2: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_complex_1);
}



int main() {
    test1();
    //test2();

    return 0;
}