#ifndef MATRICES_HPP_
#define MATRICES_HPP_

typedef struct Matrix{
	int m;
	int n;
	float **array;
} Matrix;

void exception(const char * message);

Matrix *new_matrix(int m, int n);

Matrix * set_mat(Matrix *mat, float value);

Matrix *rand_mat(int m, int n);

void sclr_mult(Matrix *mat, float scalar);

void prnt_mat(Matrix *mat);

Matrix *dot(Matrix *mat1, Matrix *mat2);

Matrix *transpose(Matrix *mat);

Matrix * mat_sum(Matrix *mat, int axis);

Matrix * add_mats(Matrix * mat1, Matrix * mat2);

Matrix * mat_max(Matrix * mat, float thresh);

void init_mat_gen();

#endif
