// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "tree.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
BinarySearchTree *tree = new BinarySearchTree();

// ---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner) : TForm(Owner)
{
	StringGrid1->Cells[0][0] = "??????? ?????? ????????";
	StringGrid1->Cells[1][0] = "8596";
	StringGrid1->Cells[0][1] = "????????? ???????? ??????????";
	StringGrid1->Cells[1][1] = "7458";
	StringGrid1->Cells[0][2] = "??????? ???????? ?????????";
	StringGrid1->Cells[1][2] = "7854";
	StringGrid1->Cells[0][3] = "??? ???????? ?????";
	StringGrid1->Cells[1][3] = "2001";
	StringGrid1->Cells[0][4] = "?????? ???? ???????";
	StringGrid1->Cells[1][4] = "1000";
}
// ---------------------------------------------------------------------------

void ViewTree(BinarySearchTree::node *t, int kl, TTreeView *TreeView1)
{
	if (t == NULL)
		return;
	if (kl == -1)
		TreeView1->Items->AddFirst(NULL, t->data + " = " + IntToStr(t->key));
	else
		TreeView1->Items->AddChildFirst(TreeView1->Items->Item[kl],
		t->data + " = " + IntToStr(t->key));
	kl++;
	ViewTree(t->left, kl, TreeView1);
	ViewTree(t->right, kl, TreeView1);
	kl--;
}

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	TreeView1->Items->Clear();
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// tree->add(123, "jopa", &tree->root);
			tree->root = tree->add(StrToInt(StringGrid1->Cells[i + 1][j]),
				StringGrid1->Cells[i][j], tree->root);
		}
	}
	ViewTree(tree->root, -1, TreeView1);

}
// ---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
	if (TreeView1->Selected == NULL)
		return;
	int siz = TreeView1->Selected->Text.Length();
	int key = StrToInt(TreeView1->Selected->Text.SubString(siz - 4, 5));
	ShowMessage(key);
	tree->root = tree->remove(tree->root, key);
	TreeView1->Items->Clear();
	ViewTree(tree->root, -1, TreeView1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
	Memo1->Text = tree->pre_order(tree->root);
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
	Memo1->Text = tree->post_order(tree->root);
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::Button5Click(TObject *Sender)
{
	Memo1->Text = tree->in_order(tree->root);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
	Label2->Caption = IntToStr(tree->get_left_nodes(tree->root));
}
//---------------------------------------------------------------------------

