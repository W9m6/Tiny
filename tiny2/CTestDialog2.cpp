// CTestDialog2.cpp: 实现文件
//

#include "pch.h"
#include "tiny2.h"
#include "afxdialogex.h"
#include "CTestDialog2.h"


// CTestDialog2 对话框

IMPLEMENT_DYNAMIC(CTestDialog2, CDialogEx)

CTestDialog2::CTestDialog2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CTestDialog2::~CTestDialog2()
{
}

void CTestDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDialog2, CDialogEx)
END_MESSAGE_MAP()


// CTestDialog2 消息处理程序
