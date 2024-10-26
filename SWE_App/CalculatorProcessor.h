#pragma once
#include <wx/wx.h>
#include <wx/tokenzr.h>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>


class CalculatorProcessor{

public:
	// Getter for the CalculatorProcessor instance (Singleton)
	static CalculatorProcessor& GetInstance() {
		static CalculatorProcessor instance;
		return instance;
	}
	
	// Delete copy constructor and assignment operator (Singleton)
	CalculatorProcessor(const CalculatorProcessor&) = delete;
	void operator=(const CalculatorProcessor&) = delete;

	// Calculates the wxString using the helper methods, then sets the display to the result
	void Calculate(const wxString& equation, wxTextCtrl* display);
	
private:
	// Private constructor/destructor to prevent instantiation (Singleton)
	CalculatorProcessor() {}
	~CalculatorProcessor() {}

	// Helper methods:
	// 
	// Checks if a token is a number
	bool IsNumber(const wxString& token);
	// Checks if a token is an operator (+, -, *, /, or %) with left AND right associativity
	bool IsOperator(const wxString& token);
	// Checks if a token is a function (Sqrt, Sin, Cos, Tan) with right associativity
	bool IsFunction(const wxString& token);
	// Determines an operator's precedence
	int Precedence(const wxString& oper);
	// Process the operator with value(s) on top of operands stack
	bool ProcessOperator(const wxString& oper, std::stack<double>& operands, wxTextCtrl* display);

};

