#include "Calculator.h"

#include <math.h>

// Clear the calculator
void Calculator::clear ()
{
    current_value = 0.0f;
}

// Add function of the calculator
double Calculator::add (double value)
{
    current_value += value;
	return current_value;
}

// Subtract function of the calculator
double Calculator::subtract (double value)
{
    current_value -= value;
	return current_value;
}

// Multiply function of the calculator
double Calculator::multiply (double value)
{
    current_value *= value;
	return current_value;
}

// Divide function of the calculator
double Calculator::divide (double value)
{
    current_value /= value;
	return current_value;
}

// Invert function of the calculator
double Calculator::invert ()
{
	if (current_value != 0.0)
	{
        current_value *= -1.0f;
	}
	return current_value;
}

// Power function of the calculator
double Calculator::power (double value)
{
    current_value = pow (current_value, value);
	return current_value;
}

// Square root function of the calculator
double Calculator::sqroot ()
{
    current_value = sqrt (current_value);
    return current_value;
}

// Logarithm function of the calculator
double Calculator::logarithm ()
{
    current_value = log (current_value);
    return current_value;
}

// Sine function of the calculator
double Calculator::sine ()
{
    current_value = sin (current_value);
    return current_value;
}

// Cosine function of the calculator
double Calculator::cosine ()
{
    current_value = cos (current_value);
    return current_value;
}

// Tangent function of the calculator
double Calculator::tangent ()
{
    current_value = tan (current_value);
    return current_value;
}

// Clears the calculator memory value
void Calculator::clearMemory ()
{
	memory_value = 0.0f;
}

// Recalls the calculator memory value
double Calculator::recallMemory ()
{
    current_value = memory_value;
	return current_value;
}

// Stores the calculator value in memory
void Calculator::storeMemory ()
{
    memory_value = current_value;
}

// Returns the current value of the calculator
double Calculator::currentValue ()
{
    return current_value;
}
