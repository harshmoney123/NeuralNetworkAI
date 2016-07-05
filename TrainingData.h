//
//  TrainingData.hpp
//  MachineLearningTutorial
//
//  Created by Harsha Vankayalapati on 6/28/16.
//  Copyright © 2016 Harsha Vankayalapati. All rights reserved.
//

#ifndef TrainingData_h
#define TrainingData_h

#include <stdio.h>
#include "Net.h"
#include <fstream>
#include <sstream>

class TrainingData
{
public:
    TrainingData(const string filename);
    bool isEof(void) { return m_trainingDataFile.eof(); }
    void getTopology(vector<size_t> &topology);
    
    // Returns the number of input values read from the file:
    size_t getNextInputs(vector<double> &inputVals);
    size_t getTargetOutputs(vector<double> &targetOutputVals);
    
private:
    ifstream m_trainingDataFile;
};


#endif /* TrainingData_h */
