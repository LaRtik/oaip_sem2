object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 476
  ClientWidth = 790
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
    Left = 8
    Top = 323
    Width = 197
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1091#1079#1083#1086#1074' '#1074' '#1083#1077#1074#1086#1084' '#1087#1086#1076#1076#1077#1088#1077#1074#1077':'
  end
  object Label2: TLabel
    Left = 211
    Top = 323
    Width = 76
    Height = 13
    Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
  end
  object TreeView1: TTreeView
    Left = 416
    Top = 32
    Width = 313
    Height = 209
    Indent = 19
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 32
    Top = 32
    Width = 305
    Height = 161
    ColCount = 2
    DefaultColWidth = 200
    TabOrder = 1
  end
  object Button1: TButton
    Left = 112
    Top = 216
    Width = 137
    Height = 25
    Caption = 'Transform to TreeView'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 416
    Top = 256
    Width = 97
    Height = 25
    Caption = 'Delete selected'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 544
    Top = 320
    Width = 185
    Height = 148
    TabOrder = 4
  end
  object Button3: TButton
    Left = 288
    Top = 318
    Width = 227
    Height = 25
    Caption = #1055#1088#1103#1084#1086#1081' '#1086#1073#1093#1086#1076
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 288
    Top = 381
    Width = 227
    Height = 25
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081' '#1086#1073#1093#1086#1076
    TabOrder = 6
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 288
    Top = 443
    Width = 227
    Height = 25
    Caption = #1054#1073#1093#1086#1076' '#1074' '#1087#1086#1088#1103#1076#1082#1077' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1103' '#1082#1083#1102#1095#1072
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 342
    Width = 75
    Height = 25
    Caption = #1055#1086#1083#1091#1095#1080#1090#1100
    TabOrder = 8
    OnClick = Button6Click
  end
end
