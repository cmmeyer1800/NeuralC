#include <iostream>
#include <string>
#include <math.h>
#include "neural.hpp"
#include "matrices.hpp"

Dense_Layer::Dense_Layer(int n_inputs, int n_neurons){
    weights = rand_mat(n_inputs, n_neurons);
    biases = set_mat(new_matrix(1, n_neurons), 0.0);
}

Dense_Layer::Dense_Layer(Matrix *weights, Matrix *biases){
    weights = weights;
    biases = biases;
}

void Dense_Layer::forward(Matrix * inputs){
    Matrix *bef_bias = dot(inputs, weights);
    output = add_mats(bef_bias, biases);
}

Matrix * Dense_Layer::get_output(){
    return output;
}

void ReLU::forward(Matrix * input){
    output = mat_max(input, 0);
}

Matrix * ReLU::get_output(){
    return output;
}

int main(){
    init_mat_gen();
    Matrix * mat = rand_mat(1, 4);
    prnt_mat(mat);
    Matrix * mat2 = mat_max(mat, .5);
    prnt_mat(mat2);
}