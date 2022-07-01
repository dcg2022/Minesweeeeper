#include "cMain.h"
#include "wx/wx.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

	EVT_BUTTON(1001, ButtonPress)

wxEND_EVENT_TABLE()
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Minesweeper")
{
	button = new wxButton * [width * height];
	wxGridSizer* grid = new wxGridSizer(width, height, 0, 0); 

	field = new int[width * height];

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			button[y * width + x] = new wxButton(this, 100 + (y * width + x));
			grid->Add(button[y * width + x], 1, wxEXPAND | wxALL);

			button[y * width + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::ButtonPress, this);
			field[y * width + x] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();


}

void cMain::ButtonPress(wxCommandEvent& click)
{
	int x = (click.GetId() - 100) % width;
	int y = (click.GetId() - 100) / width;

	if (firstClick)
	{
		int mines = 30;
		while (mines)
		{
			int rx = rand() % width;
			int ry = rand() % height;

			if (field[ry * width + rx] == 0 && rx != x && ry != y)
			{
				field[ry * width + rx] = -1;
				mines--;
			}
		}
		firstClick = false;
	}

	button[y * width + x]->Enable(false);

	if (field[y * width + x] == -1)
	{
		wxMessageBox("BOOOOOOOM!!!!!! You Lose!");
		firstClick = true;
		for (int x = 0; x < width; x++)
			for (int y = 0; y < height; y++)
			{
				field[y * width + x] = 0;
				button[y * width + x]->SetLabel("");
				button[y * width + x]->Enable(true);
			}
	}
	else
	{
		int count = 0;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height)
				{
					if (field[(y + j) * width + (x + i)] == -1)
						count++;

				}
			}

		if (count > 0)
		{
			button[y * width + x]->SetLabel(std::to_string(count));

		}

	}

	click.Skip();
}