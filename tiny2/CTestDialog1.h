﻿#pragma once
#include "afxdialogex.h"


// CTestDialog1 对话框

class CTestDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDialog1)

public:
	CTestDialog1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTestDialog1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
