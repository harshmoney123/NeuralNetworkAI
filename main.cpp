#define WIN32_LEAN_AND_MEAN
 
#include <stdlib.h>
#include <time.h>


#include "utils.h"
#include "resource.h"
#include "CParams.h"
#include "CNeuralNet.h"
#include <vector>

using namespace std;

///////////////////////GLOBALS ////////////////////////////////////

string			szApplicationName = "Smart Sweepers v1.0";
string			szWindowClassName = "sweeper";


//create an instance of the parameter class.
CParams   g_Params;

int main() {
    CNeuralNet testNet;
    vector<double> weights = testNet.GetWeights();
    
    return 0;
};
// end WinMain



