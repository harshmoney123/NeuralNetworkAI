//
//  Net.hpp
//  MachineLearningTutorial
//
//  Created by Harsha Vankayalapati on 6/28/16.
//  Copyright © 2016 Harsha Vankayalapati. All rights reserved.
//

#ifndef Net_h
#define Net_h

#include <stdio.h>
#include "Neuron.h"

typedef vector<Neuron> Layer;

class Net
{
private:
    size_t numOfBackProps;
    double overallEta;
    double overallAlpha;
    vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
    double m_error;
    double m_overallError;
    double m_recentAverageError;
    void etaValUpdate(double errorDiff);
    void alphaValUpdate(double errorDiff);
public:
    Net(const vector<size_t> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector<double> &resultVals) const;
    double getRecentAverageError(void) const { return m_recentAverageError; }
    void setOverallEta(double newEta);
    void setOverallAlpha(double newAlpha);
    double calcErrorDiff();
};

#endif /* Net_h */
