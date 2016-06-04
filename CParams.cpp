#include "CParams.h"
#include <iostream>

//because we will always be loading in the settings from an ini file
//we can just initialize everything to zero
double CParams::dPi                 = 3.14159265358979;
double CParams::dHalfPi             = dPi / 2;
double CParams::dTwoPi              = dPi * 2;
int CParams::WindowWidth            = 400;
int CParams::WindowHeight           = 400;
int CParams::iFramesPerSecond       = 0;
int CParams::iNumInputs             = 0;
int CParams::iNumHidden             = 0;
int CParams::iNeuronsPerHiddenLayer = 0;
int CParams::iNumOutputs            = 0;
double CParams::dActivationResponse = 0;
double CParams::dBias               = 0;
double CParams::dMaxTurnRate        = 0;
double CParams::dMaxSpeed           = 0;
int CParams::iSweeperScale          = 0;
int CParams::iNumSweepers           = 0;
int CParams::iNumMines              = 0;
int CParams::iNumTicks              = 0;
double CParams::dMineScale          = 0;
double CParams::dCrossoverRate      = 0;
double CParams::dMutationRate       = 0;
double CParams::dMaxPerturbation    = 0;
int CParams::iNumElite              = 0;
int CParams::iNumCopiesElite        = 0;

//this function loads in the parameters from a given file name. Returns
//false if there is a problem opening the file.
bool CParams::LoadInParameters(string szFileName)
{
    ifstream infile;
    infile.open("params.txt");
    if (infile.fail()) {
        throw invalid_argument("Cannot find file");
    }

    //load in from the file
    infile >> iFramesPerSecond;
    infile >> iNumInputs;
    infile >> iNumHidden;
    infile >> iNeuronsPerHiddenLayer;
    infile >> iNumOutputs;
    infile >> dActivationResponse;
    infile >> dBias;
    infile >> dMaxTurnRate;
    infile >> dMaxSpeed;
    infile >> iSweeperScale;
    infile >> iNumMines;
    infile >> dMineScale;
    infile >> dCrossoverRate;
    infile >> dMutationRate;
    infile >> dMaxPerturbation;
    infile >> iNumElite;
    infile >> iNumCopiesElite;

  return true;
}

//iFramesPerSecond 60
//iNumInputs 4
//iNumHidden 1
//iNeuronsPerHiddenLayer 6
//iNumOutputs 2
//dActivationResponse 1
//dBias -1
//dMaxTurnRate 0.3
//dMaxSpeed 2
//iSweeperScale 5
//iNumMines 40
//iNumSweepers 30
//iNumTicks 2000
//dMineScale 2
//dCrossoverRate 0.7
//dMutationRate 0.1
//dMaxPerturbation 0.3
//iNumElite 4
//iNumCopiesElite 1





  
  
