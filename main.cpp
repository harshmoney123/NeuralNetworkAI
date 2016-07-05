// neural-net-tutorial.cpp
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include "Neuron.h"
#include "Net.h"
#include "TrainingData.h"

using namespace std;

// This function shows the values of the vector
void showVectorVals(string label, vector<double> &v)
{
    cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    
    cout << endl;
}

int main()
{
    string fileName;
    cout << "Please input training data file name: ";
    cin >> fileName;
    TrainingData trainData(fileName);
    
    // e.g., { 3, 2, 1 }
    vector<size_t> topology;
    trainData.getTopology(topology);
    
    Net myNet(topology);
    
    vector<double> inputVals, targetVals, resultVals;
    int trainingPass = 0;
    
    while (!trainData.isEof()) {
        ++trainingPass;
        cout << endl << "Pass " << trainingPass;
        
        // Get new input data and feed it forward:
        if (trainData.getNextInputs(inputVals) != topology[0]) {
            break;
        }
        showVectorVals(": Inputs:", inputVals);
        myNet.feedForward(inputVals);
        
        // Collect the net's actual output results:
        myNet.getResults(resultVals);
        showVectorVals("Outputs:", resultVals);
        
        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals);
        assert(targetVals.size() == topology.back());
        
        myNet.backProp(targetVals);
        
        // Report how well the training is working, average over recent samples:
        cout << "Net recent average error: "
        << myNet.getRecentAverageError() << endl;
    }
    
    double oneValue;
    while (oneValue != 20) {
        inputVals.clear();
        string line;
        cout << endl << "please enter in string of input vals for testing: ";
        cin >> line;
        stringstream ss(line);
        while (ss >> oneValue) {
            inputVals.push_back(oneValue);
        }
        myNet.feedForward(inputVals);
        myNet.getResults(resultVals);
        showVectorVals("Outputs:", resultVals);
    }
    cout << endl << "Done" << endl;
}
