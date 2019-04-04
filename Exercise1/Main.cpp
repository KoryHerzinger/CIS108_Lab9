#include <iostream>
#include <conio.h>

#include "Calculator.h"

using namespace std;

int main ()
{
    // create a calculator object
    Calculator calculator;

	// flag that is set to indicate that the main loop should terminate
	bool should_exit = { false };

	constexpr int LEFT_OPERAND = 0;
	constexpr int RIGHT_OPERAND = 1;

	// the operands (left and right)
	double operands[2] = { 0.0, 0.0 };
	int current_operand = LEFT_OPERAND;

	// a flag indicating whether or not the left operand has a value
	bool left_operand_set = false;

	// a flag indicating whether or not the period has been pressed since the last function was executed
	bool period_entered = { false };
	// the current place of the fraction (after the period has been pressed)
	double fraction_place = { 0.1 };
	// the current requested operation
	char operation = '\0';
	
	// the last keycode pressed by the user
	char keycode = '\0';

	// output the prompt
	cout << "> ";

	// enter the main calculator loop
	while (!should_exit)
	{
		bool echo_keycode = false;

		keycode = _getch ();
		if (keycode >= '0' && keycode <= '9')
		{
			int digit = (keycode - '0');

			// determine if this is the left operand
			if (operation == '\0' && !left_operand_set)
			{
				left_operand_set = true;
			}

			// shift in the digit
			if (!period_entered)
			{
				operands[current_operand] *= 10.0;
				operands[current_operand] += digit;
			}
			else
			{
				operands[current_operand] += (static_cast<double>(digit) * fraction_place);
				fraction_place /= 10.0;
			}

			echo_keycode = true;
		}
		else
		{
			bool display_current_value = false;

			switch (keycode)
			{
				case '.':
				{
					if (!period_entered)
					{
						period_entered = true;
						fraction_place = 0.1;

						echo_keycode = true;
					}
				} break;

				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
				{
					period_entered = false;
					fraction_place = 0.1;
					current_operand++;

					operation = keycode;

					echo_keycode = true;
				} break;

				case 'c':
				case 'C':
				{
					// clear the current value of the calculator
                    calculator.clear ();

					display_current_value = true;
				} break;

				case 's':
				case 'S':
				{
					// store the current value in the calculator's memory
                    calculator.storeMemory ();
				} break;

				case 'r':
				case 'R':
				{
					// recall the value from the calculator's memory
                    calculator.recallMemory ();

					display_current_value = true;
				} break;

				case 'm':
				case 'M':
				{
					// clear the value in the calculator's memory
                    calculator.clearMemory ();
				} break;

				case 'i':
				case 'I':
				{
                    calculator.invert ();
					display_current_value = true;
				} break;

                case 'q':
                case 'Q':
                {
                    calculator.sqroot ();
                    display_current_value = true;
                } break;

                case 'l':
                case 'L':
                {
                    calculator.logarithm ();
                    display_current_value = true;
                } break;

                case 'n':
                case 'N':
                {
                    calculator.sine ();
                    display_current_value = true;
                } break;

                case 'o':
                case 'O':
                {
                    calculator.cosine ();
                    display_current_value = true;
                } break;

                case 't':
                case 'T':
                {
                    calculator.tangent ();
                    display_current_value = true;
                } break;

				case 'x':
				case 'X':
				{
					should_exit = true;
				} break;

				case '\r':
				{
					if (left_operand_set)
					{
                        calculator.clear ();
                        calculator.add (operands [LEFT_OPERAND]);
					}

					// execute the function
					switch (operation)
					{
						case '+':
						{
                            calculator.add (operands [RIGHT_OPERAND]);
						} break;

						case '-':
						{
                            calculator.subtract (operands[RIGHT_OPERAND]);
						} break;

						case '*':
						{
                            calculator.multiply (operands[RIGHT_OPERAND]);
						} break;

						case '/':
						{
                            calculator.divide (operands[RIGHT_OPERAND]);
						} break;

						case '^':
						{
                            calculator.power (operands[RIGHT_OPERAND]);
						} break;
					}

					operands[LEFT_OPERAND] = 0.0;
					operands[RIGHT_OPERAND] = 0.0;
					current_operand = LEFT_OPERAND;

					period_entered = false;
					fraction_place = 0.1;
					operation = '\0';

					left_operand_set = false;

					display_current_value = true;
				} break;
			}

			if (display_current_value)
			{
				cout << endl << calculator.currentValue () << endl;
				cout << "> ";

				display_current_value = false;
			}
		}

		if (echo_keycode)
		{
			cout << keycode;
		}
	}

	return 0;
}
