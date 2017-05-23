object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Notepad'
  ClientHeight = 679
  ClientWidth = 898
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 897
    Height = 681
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    HideSelection = False
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    TabOrder = 0
  end
  object MainMenu: TMainMenu
    Left = 888
    Top = 656
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N3: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = N4Click
      end
      object N9: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082
        OnClick = N9Click
      end
      object N5: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N5Click
      end
    end
    object N2: TMenuItem
      Caption = #1057#1074#1086#1081#1089#1090#1074#1072
      OnClick = N2Click
    end
    object N6: TMenuItem
      Caption = #1053#1072#1081#1090#1080
      OnClick = N6Click
    end
    object N8: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N8Click
    end
    object test1: TMenuItem
      Caption = 'test'
    end
  end
  object OpenDialog: TOpenDialog
    FileName = 'D:\BSUIR\'#1051#1072#1073#1099'\TheCoursach\test.txt'
    Left = 728
    Top = 8
  end
  object SaveDialog: TSaveDialog
    Left = 728
    Top = 56
  end
end
