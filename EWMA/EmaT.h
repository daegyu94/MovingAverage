#ifndef _EMAT_H_
#define _EMAT_H_

template <typename T>
class EmaT {
	public:
		/*
		 * Creates a filter with a defined initial output.
		 */
		EmaT(T alpha, unsigned int alphaScale);
		/*
		 * Creates a filter with a defined initial output.
		 */
		EmaT(T alpha, unsigned int alphaScale, T initialOutput);

		void reset();

		T output();

		/*
		 * Specifies a reading value.
		 * @returns current output
		 */
		T filter(T input);

	private:
		void init(T alpha, unsigned int alphaScale, T initialOutput);

		/*
		 * Smoothing factor, in range [0,alphaScale]. Higher the value - less smoothing (higher the latest reading impact).
		 */
		T alpha;
		T outputScaled;
		unsigned int alphaScale;
		bool hasInitial;
};

template <typename T>
EmaT<T>::EmaT(T alpha, unsigned int alphaScale) {
	init(alpha, alphaScale, 0);
	this->hasInitial = false;
}

template <typename T>
EmaT<T>::EmaT(T alpha, unsigned int alphaScale, T initialOutput) {
	init(alpha, alphaScale, initialOutput);
}

template <typename T>
void EmaT<T>::init(T alpha, unsigned int alphaScale, T initialOutput) {
	this->alpha = alpha;
	this->alphaScale = alphaScale;
	this->outputScaled = initialOutput * alphaScale;
	this->hasInitial = true;
}

template <typename T>
void EmaT<T>::reset() {
	this->hasInitial = false;
}

template <typename T>
T EmaT<T>::filter(T input) {
	if (hasInitial) {
        outputScaled = (alphaScale - alpha) * outputScaled / alphaScale + (alpha * input);
	} else {
		outputScaled = input * alphaScale;
		hasInitial = true;
	}
	return output();
}

template <typename T>
T EmaT<T>::output() {
	return (outputScaled + alphaScale / 2) / alphaScale;
}

#endif // _EMAT_H_
