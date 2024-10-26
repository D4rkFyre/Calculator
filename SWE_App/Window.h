#pragma once
#include <wx/wx.h>
#include <wx/tokenzr.h>
#include <stack>
#include <string>


class Window : public wxFrame
{
public:
	Window();

private:
	wxDECLARE_EVENT_TABLE();

	// SCREEN
	wxTextCtrl* display = nullptr;

	// CLICK HANDLER METHOD
	void OnClick(wxCommandEvent& event);
};

