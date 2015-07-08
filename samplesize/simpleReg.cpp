//
//  simpleReg.cpp
//  samplesize
//
//  Created by Fredrik on 17/06/15.
//  Copyright (c) 2015 fredrik. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "simpleReg.h"
using namespace std;

slReg::slReg(int i){
    size = i;
    arrX = new double [size];
    arrY = new double [size];
}

int slReg::getSize(){
    return size;
}

double slReg::squares(double data1, double data2){

    double value = pow( data1  - data2 ,2);
    
    return value;
}

double slReg::average(double *data){
    double value = 0.0;
    for (int i; i < size; i++) {
        value = value + data[i];
    }
    return ( value / size );
}

double slReg::sumVarXtimesVarY(double *data1, double *data2){
    double value = 0.0;
    
    for (int i; i < size; i++) {
        value = value + data1[i] * data2[i];
    }
    
    return value;
}

double slReg::sumOfVariable(double *data1){
    double value = 0.0;
    for (int i = 0; i < size; i++) {
        value = value + data1[i];
    }
    return value;
}

void slReg::averageX(){
    valMeanX = average(arrX);
}

void slReg::averageY(){
    valMeanY = average(arrY);
}

void slReg::sumXX(){
    valSumXX = sumVarXtimesVarY(arrX, arrX);
}

void slReg::sumXY(){
    valSumXY = sumVarXtimesVarY(arrX, arrY);
}

void slReg::sumYY(){
    valSumYY = sumVarXtimesVarY(arrY, arrY);
}

void slReg::sumX(){
    valSumX = sumOfVariable(arrX);
}

void slReg::sumY(){
    valSumY = sumOfVariable(arrY);
}

void slReg::estimators(){
    valM = ( size * ( valSumXY ) -  valSumX * valSumY) / ( size * ( valSumXX ) - valSumX * valSumX );
    valB = ( ( valSumX * valSumX * valMeanY ) - valSumXY * valSumX  ) / ( size * ( valSumXX ) - valSumX * valSumX );
}

double slReg::functionY( double x ){
    return (valM * x + valB);
}

void slReg::constructEstimatedArray(){
    for (int i = 0; i < size; i++) {
        arrEstY[i] = functionY( arrX[i] );
    }
}

double slReg::sumVarXminusVarYsquared(double *data1, double *data2){
    
    double value = 0.0;
    
    for (int i = 0; i < size; i++) {
        value = value + pow( ( data1[i] - data2[i] ) ,2);
    }
    
    return value;
    
}

double slReg::sumVarXminusVarYsquared(double *data1, double k){
    
    double value = 0.0;
    
    for (int i = 0; i < size; i++) {
        value = value + pow( ( data1[i] - k ) ,2);
    }
    
    return value;
    
}

double slReg::sumXminAvgXtimesYminAvgY(double *data1, double *data2){
    double value = 0.0;
    
    for (int i = 0; i < size; i++) {
        value = value + ( (data1[i] - valMeanX) * (data2[i]-valMeanY) );
    }
    
    return value;
}

void slReg::sumYminfYsquared(){
    valSumYfY = sumVarXminusVarYsquared(arrY, arrEstY);
    valSSyOfx = valSumYfY / (size-2);
}

void slReg::sumXminAvgXsquared(){
    valSSxx = sumVarXminusVarYsquared(arrX, valMeanX);
}

void slReg::sumYminAvgYsquared(){
    valSSxy = sumXminAvgXtimesYminAvgY(arrX, arrY);
}

void slReg::stdSlope(){
    valSSm = valSSyOfx * valSSyOfx / valSSxx;
}


void slReg::stdIntercept(){
    valSSb = valSSyOfx * valSSyOfx * valSumXX / (size * valSSxx);
}








