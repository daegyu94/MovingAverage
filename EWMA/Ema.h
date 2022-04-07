#ifndef _EMA_H_
#define _EMA_H_

class Ema {
    public:
        /* Current data output */
        double output = 0;
         /* Smoothing factor, in range [0,1]. Higher the value - less smoothing (higher the latest reading impact).*/
        double alpha = 0;

        /* Creates a filter without a defined initial output. The first output will be equal to the first input. */
        Ema(double alpha) {
            this->alpha = alpha;
        }

        /* Creates a filter with a defined initial output. */
        Ema(double alpha, double initialOutput) {
            this->alpha = alpha;
            this->output = initialOutput;
            this->hasInitial = true;
        }

        void reset() {
            this->hasInitial = false;
        }

        double filter(double input) {
            if (hasInitial) {
                output = (1 - alpha) * output + (alpha * input);
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

#endif // _EMA_H_
