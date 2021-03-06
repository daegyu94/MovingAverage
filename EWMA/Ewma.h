/*
 * EWMA Filter - Exponentially Weighted Moving Average filter used for smoothing data series readings.
 *
 *     output = alpha * reading + (1 - alpha) * lastOutput
 *
 * Where:
 *  -   alpha = factor greater than 0 and less or equal to 1
 *  -   reading = current input value
 *  -   lastOutput = last filter output value
 *  -   output = filter output value after the last reading
 */

#ifndef _EWMA_H_
#define _EWMA_H_

class Ewma {
    public:
        /* Current data output */
        double output = 0;
         /* Smoothing factor, in range [0,1]. Higher the value - less smoothing (higher the latest reading impact).*/
        double alpha = 0;

        /* Creates a filter without a defined initial output. The first output will be equal to the first input. */
        Ewma(double alpha) {
            this->alpha = alpha;
        }

        /* Creates a filter with a defined initial output. */
        Ewma(double alpha, double initialOutput) {
            this->alpha = alpha;
            this->output = initialOutput;
            this->hasInitial = true;
        }

        void reset() {
            this->hasInitial = false;
        }

        /*
         * Specifies a reading value.
         * @returns current output
         */
        double filter(double input) {
            if (hasInitial) {
                output = alpha * (input - output) + output;
            } else {
                output = input;
                hasInitial = true;
            }
            return output;

        }
        
        void Record();

    private:
        bool hasInitial = false;
};

#endif /* _EWMA_H_ */
