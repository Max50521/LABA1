#include <stdio.h>
#include <stdlib.h>
#include "Matrix.c"
#include "Matrix_complex.c"
#include "Matrix_float.c"
#include "Matrix_int.c"

int main() {
    int number;
    int Pause = 0;
    int type;
    int width_1;
    int height_1;
    int width_2;
    int height_2;
    Matrix *a;
    Matrix *b;
    matrixmeta *matrixmeta_complex = NULL;
    matrixmeta *matrixmeta_float = NULL;
    matrixmeta *matrixmeta_int = NULL;
    complex *put = NULL;
    float *put_f = NULL;
    int *put_i = NULL;
    int row;
    int *lambda;
    float *lambda_f;
    while (Pause == 0) {
        printf("For work with complex numbers choose 0, for work with float - 1,\nfor work with integer - 2 -> ");
        scanf("%d", &type);

        if ((type == 0) || (type == 1) || (type == 2)) {
            Pause = 1;
        } else {
            printf("Введите другое значение:\n");
        }
        while (Pause == 1) {
            printf("Enter the width of matrix 1 ->\n ");
            scanf("%d", &width_1);
            printf("Enter the height of matrix 1 ->\n ");
            scanf("%d", &height_1);
            printf("Enter the width of matrix 2 ->\n ");
            scanf("%d", &width_2);
            printf("Enter the height of matrix 2 ->\n ");
            scanf("%d", &height_2);
            if (width_1 > 0 && height_1 > 0 && width_2 > 0 && height_2 > 0) {
                Pause = 2;
            } else {
                printf("put another values:\n");
            }
        }
    }

    if (type == 0) {
        matrixmeta_complex = init_matrixmeta_complex();
        put = calloc(width_1 * height_1 + width_2 * height_2, sizeof(complex));
        for (int i = 0; i < width_1 * height_1; ++i) {
            printf("Enter real part complex:");
            scanf("%f", &put[i].real);
            printf("Enter imaginary part complex:");
            scanf("%f", &put[i].imag);
        }
        a = matrixmeta_complex->set_from_arr(height_1, width_1, put, matrixmeta_complex);
        printf("First Matrix\n");
        a->meta->print(a);
        for (int i = 0; i < width_2 * height_2; ++i) {
            printf("Enter real part complex:");
            scanf("%f", &put[i].real);
            printf("Enter imaginary part complex:");
            scanf("%f", &put[i].imag);
        }
        b = matrixmeta_complex->set_from_arr(height_2, width_2, put, matrixmeta_complex);
        printf("\nSecond Matrix\n");
        b->meta->print(b);
        printf("\n");

    } else if (type == 1) {
        matrixmeta_float = init_matrixmeta_float();
        put_f = calloc(width_1 * height_1 + width_2 * height_2, sizeof(float));
        for (int i = 0; i < width_1 * height_1; ++i) {
            printf("Enter float number:");
            scanf("%f", &put_f[i]);
        }
        a = matrixmeta_float->set_from_arr(height_1, width_1, put_f, matrixmeta_float);
        printf("First Matrix\n");
        a->meta->print(a);
        for (int i = 0; i < width_2 * height_2; ++i) {
            printf("Enter float number:");
            scanf("%f", &put_f[i]);
        }
        b = matrixmeta_float->set_from_arr(height_2, width_2, put_f, matrixmeta_float);
        printf("\nSecond Matrix\n");
        a->meta->print(b);
        printf("\n");

    } else if (type == 2) {
        matrixmeta_int = init_matrixmeta_int();
        put_i = calloc(width_1 * height_1 + width_2 * height_2, sizeof(int));
        for (int i = 0; i < width_1 * height_1; ++i) {
            printf("Enter int number:");
            scanf("%d", &put_i[i]);
        }
        a = matrixmeta_int->set_from_arr(height_1, width_1, put_i, matrixmeta_int);
        printf("First Matrix\n");
        a->meta->print(a);
        for (int i = 0; i < width_2 * height_2; ++i) {
            printf("Enter int number:");
            scanf("%d", &put_i[i]);
        }
        b = matrixmeta_int->set_from_arr(height_2, width_2, put_i, matrixmeta_int);
        printf("\nSecond Matrix\n");
        a->meta->print(b);
        printf("\n");


    }
    printf("\n");
    printf("Menu:\n1 -> Print Martix 1 again\n2 -> Print Matrix 2 again\n3 -> Sum Matrices\n4 -> Multiply matrices\n5 -> Transpose Matrix 1\n6 -> Transpose Matrix 2\n7 -> Transpose both Matrices\n8 -> Transpose sum of Matrices\n9 -> Transpose multiply of Matrices\n10 -> Add linear combination in matrix 1\n11 -> Add linear combination in matrix 2\n Else -> Exit\n");
    scanf("%d", &number);
    if (number == 1) {
        a->meta->print(a);
        printf("\nDone\n");
        a->meta->delete(a);
        b->meta->delete(b);
    }
    if (number == 2) {
        b->meta->print(b);
        printf("\nDone\n");
        a->meta->delete(a);
        b->meta->delete(b);
    }
    if (number == 3) {
        if (width_1 == width_2 && height_1 == height_2) {
            Matrix *c = a->meta->sum(a, b);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        } else {
            printf("\nImpossible to sum this Matrices\n");
            a->meta->delete(a);
            b->meta->delete(b);
        }

    }
    if (number == 4) {
        if (width_1 == height_2) {
            Matrix *c = a->meta->mult(a, b);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        } else {
            printf("\nImpossible to multiply this Matrices\n");
            a->meta->delete(a);
            b->meta->delete(b);
        }
    }
    if (number == 5) {
        Matrix *d = a->meta->trans(a);
        printf("\n");
        a->meta->print(d);
        printf("\nDone\n");
        a->meta->delete(a);
        b->meta->delete(b);
        d->meta->delete(d);
    }
    if (number == 6) {
        Matrix *l = a->meta->trans(b);
        printf("\n");
        a->meta->print(l);
        printf("\nDone\n");
        a->meta->delete(a);
        b->meta->delete(b);
        l->meta->delete(l);
    }
    if (number == 7) {
        Matrix *d = a->meta->trans(a);
        Matrix *l = a->meta->trans(b);
        printf("\n");
        a->meta->print(d);
        printf("\n");
        a->meta->print(l);
        printf("\nDone\n");
        a->meta->delete(a);
        b->meta->delete(b);
        d->meta->delete(d);
        l->meta->delete(l);

    }
    if (number == 8) {
        if (width_1 == width_2 && height_1 == height_2) {
            Matrix *c = a->meta->sum(a, b);
            Matrix *k = a->meta->trans(c);
            printf("\nYour sum\n");
            c->meta->print(c);
            printf("\nTransposed sum\n");
            k->meta->print(k);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
            k->meta->delete(k);

        } else {
            printf("\nImpossible to sum this Matrices\n");
            a->meta->delete(a);
            b->meta->delete(b);
        }

    }
    if (number == 9) {
        if (width_1 == height_2) {
            Matrix *c = a->meta->mult(a, b);
            Matrix *k = a->meta->trans(c);
            printf("\nYour multiply\n");
            c->meta->print(c);
            printf("\nTransposed multiply\n");
            k->meta->print(k);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
            k->meta->delete(k);
        } else {
            printf("\nImpossible to multiply this Matrices\n");
            a->meta->delete(a);
            b->meta->delete(b);
        }
    }
    if (number == 10) {                    //выбор добавления лин комбинации
        if (type == 2) {
            lambda = calloc(height_1, sizeof(int));
            printf("Enter a number of a row:");
            scanf("%d", &row);
            row=row-1;
            for (int i = 0; i < height_1; i++) {
              printf("Enter integer coefficient:");
              scanf("%d", &lambda[i]);
            }
            Matrix *c = a->meta->addLinComb(a, row, lambda);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
        if (type == 1){
            lambda_f = calloc( height_1, sizeof(float));
            printf("Enter a number of a row:");
            scanf("%d", &row);
            for (int i = 0; i < height_1; i++) {
                printf("Enter float coefficient:");
                scanf("%f", &lambda_f[i]);
            }
            Matrix *c = a->meta->addLinComb(a, row, lambda_f);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
    }
    if (number == 11) {
        if (type == 2) {
            lambda = calloc( height_2, sizeof(int)); //dimension_1
            printf("Enter a number of a row:");
            scanf("%d", &row);
            row=row-1;
            for (int i = 0; i < height_2; i++) { //dimension_1
                printf("Enter integer coefficient:");
                scanf("%d", &lambda[i]);
            }
            Matrix *c = b->meta->addLinComb(b, row, lambda);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
        if (type == 1){
            lambda_f = calloc( height_2, sizeof(float));//dimension_1
            printf("Enter a number of a row:");
            scanf("%d", &row);
            for (int i = 0; i < height_2; i++) {//dimension_1
                printf("Enter float coefficient:");
                scanf("%f", &lambda_f[i]);
            }
            Matrix *c = b->meta->addLinComb(b, row, lambda_f);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
    }else {
        printf("\nExit...\n");
        a->meta->delete(a);
        b->meta->delete(b);
        printf("Done\n");
    }
    free(matrixmeta_float);
    free(matrixmeta_complex);
    free(matrixmeta_int);
    free(put);
    free(put_f);
    free(lambda);
    free(lambda_f);
    return 0;
}