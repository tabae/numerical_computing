#ifndef __IDFT_HPP__
#define __IDFT_HPP__

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <complex>
#include "dft.hpp"

using namespace std;

template<class T>
vector<complex<T>> idft(const vector<complex<T>>& f_in) {
    const T pi = acos(-1);
    const int n_sample = f_in.size();
    vector<complex<T>> f_out(n_sample);
    for(int n = 0; n < n_sample; n++) {
        for(int k = 0; k < n_sample; k++) {
            complex<T> p(0, 2*pi/n_sample*k*n);
            f_out[n] += f_in[k] * exp(p);
        }
        f_out[n] /= n_sample;
    }
    return f_out;
}

bool idft_test() {
    bool res = true;
    const int n_sample = 200;
    const double pi = acos(-1);
    vector<complex<double>> f_in(n_sample);
    for(int j = 0; j < n_sample; j++) {
        for(int k = 0; k < n_sample; k++) {
            const double p = 2*pi*k*j/n_sample; 
            f_in[k] = complex<double>(cos(p), sin(p));
        }
        auto f_out = dft(f_in);
        auto f_in2 = idft(f_out);
        for(int k = 0; k < n_sample; k++) {
            if(abs(f_in[k] - f_in2[k]) > 1e-9) {
                cout << "[\e[0;31mFailed\e[0m]\t"; 
                cout << j << "," << k << ": " << f_in[k] << " " << f_in2[k] << endl;
                res = false;
            }
        }
    }
    if(res) cout << "[\e[0;32mSuccess\e[0m]\t"; 
    else cout << "[\e[0;31mFailed\e[0m]\t"; 
    cout << "idft_test" << endl;
    return res;
}

#endif
