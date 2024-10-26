#include "ButtonFactory.h"


wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& point, const wxSize& size, long style) {
	return new wxButton(parent, id, label, point, size, style);
}

wxButton* ButtonFactory::CreateNumOpButton(wxWindow* parent, wxWindowID id, const wxString& label) {
	return CreateButton(parent, id, label);
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent, wxWindowID id) {
	return CreateButton(parent, id, wxT("="));
}

wxButton* ButtonFactory::CreateDeleteButton(wxWindow* parent, wxWindowID id) {
	return CreateButton(parent, id, wxT("\u2190"));
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent, wxWindowID id) {
	return CreateButton(parent, id, wxT("CE"));
}

