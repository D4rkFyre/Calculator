#pragma once
#include <wx/wx.h>
#include <wx/button.h>



class ButtonFactory{
private:
	// General button creation (other methods call on this)
	static wxButton* CreateButton(wxWindow* parent, wxWindowID id, const wxString& label,
		const wxPoint& point = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = 0);

public:
	// For number/operator buttons
	static wxButton* CreateNumOpButton(wxWindow* parent, wxWindowID id, const wxString& label);
	// For the equals button
	static wxButton* CreateEqualsButton(wxWindow* parent, wxWindowID id);
	// For the delete button
	static wxButton* CreateDeleteButton(wxWindow* parent, wxWindowID id);
	// for the clear button
	static wxButton* CreateClearButton(wxWindow* parent, wxWindowID id);
};

