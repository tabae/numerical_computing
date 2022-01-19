#ifndef __DFT_HPP__
#define __DFT_HPP__

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <complex>

using namespace std;

template<class T>
vector<complex<T>> dft(const vector<complex<T>>& f_in) {
    const T pi = acos(-1);
    const int n_sample = f_in.size();
    vector<complex<T>> f_out(n_sample);
    for(int k = 0; k < n_sample; k++) {
        for(int n = 0; n < n_sample; n++) {
            complex<T> p(0, -2*pi/n_sample*k*n);
            f_out[k] += f_in[n] * exp(p);
        }
    }
    return f_out;
}

bool dft_test(bool log = false) {
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
        for(int n = 0; n < n_sample; n++) {
            if(abs(f_out[n]) > 1e-9) {
                if(abs(abs(f_out[n]) - n_sample) < 1e-9 && j == n) {
                    if(log) cout << "[\e[0;32mSuccess\e[0m]\t"; 
                } else {
                    if(log) cout << "[\e[0;31mFailed\e[0m]\t"; 
                    res = false;
                }
                if(log) cout << j << "," << n << ": " << f_out[n] << endl;
            }
        }
    }
    if(res) cout << "[\e[0;32mSuccess\e[0m]\t"; 
    else cout << "[\e[0;31mFailed\e[0m]\t"; 
    cout << "dft_test" << endl;
    return res;
}

#endif