//---------------------------------------------------------------------------
#include <vcl.h>

#ifndef functionsH
#define functionsH
//---------------------------------------------------------------------------
#endif

AnsiString GetMessage(int v);

bool LoadDialogs();

bool Load(AnsiString fileName, TMemo *memo);

bool Save(AnsiString fileName, TMemo *memo);

int AStrToInt(AnsiString input);

void SetMemoColor(TListBox *listBox, TMemo *memo);

void FindText(TMemo *memo, AnsiString text);
