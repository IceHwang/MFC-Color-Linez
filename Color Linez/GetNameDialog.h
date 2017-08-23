#pragma once


// CGetNameDialog 对话框

class CGetNameDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CGetNameDialog)

public:
	CGetNameDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGetNameDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETNAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CString m_name;
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
};
