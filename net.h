#ifndef __NET_H__
#define __NET_H__

int main();

typedef struct Matrix{
	int m;
	int n;
	float **array;
} Matrix;

void exception(const char * message);

Matrix *new_matrix(int m, int n);

void set_mat(Matrix *mat, float value);

void sclr_mult(Matrix *mat, float scalar);

void prnt_mat(Matrix *mat);

Matrix *dot(Matrix *mat1, Matrix *mat2);

Matrix *transpose(Matrix *mat);

Matrix * mat_sum(Matrix *mat, int axis);

#endif
