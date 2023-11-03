
// tiny2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "tiny2.h"
#include "tiny2Dlg.h"
#include "afxdialogex.h"
#include "CTestDialog1.h"
#include "CTestDialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctiny2Dlg 对话框



Ctiny2Dlg::Ctiny2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TINY2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctiny2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, m_ComboBox1);
	DDX_Control(pDX, IDC_COMBO2, m_ComboBox2);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);

	DDX_Control(pDX, IDC_SLIDER1, m_SliderCtrl);
}

BEGIN_MESSAGE_MAP(Ctiny2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &Ctiny2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &Ctiny2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctiny2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Ctiny2Dlg::OnBnClickedButton4)
	ON_WM_TIMER()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// Ctiny2Dlg 消息处理程序

BOOL Ctiny2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 为下拉框添加下来元素
	m_ComboBox1.AddString("2020级");
	m_ComboBox1.AddString("2021级");
	m_ComboBox1.AddString("2022级");
	m_ComboBox1.AddString("2023级");
	m_ComboBox2.AddString("计算机科学与技术");
	m_ComboBox2.AddString("软件工程");
	m_ComboBox2.AddString("信息安全");

	// 设置进度条范围和初始化时钟时事件
	m_Progress.SetRange(0, 500);
	m_Progress.SetPos(0);
	SetTimer(1, 1000, NULL);

	// 初始化滑动条
	m_SliderCtrl.SetRange(1, 100); //设置滑动范围
	m_SliderCtrl.SetTicFreq(1); //每10个单位画一刻度
	m_SliderCtrl.SetLineSize(1);



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctiny2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctiny2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctiny2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctiny2Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(true, ".txt", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("文本文件(*.txt)|*.txt|所有文件 (*.*)|*.*||"));
	CString filePath;
	CStdioFile File;
	CString strLine;
	CString LStr, RStr;

	// 获取用户选择的文件路径
	if (dlg.DoModal() == IDOK)
	{
		filePath = dlg.GetPathName();
		UpdateData(FALSE);
	}


	// 将读到的文件信息输入到信息框
	File.Open(filePath, CFile::modeRead | CFile::typeText);


	while (File.ReadString(strLine))
	{
		int index = strLine.Find(':');
		LStr = strLine.Left(index);
		RStr = strLine.Mid(index + 1);
		if (LStr == "姓名")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT1);
			pEditBox->SetWindowText(RStr);
		}
		else if (LStr == "学号")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT2);
			pEditBox->SetWindowText(RStr);
		}
		else if (LStr == "IP地址")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT3);
			pEditBox->SetWindowText(RStr);
		}
		else if (LStr == "物理地址")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT4);
			pEditBox->SetWindowText(RStr);
		}
		else if (LStr == "子网掩码")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT5);
			pEditBox->SetWindowText(RStr);
		}
		else if (LStr == "籍贯")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT6);
			pEditBox->SetWindowText(RStr);
		}
		else if (LStr == "政治面貌")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT7);
			pEditBox->SetWindowText(RStr);
		}
		else if (LStr == "联系方式")
		{
			CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT8);
			pEditBox->SetWindowText(RStr);
		}


	}
	File.Close();

}


void Ctiny2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 创建模态对话框
	CTestDialog1 td;
	td.DoModal();
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}


void Ctiny2Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	// 创建非模态对话框
	CTestDialog2* pDlg = new CTestDialog2;
	pDlg->Create(IDD_DIALOG2, this);
	pDlg->ShowWindow(SW_SHOW);
}


void Ctiny2Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||"));
	CString filePath;
	CStdioFile File;



	// 获取用户选择的文件路径
	if (dlg.DoModal() == IDOK)
	{
		filePath = dlg.GetPathName();
		if (File.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
		{
			//循环写入文件，读取静态文本框描述文字和编辑框文字，将他们写入到文件中
			int staticID = IDC_STATIC1;
			for (int editID = IDC_EDIT1; editID <= IDC_EDIT8; editID++)
			{

				CEdit* pEditBox = (CEdit*)GetDlgItem(editID);
				CStatic* pStatic = (CStatic*)GetDlgItem(staticID);
				CString strText, strValue;
				pStatic->GetWindowText(strText);
				pEditBox->GetWindowText(strValue);
				File.WriteString(strText + ":" + strValue + "\n");
				staticID++;
			}

			//获取单选的框并写入文件 
			CButton* pRadioButton = (CButton*)GetDlgItem(IDC_RADIO1);
			int buttonState = pRadioButton->GetCheck();

			if (buttonState == BST_CHECKED) {
				File.WriteString("性别:男\n");
			}
			pRadioButton = (CButton*)GetDlgItem(IDC_RADIO2);
			buttonState = pRadioButton->GetCheck();
			if (buttonState == BST_CHECKED) {
				File.WriteString("性别:女\n");
			}

			// 获取下拉列表的值并写入文件
			CString grade, major;
			int i;
			i = m_ComboBox1.GetCurSel();   //取得当前的位置
			m_ComboBox1.GetLBText(i, grade);//取得当前的字符串
			i = m_ComboBox2.GetCurSel();
			m_ComboBox2.GetLBText(i, major);
			File.WriteString("年级:" + grade + "\n");
			File.WriteString("专业:" + major + "\n");

			File.Close();
		}

	}

}


void Ctiny2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// 时钟事件，定时更新进度条

	pos = pos + 50;
	if (pos > 500)
		pos = 0;
	m_Progress.SetPos(pos);

}


void Ctiny2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// 动态读取滑动条
	int i = m_SliderCtrl.GetPos();;    // 获取当前刻度
	CString pos;
	pos.Format(_T("%d"), i);		// 强转成CString类型
	CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT9);
	pEditBox->SetWindowText(pos);
	
}
