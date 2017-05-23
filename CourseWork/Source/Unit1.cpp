
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
#include "functions.h"

#include <cctype>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString fileName;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	LoadDialogs();
	fileName = "";

	Memo1->Clear();
	Form1->Constraints->MaxWidth = 1366;
	Form1->Constraints->MaxHeight = 768;

	Memo1->Width = Form1->Width - 10;
	Memo1->Height = Form1->Height - 10;

	TransparentColor = true;
	TransparentColorValue = clGray;

	//Memo1->WordWrap = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)    //info [Form2]
{
	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)//close_info [Form2]
{
	Form2->Close();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender) //exit
{
	Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N3Click(TObject *Sender) //load from file
{
	OpenDialog->Execute();
	fileName = OpenDialog->FileName;

	Load(fileName, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender) //save to file
{
	if (fileName == "")
		Form1->N9Click(Form1);
	else
	{
		Save(fileName, Memo1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender) //save as ...
{
	SaveDialog->Execute();
	fileName = SaveDialog->FileName;

    Save(fileName, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender) //change Memo1 [Form3]
{
	int changeFont = AStrToInt(Form3->Edit1->Text);

	if (changeFont < 0)
	{
        Form3->Edit1->Text = Form1->Memo1->Font->Size;
		ShowMessage(GetMessage(1));
	}
	else     changeFont = (changeFont > 250 || changeFont < 1 ? 10 : changeFont);

	Form3->Close();

	if (changeFont > 0)     Form1->Memo1->Font->Size = changeFont;
	if (Form3->CheckBox1->Checked)
	{
		Form1->Memo1->Color = clGray;
	}
	else
	{
		Form1->Memo1->Color = clWhite;
	}

	SetMemoColor(Form3->ListBox1, Form1->Memo1);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender) //change Memo [open Form3]
{
	Form3->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormResize(TObject *Sender)  //resize
{
    Memo1->Width = Form1->Width - 10;
	Memo1->Height = Form1->Height - 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)  //find
{
	Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
	FindText(Form1->Memo1, Form5->Edit1->Text);

	Form5->Close();
}

