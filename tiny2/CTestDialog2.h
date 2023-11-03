#pragma once
#include "afxdialogex.h"


// CTestDialog2 对话框

class CTestDialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDialog2)

public:
	CTestDialog2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTestDialog2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
