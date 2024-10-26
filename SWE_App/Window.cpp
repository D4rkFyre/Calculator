#include "Window.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"



wxBEGIN_EVENT_TABLE(Window, wxFrame)
	EVT_COMMAND_RANGE(11, 64, wxEVT_COMMAND_BUTTON_CLICKED, Window::OnClick)
wxEND_EVENT_TABLE()


Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(600, 700)){
	
	// Main sizer
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	// Text control box
	display = new wxTextCtrl(this, 001, "", wxPoint(10, 20), wxSize(465, 40), wxTE_RIGHT);
	display->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	display->SetEditable(false);

	mainSizer->Add(display, 0, wxEXPAND | wxALL, 10);
	
	// Grid sizer for buttons
	wxGridSizer* buttonSizer = new wxGridSizer(6, 4, 5, 5);

	wxButton* buttonMod = ButtonFactory::CreateNumOpButton(this, 11, " % ");
	wxButton* buttonSqrt = ButtonFactory::CreateNumOpButton(this, 12, " Sqrt( ");
	wxButton* buttonClear = ButtonFactory::CreateClearButton(this, 13);
	wxButton* buttonDelete = ButtonFactory::CreateDeleteButton(this, 14);
	// Delete button font size increase
	wxFont font = buttonDelete->GetFont();
	font.SetPointSize(20);
	buttonDelete->SetFont(font);

	// Button creation using ButtonFactory methods
	wxButton* buttonSin = ButtonFactory::CreateNumOpButton(this, 21, " Sin( ");
	wxButton* buttonCos = ButtonFactory::CreateNumOpButton(this, 22, " Cos( ");
	wxButton* buttonTan = ButtonFactory::CreateNumOpButton(this, 23, " Tan( ");
	wxButton* buttonDivide = ButtonFactory::CreateNumOpButton(this, 24, " / ");

	wxButton* button7 = ButtonFactory::CreateNumOpButton(this, 31, "7");
	wxButton* button8 = ButtonFactory::CreateNumOpButton(this, 32, "8");
	wxButton* button9 = ButtonFactory::CreateNumOpButton(this, 33, "9");
	wxButton* buttonMult = ButtonFactory::CreateNumOpButton(this, 34, " * ");

	wxButton* button4 = ButtonFactory::CreateNumOpButton(this, 41, "4");
	wxButton* button5 = ButtonFactory::CreateNumOpButton(this, 42, "5");
	wxButton* button6 = ButtonFactory::CreateNumOpButton(this, 43, "6");
	wxButton* buttonSub = ButtonFactory::CreateNumOpButton(this, 44, " - ");

	wxButton* button1 = ButtonFactory::CreateNumOpButton(this, 51, "1");
	wxButton* button2 = ButtonFactory::CreateNumOpButton(this, 52, "2");
	wxButton* button3 = ButtonFactory::CreateNumOpButton(this, 53, "3");
	wxButton* buttonAdd = ButtonFactory::CreateNumOpButton(this, 54, " + ");

	wxButton* buttonPosNeg = ButtonFactory::CreateNumOpButton(this, 61, "+/-");
	wxButton* button0 = ButtonFactory::CreateNumOpButton(this, 62, "0");
	wxButton* buttonDot = ButtonFactory::CreateNumOpButton(this, 63, ".");
	wxButton* buttonEquals = ButtonFactory::CreateEqualsButton(this, 64);

	// Button/window color settings
	this->SetBackgroundColour(*wxBLACK);

	wxColor lightRed(255, 192, 192);
	//wxColor lightBlue(173, 216, 230);
	wxColor lightGreen(144, 238, 144);
	//wxColor lightYellow(255, 255, 204);

	buttonEquals->SetBackgroundColour(*wxCYAN);

	buttonMod->SetBackgroundColour(lightGreen);
	buttonSqrt->SetBackgroundColour(*wxGREEN);
	buttonSin->SetBackgroundColour(*wxGREEN);
	buttonCos->SetBackgroundColour(*wxGREEN);
	buttonTan->SetBackgroundColour(*wxGREEN);
	buttonDivide->SetBackgroundColour(lightGreen);
	buttonMult->SetBackgroundColour(lightGreen);
	buttonSub->SetBackgroundColour(lightGreen);
	buttonAdd->SetBackgroundColour(lightGreen);

	buttonPosNeg->SetBackgroundColour(*wxYELLOW);
	buttonDot->SetBackgroundColour(*wxYELLOW);

	buttonClear->SetBackgroundColour(lightRed);
	buttonDelete->SetBackgroundColour(lightRed);
	
	// Add buttons to grid sizer
	buttonSizer->Add(buttonSqrt, 1, wxEXPAND);
	buttonSizer->Add(buttonClear, 1, wxEXPAND);
	buttonSizer->Add(buttonDelete, 1, wxEXPAND);
	buttonSizer->Add(buttonMod, 1, wxEXPAND);

	buttonSizer->Add(buttonSin, 1, wxEXPAND);
	buttonSizer->Add(buttonCos, 1, wxEXPAND);
	buttonSizer->Add(buttonTan, 1, wxEXPAND);
	buttonSizer->Add(buttonDivide, 1, wxEXPAND);

	buttonSizer->Add(button7, 1, wxEXPAND);
	buttonSizer->Add(button8, 1, wxEXPAND);
	buttonSizer->Add(button9, 1, wxEXPAND);
	buttonSizer->Add(buttonMult, 1, wxEXPAND);

	buttonSizer->Add(button4, 1, wxEXPAND);
	buttonSizer->Add(button5, 1, wxEXPAND);
	buttonSizer->Add(button6, 1, wxEXPAND);
	buttonSizer->Add(buttonSub, 1, wxEXPAND);

	buttonSizer->Add(button1, 1, wxEXPAND);
	buttonSizer->Add(button2, 1, wxEXPAND);
	buttonSizer->Add(button3, 1, wxEXPAND);
	buttonSizer->Add(buttonAdd, 1, wxEXPAND);

	buttonSizer->Add(buttonPosNeg, 1, wxEXPAND);
	buttonSizer->Add(button0, 1, wxEXPAND);
	buttonSizer->Add(buttonDot, 1, wxEXPAND);
	buttonSizer->Add(buttonEquals, 1, wxEXPAND);

	// Add button sizer to main sizer
	mainSizer->Add(buttonSizer, 1, wxEXPAND | wxALL, 10);

	SetSizerAndFit(mainSizer);
	SetMinSize(wxSize(600, 700));
}


void Window::OnClick(wxCommandEvent& event) {
	
	wxString currentString;

	// If button is Clear, Delete, unary negation, or Equals, perform different functions
	if (event.GetId() == 13) {
		display->Clear();
		return;
	}
	else if (event.GetId() == 14) {
		currentString = display->GetValue();
		if (!currentString.IsEmpty()) {
			currentString.RemoveLast();
			display->SetValue(currentString);
			return;
		}
	}
	else if (event.GetId() == 61) {
		display->AppendText("-");
		return;
	}
	else if (event.GetId() == 64) {
		if (!display->IsEmpty()) {
			CalculatorProcessor::GetInstance().Calculate(display->GetValue(), display);
		}
		
		return;
	}
	// Any other button will use AppendText with its label
	else {
		wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
		wxString label = button->GetLabel();
		display->AppendText(label);
	}
}