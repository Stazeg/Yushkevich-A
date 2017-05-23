//---------------------------------------------------------------------------

#pragma hdrstop
#include "vcl.h"
#include <vector>
#include <fstream>

#include "functions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

std::vector <AnsiString> dialogs;
std::ifstream fin;

void Read(std::vector <AnsiString> &in)
{
	AnsiString temp;
	char c;

	fin.seekg(0, fin.beg);
	while (fin.get(c))
	{
		if (c == '\n')
		{
			if (temp != "")
				in.push_back(temp);
			temp = "";
		}
		else
		{
			temp += (AnsiString)c;
		}
	}
	in.push_back(temp);
}

void Read(TMemo *memo)
{
	std::vector <AnsiString> temp;

	memo->Text = "";
	Read(temp);
	for (int i = 0; i < temp.size(); ++i)
	{
		memo->Lines->Add(temp[i]);
	}
}

bool LoadDialogs()
{
	fin.open("dialogs.dat");
	if (!fin.is_open())
	{
		ShowMessage("Ошибка при загрузке языкового пакета");
		return false;
	}

	Read(dialogs);
	fin.close();
	return true;
}

bool Load(AnsiString fileName, TMemo *memo)
{
	AnsiString temp;

	fin.open(fileName.c_str());
	if (!fin.is_open())
	{
		ShowMessage(dialogs[0]);
		return false;
	}
	else
	{
		Read(memo);
	}

	fin.close();
	return true;
}

bool Save(AnsiString fileName, TMemo *memo)
{
	AnsiString temp;
	std::ofstream fout;

	fout.open(fileName.c_str());
	for (int i = 0; i < memo->Lines->Count; ++i)
	{
		temp = memo->Lines->Strings[i];
		fout << temp.c_str();
		if (i + 1 != memo->Lines->Count)
			fout << "\n";
	}
	fout.close();

	return true;
}

AnsiString GetMessage(int v)
{
	return dialogs[v];
}

int AStrToInt(AnsiString input)
{
    int s = 0;
	char *c = input.c_str();

	for (int i = 0; i < input.Length(); ++i)
	{

		if (!isdigit(c[i]))
			{
				return -1;
			}
		s = s * 10 + (int)c[i] - 48;
	}

	return s;
}

void SetMemoColor(TListBox *listBox, TMemo *memo)
{
	int selectedItem;

	for (int i = 0; i < listBox->Items->Count; ++i)
	{
		if (listBox->Selected[i])
			selectedItem = i;
	}

	switch (selectedItem)
	{
		case 0:
		{
			memo->Font->Color = clWhite;
			break;
		}
		case 1:
		{
			memo->Font->Color = clBlack;
			break;
		}
		case 2:
		{
			memo->Font->Color = clGreen;
			break;
		}
		case 3:
		{
			memo->Font->Color = clRed;
			break;
		}
		case 4:
		{
			memo->Font->Color = clBlue;
			break;
		}
		case 5:
		{
			memo->Font->Color = clYellow;
			break;
		}
		default:
			break;
	}
}

int SNumber(TMemo *memo, int &index)
{
	int output = 0;

	for (int i = 0; i < index; ++i)
	{
		output += memo->Lines->Strings[i].Length();
		output += 2;
	}

	return output;
}

void Mark(TMemo *memo, std::vector <int> pF, int length, int &number, int index)
{
	for (int i = 0; i < pF.size(); ++i)
	{
		if (pF[i] == length)
		{
			if (number == 0)
			{
				memo->SelStart = i - 2 * length + SNumber(memo, index);
				memo->SelLength = length;
			}
			++number;
		}
	}
}

void KMP(TMemo *memo, AnsiString text, int length, int &number, int index)
{
	std::vector <int> pF;
    pF.resize(text.Length(), 0);

	for (int i = 1; i < pF.size(); ++i)
	{
		int j = pF[i - 1];

		while (j != 0 && text[j + 1] != text[i + 1])
			j = pF[j - 1];

		if (text[i + 1] == text[j + 1])      ++j;
		pF[i] = j;
	}

	Mark(memo, pF, length, number, index);
}

void FindText(TMemo *memo, AnsiString input)
{
	AnsiString text = input;
	int number = 0;

    memo->SelLength = 0;
	for (int i = 0; i < memo->Lines->Count; ++i)
	{
		KMP(memo, text + "&" + memo->Lines->Strings[i], input.Length(), number, i);
	}

	AnsiString message = dialogs[3] + " " + IntToStr(number);

	if (number == 0)
		ShowMessage(dialogs[2]);
	else
		ShowMessage(message);
}
