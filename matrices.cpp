#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrices.hpp"

void exception(const char * message){
	printf("Error: %s. Quiting execution...\n", message);
	exit(-1);
}

Matrix *new_matrix(int m, int n){
	float **arr;
	arr = (float**)malloc(m*sizeof(float*));
	for(int i = 0; i < m; i++){
		arr[i] = (float*)malloc(n*sizeof(float));
	}
	struct Matrix *mat = (struct Matrix*)malloc(sizeof(struct Matrix));
	mat->array = arr;
	mat->m = m;
	mat->n = n;
	return mat;
}

Matrix * set_mat(Matrix *mat, float value){
	int m = mat->m;
	int n = mat->n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			mat->array[i][j] = value;
		}
	}
	return mat;
}

Matrix *rand_mat(int m, int n){
	float **arr;
	arr = (float**)malloc(m*sizeof(float*));
	for(int i = 0; i < m; i++){
		arr[i] = (float*)malloc(n*sizeof(float));
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			arr[i][j] = (float)rand()/(float)RAND_MAX;
		}
	} 
	struct Matrix *mat = (struct Matrix*)malloc(sizeof(struct Matrix));
	mat->array = arr;
	mat->m = m;
	mat->n = n;
	return mat;
}

void sclr_mult(Matrix *mat, float scalar){
	int m = mat->m;
	int n = mat->n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			mat->array[i][j] *= scalar;
		}
	} 
}

void prnt_mat(Matrix *mat){
	int m = mat->m;
	int n = mat->n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%f", mat->array[i][j]);
			printf("\t");
		}
		printf("\n");
	} 
}

Matrix *dot(Matrix *mat1, Matrix *mat2){
	if(mat1->n != mat2->m){
		exception("Matrices dimensions not multiplyable");
	}
	float **arr;
	arr = (float**)malloc(mat1->m*sizeof(float*));
	for(int i = 0; i < mat1->m; i++){
		arr[i] = (float*)malloc(mat2->n*sizeof(float));
	}
	for(int i = 0; i < mat1->m; i++){
		for(int j = 0; j < mat2->n; j++){
			arr[i][j] = 0;
			for(int k = 0; k < mat2->m; k++){
				arr[i][j] += (mat1->array[i][k]*mat2->array[k][j]);
			}
		}
	}
	struct Matrix *res_mat = (struct Matrix*)malloc(sizeof(struct Matrix));
	res_mat->array = arr;
	res_mat->m = mat1->m;
	res_mat->n = mat2->n;
	return res_mat;
}

Matrix *transpose(Matrix *mat){
	int m = mat->m;
	int n = mat->n;
	Matrix *ret_mat = new_matrix(n, m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ret_mat->array[j][i] = mat->array[i][j];
		}
	}
	return ret_mat;
}

Matrix * mat_sum(Matrix *mat, int axis){ 
	/*
	Axis 0: Sums across rows to create a 1 column by n row matrix
	Axis 1: Sums down columns to create a 1 row by by n column matrix
	Axis 2: Sums together all rows and columns to result a 1x1 matrix
	*/
	if(axis < 0 || axis > 2){
		exception("Axis must be on range [0,2]");
	}
	if(axis == 0){
		Matrix *ret_mat = new_matrix(mat->m, 1);
		for(int i = 0; i < mat->m; i++){
			float temp_sum = 0.0;
			for(int j = 0; j < mat->n; j++){
				temp_sum += mat->array[i][j];
			}
			ret_mat->array[i][0] = temp_sum;
		}
		return ret_mat;
	}
	if(axis == 1){
		Matrix *ret_mat = new_matrix(1, mat->n);
		for(int j = 0; j < mat->n; j++){
			float temp_sum = 0.0;
			for(int i = 0; i < mat->m; i++){
				temp_sum += mat->array[i][j];
			}
			ret_mat->array[0][j] = temp_sum;
		}
		return ret_mat;
	}
	if(axis == 2){
		float sum = 0.0;
		for(int i = 0; i < mat->m; i++){
			for(int j = 0; j < mat->n; j++){
				sum += mat->array[i][j];
			}
		}
		Matrix *ret_mat = new_matrix(1, 1);
		ret_mat->array[0][0] = sum;
		return ret_mat;
	}
	return nullptr;
}

Matrix * add_mats(Matrix * mat1, Matrix * mat2){
	if(mat1->m != mat2->m || mat2->n != mat2->n){
		exception("Matrices must have same dims to add");
	}
	else{
		Matrix * res_mat = new_matrix(mat1->m, mat1->n);
		for(int i = 0; i < mat1->m; i++){
			for(int j = 0; j < mat1->n; j++){
				res_mat->array[i][j] = mat1->array[i][j] + mat2->array[i][j];
			}
		}
		return res_mat;
	}
	return nullptr;
}
// returns larger of two, either threshold or the matrix value
Matrix * mat_max(Matrix * mat, float thresh){
	int m = mat->m;
	int n = mat->n;
	Matrix * ret_mat = new_matrix(m, n);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(mat->array[i][j] > thresh){
				ret_mat->array[i][j] = mat->array[i][j];
			}
			else{
				ret_mat->array[i][j] = thresh;
			}
		}
	}
	return ret_mat;
}

void init_mat_gen(){
	srand(time(NULL));
}