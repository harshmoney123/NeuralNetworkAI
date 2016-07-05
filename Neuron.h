//
//  Neuron.hpp
//  MachineLearningTutorial
//
//  Created by Harsha Vankayalapati on 6/28/16.
//  Copyright © 2016 Harsha Vankayalapati. All rights reserved.
//

#ifndef Neuron_h
#define Neuron_h

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>

using namespace std;

// Connection Struct
struct Connection
{
    double weight;
    double deltaWeight;
};

// Neuron Class
class Neuron;
typedef vector<Neuron> Layer;

class Neuron
{
private:
    double eta; // [0.0...1.0] overall net training rate
    double alpha; // [0.0...n] multiplier of last weight change [momentum]
    static double transferFunction(double x);
    static double transferFunctionDerivative(double x);
    static double randomWeight(void) {
        return rand() / double (RAND_MAX);
    }
    double sumDOW(const Layer &nextLayer) const;
    double m_outputVal;
    vector<Connection> m_outputWeights;
    size_t m_myIndex;
    double m_gradient;
public:
    Neuron(size_t numOutputs, size_t myIndex);
    void setOutputVal(double val) { m_outputVal = val; }
    double getOutputVal(void) const { return m_outputVal; }
    void feedForward(const Layer &prevLayer);
    void calcOutputGradients(double targetVal);
    void calcHiddenGradients(const Layer &nextLayer);
    void updateInputWeights(Layer &prevLayer);
    void setEta(double newEta);
    void setAlpha(double newAlpha);
};


#endif /* Neuron_hpp */
