#include "CppUnitTest.h"
#include "..\SWE_App\CalculatorProcessor.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CalculatorProcessorTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		TEST_METHOD(EmptyEquation)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("", display->GetValue());
		}

		TEST_METHOD(DivisionByZero)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "10 / 0";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("Error: Can't divide by 0", display->GetValue());
		}

		TEST_METHOD(ModByZero)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "10 % 0";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("Error: Can't divide by 0", display->GetValue());
		}

		TEST_METHOD(UnknownToken)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "3 $ 5";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("Unknown token: $", display->GetValue());
		}

		TEST_METHOD(InvalidSyntax)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "+ 5 3";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("Invalid syntax: unexpected operator +", display->GetValue());
		}

		TEST_METHOD(Add)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "10 + 2";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("12", display->GetValue());
		}

		TEST_METHOD(Divide)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "10 / 2";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("5", display->GetValue());
		}

		TEST_METHOD(TrigFunctionCos)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "Cos( 0";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("1", display->GetValue());
		}

		TEST_METHOD(MultipleOperationsWithPrecedence)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "10 + 2 * 3 - 4 / 2";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("14", display->GetValue());
		}

		TEST_METHOD(FunctionsAndOperationsWithPrecedence)
		{
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxTextCtrl* display = new wxTextCtrl(tempFrame, wxID_ANY);
			wxString equation = "1 + Sqrt( 4 * 4 - Cos( 0 / 1";
			CalculatorProcessor::GetInstance().Calculate(equation, display);
			Assert::AreEqual("8", display->GetValue());
		}
	};
}
