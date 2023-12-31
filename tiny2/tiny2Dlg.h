﻿
// tiny2Dlg.h: 头文件
//

#pragma once


// Ctiny2Dlg 对话框
class Ctiny2Dlg : public CDialogEx
{
// 构造
public:
	Ctiny2Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TINY2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int pos = 0;   // 设置进度条当前进度
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	CComboBox m_ComboBox1;
	CComboBox m_ComboBox2;
	CProgressCtrl m_Progress;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CSliderCtrl m_SliderCtrl;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
