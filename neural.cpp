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
    ReLU activate;
    Dense_Layer layer(5, 5);
    Matrix * in_mat = rand_mat(1,5);
    layer.forward(in_mat);
    activate.forward(layer.get_output());
    prnt_mat(activate.get_output());
}