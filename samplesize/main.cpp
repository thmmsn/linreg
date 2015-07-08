//
//  main.cpp
//  samplesize
//
//  Created by Fredrik on 16/06/15.
//  Copyright (c) 2015 fredrik. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "simpleReg.h"

using namespace std;

int main() {
    double val;
    slReg::slReg data(10);
    
    cout << "Set X-values" << endl;
    for (int i = 0; i < data.getSize(); i++) {
        cin >> val;
        data.setX(i, val);
    }

    cout << "Set corresponding Y-values" << endl;
    for (int i = 0; i < data.getSize(); i++) {
        cin >> val;
        data.setY(i, val);
    }
    
    data.valuesOut();
    
    
    
    
}
