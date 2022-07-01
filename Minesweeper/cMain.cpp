#include "cMain.h"
#include "wx/wx.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

	EVT_BUTTON(1001, ButtonPress)

wxEND_EVENT_TABLE()
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Minesweeper")
{
	button = new wxButton * [width * height];
	wxGridSizer* grid = new wxGridSizer(width, height, 0, 0); 
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			button[y * width + x] = new wxButton(this, 100 + (y * width + x));
			grid->Add(button[y * width + x], 1, wxEXPAND | wxALL);

			button[y * width + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::ButtonPress, this);
		}
	}

	this->SetSizer(grid);
	grid->Layout();


}

void cMain::ButtonPress(wxCommandEvent& click)
{
	int x = (click.GetId() - 100) % width;
	int y = (click.GetId() - 100) / width;

	click.Skip();
}