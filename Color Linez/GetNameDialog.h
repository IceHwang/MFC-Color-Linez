#pragma once


// CGetNameDialog �Ի���

class CGetNameDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CGetNameDialog)

public:
	CGetNameDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGetNameDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETNAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CString m_name;
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
};
