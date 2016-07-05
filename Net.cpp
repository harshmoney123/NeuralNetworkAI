//
//  Net.cpp
//  MachineLearningTutorial
//
//  Created by Harsha Vankayalapati on 6/28/16.
//  Copyright © 2016 Harsha Vankayalapati. All rights reserved.
//

#include "Net.h"
#include "Neuron.h"

void Net::getResults(vector<double> &resultVals) const
{
    resultVals.clear();
    
    for (size_t n = 0; n < m_layers.back().size() - 1; ++n) {
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }
}

void Net::backProp(const vector<double> &targetVals)
{
    numOfBackProps++;
    // Calculate overall net error (RMS of output neuron errors)
    
    Layer &outputLayer = m_layers.back();
    double originalError = m_error;
    m_error = 0.0;
    
    for (size_t n = 0; n < outputLayer.size() - 1; ++n) {
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }
    m_error /= outputLayer.size() - 1; // get average error squared
    m_error = sqrt(m_error); // RMS
    
    // Implement a recent average measurement
    
    m_overallError += m_error;
    m_recentAverageError = m_overallError / numOfBackProps;
    
    double errorDiff = m_error - originalError;
    etaValUpdate(errorDiff);
    alphaValUpdate(errorDiff);
    
    // Calculate output layer gradients
    
    for (size_t n = 0; n < outputLayer.size() - 1; ++n) {
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }
    
    // Calculate hidden layer gradients
    
    for (size_t layerNum = m_layers.size() - 2; layerNum > 0; --layerNum) {
        Layer &hiddenLayer = m_layers[layerNum];
        Layer &nextLayer = m_layers[layerNum + 1];
        
        for (size_t n = 0; n < hiddenLayer.size(); ++n) {
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }
    
    // For all layers from outputs to first hidden layer,
    // update connection weights
    
    for (size_t layerNum = m_layers.size() - 1; layerNum > 0; --layerNum) {
        Layer &layer = m_layers[layerNum];
        Layer &prevLayer = m_layers[layerNum - 1];
        
        for (size_t n = 0; n < layer.size() - 1; ++n) {
            layer[n].updateInputWeights(prevLayer);
        }
    }
    for (size_t layerNum = 0; layerNum < m_layers.size()-1; layerNum++) {
        Layer &layer = m_layers[layerNum];
        for (size_t n = 0; n < layer.size() - 1; n++) {
            layer[n].setEta(overallEta);
            layer[n].setAlpha(overallAlpha);
        }
    }
}

void Net::feedForward(const vector<double> &inputVals)
{
    assert(inputVals.size() == m_layers[0].size() - 1);
    
    // Assign (latch) the input values into the input neurons
    for (size_t i = 0; i < inputVals.size(); ++i) {
        m_layers[0][i].setOutputVal(inputVals[i]);
    }
    
    // forward propagate
    for (size_t layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
        Layer &prevLayer = m_layers[layerNum - 1];
        for (size_t n = 0; n < m_layers[layerNum].size() - 1; ++n) {
            m_layers[layerNum][n].feedForward(prevLayer);
        }
    }
}

Net::Net(const vector<size_t> &topology)
{
    size_t numLayers = topology.size();
    overallEta = 0.2;
    overallAlpha = 0.3;
    
    for (size_t layerNum = 0; layerNum < numLayers; ++layerNum) {
        m_layers.push_back(Layer());
        size_t numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
        
        // We have a new layer, now fill it with neurons, and
        // add a bias neuron in each layer.
        for (size_t neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
            m_layers.back().push_back(Neuron(numOutputs, neuronNum));
            m_layers[layerNum][neuronNum].setEta(overallEta);
            m_layers[layerNum][neuronNum].setAlpha(overallAlpha);
            cout << "Made a Neuron!" << endl;
        }
        
        // Force the bias node's output to 1.0 (it was the last neuron pushed in this layer):
        m_layers.back().back().setOutputVal(1.0);
        m_layers.back().back().setAlpha(overallAlpha);
        m_layers.back().back().setEta(overallEta);
    }
    numOfBackProps = 0;
}

void Net::setOverallAlpha(double newAlpha) {
    overallAlpha = newAlpha;
}

void Net::setOverallEta(double newEta) {
    overallEta = newEta;
}

void Net::etaValUpdate(double errorDiff) {
    if (overallEta + errorDiff < 0) {
        overallEta = 0;
    } else if(overallEta + errorDiff > 1) {
        overallEta = 1;
    } else {
    overallEta += (errorDiff/numOfBackProps);
    }
}

void Net::alphaValUpdate(double errorDiff) {
    if (overallAlpha + errorDiff < 0) {
        overallAlpha = 0;
    } else if(overallAlpha + errorDiff > 1) {
        overallAlpha = 1;
    } else {
        overallAlpha += (errorDiff/numOfBackProps);
    }
}

double Net::calcErrorDiff() {
    return 0.0;
}