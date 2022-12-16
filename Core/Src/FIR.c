/*
* Implements a discrete-time FIR filter using a set of coefficients and a circular buffer.
* Transfer function in z-domain is as follows: G(z) = c_0 + c_1 * z^-1 + ... + c_(N-1) * z^(N-1)
* Where c_n is the n-th coefficient and N is the filter order.
*
* Written by: Philip M. Salmony @ philsal.co.uk
* Last changed: 01 Dec 2019
*
*
* modified by Simon Engel
*/

#include "FIR.h"

float pressure_coeff[] = {0.25, 0.25, 0.25, 0.25};
float pressure_buf[4];
FIRFilter pressure_FIRFilter;

void FIRFilter_pressure_Init() {
	FIRFilter_Init(&pressure_FIRFilter, pressure_coeff, pressure_buf, 4);
}

float FIRFilter_pressure_Update(float in) {
	return FIRFilter_Update(&pressure_FIRFilter, in);
}

void FIRFilter_Init(FIRFilter *filt, float *coeff, float *buf, const uint8_t order) {
	filt->out = 0.0f;

	filt->coeff = coeff;
	filt->buf   = buf;
	filt->order = order;
	filt->putIndex = 0;

	for (uint8_t n = 0; n < order; n++) {
		filt->buf[n] = 0.0f;
	}
}

float FIRFilter_Update(FIRFilter *filt, float in) {
    /* Store newest input value in circular buffer */
    filt->buf[filt->putIndex] = in;

    /* Compute filter output */
    uint8_t getIndex = filt->putIndex;

    filt->out = 0.0f;
    for (uint8_t n = 0; n < filt->order; n++) {
        filt->out = filt->out + filt->coeff[n] * filt->buf[getIndex];

        if (getIndex == 0) {
            getIndex = filt->order - 1;
        } else {
           getIndex--;
        }
    }

    /* Increment buffer index */
    filt->putIndex++;
    if (filt->putIndex == filt->order) {
        filt->putIndex = 0;
    }

    /* Return output */
    return filt->out;
}


