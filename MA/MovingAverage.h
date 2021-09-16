#ifndef MOVING_AVERAGE__H
#define MOVING_AVERAGE__H

#include <unistd.h>
#include <vector>

class MovingAverage {

private:
	const static size_t default_filter_length = 5;
	// Length of the filter
	size_t filter_length;
	// Vector with raw data
	double *data;
	double sum, average;
	int index;
	bool filter_complete;
	void init();
    
    std::vector<double> result;
public:
	/**
	 * Creates a new instance of MovingAverage with
	 * given filter length.
	 */
	MovingAverage(size_t);
	/**
	 * Creates a new instance of MovingAverage with
	 * the default filter length value 5.
	 */
	MovingAverage();
	/**
	 * Releases the memory objects associated with the
	 * current MovingAverage instance.
	 */
	~MovingAverage();
	/**
	 * Adds a new element in the Moving Average vector.
	 * Updates the current average.
	 */
	void add(double);
	/**
	 * Returns the Filter's Length.
	 */
	size_t getFilterLength();
	/**
	 * Returns the current average as update after the invocation
	 * of MovingAverage::add(double).
	 */
	double getCurrentAverage();
	/**
	 * Clears the vector of data by setting it to zero.
	 */
	void clear();
	/**
	 * Returns the raw data that are currently stored
	 * in an internal vector.
	 */
	double* getData();
};
#endif
