#pragma once
#include "wx/wx.h"


class cMain : public wxFrame
{
public: 
	cMain();
	int width = 10;
	int height = 10;
	wxButton** button;
	int *field = nullptr;
	bool firstClick = true;


	void ButtonPress(wxCommandEvent& click);


	
	wxDECLARE_EVENT_TABLE();

};

