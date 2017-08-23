
// Color LinezDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"




// CColorLinezDlg �Ի���
class CColorLinezDlg : public CDialogEx
{
// ����
public:
	CColorLinezDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLORLINEZ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    BOOL CColorLinezDlg::PreTranslateMessage(MSG* pMsg)
    {
        if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;
        if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) return TRUE;
        else
            return CDialog::PreTranslateMessage(pMsg);
    }
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnGameExit();
    afx_msg void OnGameNewgame();
    afx_msg void OnHelpAboutthisgame();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnHelpRules();
    afx_msg void OnGameLeaderboard();
    int m_score;
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    void GameMain(int pos_x, int pos_y);
    void GameStart();
    int MoveJudge(const int froms,const int tos);//1Ϊ���ƶ�,0Ϊ�����ƶ�
    int EraseJudge(int position);//positionΪ�ƶ����λ�û��²�����λ��,ֻ����position�����ᷢ������,������ȥ�ĸ���
    int ShowNext(int color);//��ʾԤ��,color��Ԥ�����ɫֵΪ��һ��*100+�ڶ���*10+������
    int ShowMap();//��ʾ����
    int CircleProduce();//����ֵΪx*10+y,ȷ��������,������-1,����Ϸ����
    int ShowPredictionAndChange();//����Ԥ�������Ӳ�����Ԥ��,������-1��������,��Ϸ����.
    int showmap();
    int shownext(int color);
    int dfs(int direction, int deep, int from_x, int from_y, const int& to_x, const int& to_y);
    int GameOver();

    CStatic m_next1;
    CStatic m_next2;
    CStatic m_next3;
    CStatic m_map00;
    CStatic m_map01;
    CStatic m_map02;
    CStatic m_map03;
    CStatic m_map04;
    CStatic m_map05;
    CStatic m_map06;
    CStatic m_map07;
    CStatic m_map08;
    CStatic m_map10;
    CStatic m_map11;
    CStatic m_map12;
    CStatic m_map13;
    CStatic m_map14;
    CStatic m_map15;
    CStatic m_map16;
    CStatic m_map17;
    CStatic m_map18;
    CStatic m_map20;
    CStatic m_map21;
    CStatic m_map22;
    CStatic m_map23;
    CStatic m_map24;
    CStatic m_map25;
    CStatic m_map26;
    CStatic m_map27;
    CStatic m_map28;
    CStatic m_map30;
    CStatic m_map31;
    CStatic m_map32;
    CStatic m_map33;
    CStatic m_map34;
    CStatic m_map35;
    CStatic m_map36;
    CStatic m_map37;
    CStatic m_map38;
    CStatic m_map40;
    CStatic m_map41;
    CStatic m_map42;
    CStatic m_map43;
    CStatic m_map44;
    CStatic m_map45;
    CStatic m_map46;
    CStatic m_map47;
    CStatic m_map48;
    CStatic m_map50;
    CStatic m_map51;
    CStatic m_map52;
    CStatic m_map53;
    CStatic m_map54;
    CStatic m_map55;
    CStatic m_map56;
    CStatic m_map57;
    CStatic m_map58;
    CStatic m_map60;
    CStatic m_map61;
    CStatic m_map62;
    CStatic m_map63;
    CStatic m_map64;
    CStatic m_map65;
    CStatic m_map66;
    CStatic m_map67;
    CStatic m_map68;
    CStatic m_map70;
    CStatic m_map71;
    CStatic m_map72;
    CStatic m_map73;
    CStatic m_map74;
    CStatic m_map75;
    CStatic m_map76;
    CStatic m_map77;
    CStatic m_map78;
    CStatic m_map80;
    CStatic m_map81;
    CStatic m_map82;
    CStatic m_map83;
    CStatic m_map84;
    CStatic m_map85;
    CStatic m_map86;
    CStatic m_map87;
    CStatic m_map88;
};
