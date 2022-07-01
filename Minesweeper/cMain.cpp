#include "cMain.h"
#include "wx/wx.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

	EVT_BUTTON(1001, ButtonPress)

wxEND_EVENT_TABLE()
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Minesweeper")
{

}

void cMain::ButtonPress(wxCommandEvent& click)
{

}