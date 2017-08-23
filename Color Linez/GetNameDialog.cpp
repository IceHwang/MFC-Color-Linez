// GetNameDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Color Linez.h"
#include "GetNameDialog.h"
#include "afxdialogex.h"

extern CString myname;

// CGetNameDialog �Ի���

IMPLEMENT_DYNAMIC(CGetNameDialog, CDialogEx)

CGetNameDialog::CGetNameDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_GETNAME, pParent)
    , m_name(_T(""))
{

}

CGetNameDialog::~CGetNameDialog()
{
}

void CGetNameDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_NAME, m_name);
}


BEGIN_MESSAGE_MAP(CGetNameDialog, CDialogEx)
    ON_BN_CLICKED(IDOK, &CGetNameDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CGetNameDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CGetNameDialog ��Ϣ�������





void CGetNameDialog::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateData(TRUE);
    if(m_name!="")
        myname = m_name;

    CDialogEx::OnOK();
}


void CGetNameDialog::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CDialogEx::OnCancel();
}
