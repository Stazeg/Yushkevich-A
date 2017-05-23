object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1057#1074#1086#1081#1089#1090#1074#1072
  ClientHeight = 201
  ClientWidth = 315
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 13
    Width = 42
    Height = 16
    Caption = #1064#1088#1080#1092#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 56
    Width = 29
    Height = 16
    Caption = #1062#1074#1077#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 136
    Top = 12
    Width = 73
    Height = 21
    TabOrder = 0
    Text = '10'
  end
  object Button1: TButton
    Left = 120
    Top = 168
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 24
    Top = 112
    Width = 97
    Height = 26
    Caption = #1055#1088#1086#1079#1088#1072#1095#1085#1086#1089#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object ListBox1: TListBox
    Left = 136
    Top = 56
    Width = 73
    Height = 41
    ItemHeight = 13
    Items.Strings = (
      'White'
      'Black'
      'Green'
      'Red'
      'Blue'
      'Yellow')
    TabOrder = 3
  end
end
