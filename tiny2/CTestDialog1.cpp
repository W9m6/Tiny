// CTestDialog1.cpp: 实现文件
//

#include "pch.h"
#include "tiny2.h"
#include "afxdialogex.h"
#include "CTestDialog1.h"


// CTestDialog1 对话框

IMPLEMENT_DYNAMIC(CTestDialog1, CDialogEx)

CTestDialog1::CTestDialog1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CTestDialog1::~CTestDialog1()
{
}

void CTestDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDialog1, CDialogEx)
END_MESSAGE_MAP()


// CTestDialog1 消息处理程序
