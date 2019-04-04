#pragma once

class Calculator
{
public:
    Calculator () = default;
    ~Calculator () = default;

public:
	// Clear the calculator
	void clear ();

	// Add function of the calculator
	double add (double value);
	// Subtract function of the calculator
	double subtract (double value);
	// Multiply function of the calculator
	double multiply (double value);
	// Divide function of the calculator
	double divide (double value);
	// Invert function of the calculator
	double invert ();
	// Power function of the calculator
	double power (double value);
    // Square root function of the calculator
    double sqroot ();
    // Logarithm function of the calculator
    double logarithm ();
    // Sine function of the calculator
    double sine ();
    // Cosine function of the calculator
    double cosine ();
    // Tangent function of the calculator
    double tangent ();

	// Clears the calculator memory value
	void clearMemory ();
	// Recalls the calculator memory value
	double recallMemory ();
	// Stores the calculator value in memory
	void storeMemory ();

    // Returns the current value of the calculator
    double currentValue ();

private:
    // The current value of the calculator
    double current_value = 0.0f;

    // The memory value of the calculator
    double memory_value = 0.0f;
};
