/*
*
* Finite Impulse Response (FIR) Filter
*
* Implements a discrete-time FIR filter using a set of coefficients and a circular buffer.
* Transfer function in z-domain is as follows: G(z) = c_0 + c_1 * z^-1 + ... + c_(N-1) * z^(N-1)
* Where c_n is the n-th coefficient and N is the filter order.
* 
* Written by: Philip M. Salmony @ philsal.co.uk
* Last changed: 01 Dec 2019
*
*/

#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#include <stdint.h>

typedef struct {
    float out;
	float *coeff;
	float *buf;
	uint8_t order;
	uint8_t putIndex;
} FIRFilter ;

void FIRFilter_pressure_Init();

float FIRFilter_pressure_Update(float in);

void FIRFilter_temp_Init();

float FIRFilter_temp_Update(float in);

void FIRFilter_Init(FIRFilter *filt, float *coeff, float *buf, const uint8_t order);

float FIRFilter_Update(FIRFilter *filt, float in);

#endif
