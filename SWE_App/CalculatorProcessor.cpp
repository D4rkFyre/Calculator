#include "CalculatorProcessor.h"

void CalculatorProcessor::Calculate(const wxString& equation, wxTextCtrl* display){
	// Tokenizer to parse equation
	wxStringTokenizer tokenizer(equation, " ");
	std::stack<double> operands;
	std::stack<wxString> operators;

	// Flag to track expected operand after an operator or function
	bool expectOperand = true; 

	// Do nothing (return) if tokenizer has one or less tokens 
	if (tokenizer.CountTokens() <= 1) {
		return;
	}
	// Loop through all tokens, one at a time
	while (tokenizer.HasMoreTokens()) {
		wxString token = tokenizer.GetNextToken();
		
		// If token is a number
		if (IsNumber(token)) {
			double operand;
			// Try to convert token to a double with error if conversion fails
			if (!token.ToDouble(&operand)) {
				display->SetValue("Invalid number: " + token);
				return;
			}
			// Push operand onto the operands stack
			operands.push(operand);
			// Next token should be an operator or function
			expectOperand = false;
		}
		// Check if token is an operator
		else if (IsOperator(token)) {
			// Ensure syntax validity by checking if operand is expected instead
			if (expectOperand) {
				display->SetValue("Invalid syntax: unexpected operator " + token);
				return;
			}
			// Process operators with higher or equal precedence
			while (!operators.empty() && Precedence(operators.top()) >= Precedence(token)) {
				// Exit if an error occurs (ProcessOperator returns false)
				if (!ProcessOperator(operators.top(), operands, display)) {
					return;
				}
				operators.pop();
			}
			// Push operator onto the operators stack
			operators.push(token);
			// Next token should be an operand
			expectOperand = true;
		}
		// Check if token is a function
		else if (IsFunction(token)) {
			// Ensure syntax by checking if an operand is expected
			if (!expectOperand) {
				display->SetValue("Invalid syntax: unexpected function " + token);
				return;
			}
			// Push function onto the operators stack
			operators.push(token);
			// Next token should be an operand
			expectOperand = true;
		}
		// Otherwise token is unknown, so display error
		else {
			display->SetValue("Unknown token: " + token);
			return;
		}
	}
	// Process remaining operators on the stack
	while (!operators.empty()) {
		// Exit if an error occurs (ProcessOperator returns false)
		if (!ProcessOperator(operators.top(), operands, display)) {
			return;
		}
		operators.pop();
	}
	
	
	
	// Final check to make sure only one operand remains
	if (operands.size() != 1) {
		display->SetValue("Invalid equation");
	}
	// Display the final remaining operand to the calc screen as the result
	else {
		display->SetValue(wxString::Format("%g", operands.top()));
	}
}

bool CalculatorProcessor::IsNumber(const wxString& token) {
	double value;
	return token.ToDouble(&value);
}

bool CalculatorProcessor::IsOperator(const wxString& token) {
	return token == "+" || token == "-" || token == "*" || token == "/" || token == "%";
}

bool CalculatorProcessor::IsFunction(const wxString& token) {
	return token == "Sqrt(" || token == "Sin(" || token == "Cos(" || token == "Tan(";
}

int CalculatorProcessor::Precedence(const wxString& oper) {
	if (oper == "+" || oper == "-")
		return 1;
	else if (oper == "*" || oper == "/" || oper == "%")
		return 2;
	else if (oper == "Sqrt(" || oper == "Sin(" || oper == "Cos(" || oper == "Tan(")
		return 3;
	return 0;
}

bool CalculatorProcessor::ProcessOperator(const wxString& oper, std::stack<double>& operands, wxTextCtrl* display) {
	double result;

	// Check if operator is a binary operator
	if (oper == "+" || oper == "-" || oper == "*" || oper == "/" || oper == "%") {
		// Ensure there are at least 2 operands for binary operations
		if (operands.size() < 2) {
			// Handle error: insufficient operands
			display->SetValue("Error: insufficient operands");
			return false;
		}

		// Create variables and pop the top two operands from the stack
		double right = operands.top();
		operands.pop();
		double left = operands.top();
		operands.pop();

		// Perform the appropriate operation on the variables
		if (oper == "+") {
			result = left + right;
		}
		else if (oper == "-") {
			result = left - right;
		}
		else if (oper == "*") {
			result = left * right;
		}
		else if (oper == "/") {
			if (right == 0) {
				// Handle error: division by zero
				display->SetValue("Error: Can't divide by 0");
				return false;
			}
			result = left / right;
		}
		else if (oper == "%") {
			if (right == 0) {
				// Handle error: division by zero
				display->SetValue("Error: Can't divide by 0");
				return false;
			}
			result = fmod(left, right);
		}
		// Push result back on the stack of operands
		operands.push(result);
	}
	// Check if the operator is a unary operator (function)
	else if (oper == "Sqrt(" || oper == "Sin(" || oper == "Cos(" || oper == "Tan(") {
		// Ensure there is at least one operand
		if (operands.size() < 1) {
			// Handle error: insufficient operands
			display->SetValue("Error: insufficient operands");
			return false;
		}

		// make a variable and pop the top operand from the stack
		double operand = operands.top();
		operands.pop();

		// Perform the correct function
		if (oper == "Sqrt(") {
			result = sqrt(operand);
		}
		else if (oper == "Sin(") {
			result = sin(operand);
		}
		else if (oper == "Cos(") {
			result = cos(operand);
		}
		else if (oper == "Tan(") {
			result = tan(operand);
		}
		// Push result back on the stack of operands
		operands.push(result);
	}
	else {
		// Handle error: unrecognized operator
		display->SetValue("Error: Unrecognized operator");
		return false;
	}
	// If everything is handled without errors, return true
	return true;
}
