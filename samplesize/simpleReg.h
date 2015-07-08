//
//  simpleReg.h
//  samplesize
//
//  Created by Fredrik on 17/06/15.
//  Copyright (c) 2015 fredrik. All rights reserved.
//

#pragma once

class slReg{
private:
    int size;
    
    double *arrX;
    double *arrY;
    double *arrEstY;
    
    // SOME VALUES
    
    double valMeanX;
    double valMeanY;
    double valSumX;     // sum( x, {0, n} )
    double valSumY;     // sum( y, {0, n} )
    double valSumXX;    // sum( x^2, {0, n} )
    double valSumXY;    // sum( x * y, {0, n} )
    double valSumYY;    // sum( y * y, {0, n} )
    double valSumYfY;   // sum( ( y - y(x) )^2, {0, n} )
    double valSSxx;     // Sum squared error of ( X - AvgX )^2
    double valSSxy;     // sum( (x-avgx)*(y-avgy), { 0 , n} )
    double valSSyOfx;     // Standard deviation of y(x) = m x + b
    double valSSm;      // Standard deviation of slope, m !!!! KVADRAT !!!!
    double valSSb;      // Standard devation of intercept, b
    
    // ESTIMATORS
    
    double valM;        // y(x) = funcM * x + funcB;
    double valB;
    
    // PRIVATE FUNCTIONS
    
    double squares(double data1, double data2);
    double average(double *data);
    double sumVarXtimesVarY(double *data1, double *data2);
    double sumVarXminusVarYsquared(double *data1, double *data2);
    double sumVarXminusVarYsquared(double *data1, double k);
    double sumXminAvgXtimesYminAvgY(double *data1, double *data2);
    double sumOfVariable(double *data1);
    double functionY( double x );
    
    void estimators();
    void constructEstimatedArray();
    void sumX();
    void sumY();
    void sumXX();
    void sumXY();
    void sumYY();
    void averageX();
    void averageY();
    void sumYminfYsquared();
    void sumXminAvgXsquared();
    void sumYminAvgYsquared();
    void stdSlope();
    void stdIntercept();

    
public:
    slReg(int i); // constructor size = i;
    int getSize(); //returns the size of the dataset
    void omniFunction();
    
};
