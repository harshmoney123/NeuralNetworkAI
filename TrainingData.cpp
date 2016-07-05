//
//  TrainingData.cpp
//  MachineLearningTutorial
//
//  Created by Harsha Vankayalapati on 6/28/16.
//  Copyright © 2016 Harsha Vankayalapati. All rights reserved.
//

#include "TrainingData.h"

void TrainingData::getTopology(vector<size_t> &topology)
{
    string line;
    string label;
    
    getline(m_trainingDataFile, line);
    stringstream ss(line);
    ss >> label;
    if (this->isEof() || label.compare("topology:") != 0) {
        abort();
    }
    
    while (!ss.eof()) {
        size_t n;
        ss >> n;
        topology.push_back(n);
    }
    
    return;
}

TrainingData::TrainingData(const string filename)
{
    m_trainingDataFile.open(filename.c_str());
}

size_t TrainingData::getNextInputs(vector<double> &inputVals)
{
    inputVals.clear();
    
    string line;
    getline(m_trainingDataFile, line);
    stringstream ss(line);
    
    string label;
    ss>> label;
    if (label.compare("in:") == 0) {
        double oneValue;
        while (ss >> oneValue) {
            inputVals.push_back(oneValue);
        }
    }
    
    return inputVals.size();
}

size_t TrainingData::getTargetOutputs(vector<double> &targetOutputVals)
{
    targetOutputVals.clear();
    
    string line;
    getline(m_trainingDataFile, line);
    stringstream ss(line);
    
    string label;
    ss>> label;
    if (label.compare("out:") == 0) {
        double oneValue;
        while (ss >> oneValue) {
            targetOutputVals.push_back(oneValue);
        }
    }
    
    return targetOutputVals.size();
}
