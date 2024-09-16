# Neural Network from Scratch

## Overview

This project implements a basic neural network from scratch, based on Chapter 1 of Michael Nielsen’s *Neural Networks and Deep Learning*. The goal of this project is to recognize handwritten digits from a dataset similar to the MNIST dataset.

## Concepts

### 1. Perceptrons
They take multiple inputs, multiply each by a weight, and pass the result through an activation function to produce an output.

### 2. Sigmoid Neurons
Instead of using simple step functions like perceptrons, the network uses sigmoid neurons. The sigmoid function outputs values between 0 and 1, which makes the network's output smoother and more adaptable.

### 3. Layers
The network is structured in layers. The input layer receives the data, hidden layers, and the output layer provides the final decision . 

### 4. Cost Function
The cost function measures the difference between the predicted outputs and the actual labels. This helps the network learn by adjusting the weights to minimize this error over time.

### 5. Learning Process
The network learns through a process called backpropagation, which adjusts the weights based on the error calculated from the cost function. This is done over many iterations (or epochs), gradually improving the accuracy of the network.


