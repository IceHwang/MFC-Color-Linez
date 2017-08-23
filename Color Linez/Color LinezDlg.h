
// Color LinezDlg.h : 头文件
//

#pragma once
#include "afxwin.h"




// CColorLinezDlg 对话框
class CColorLinezDlg : public CDialogEx
{
// 构造
public:
	CColorLinezDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLORLINEZ_DIALOG };
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
    int MoveJudge(const int froms,const int tos);//1为可移动,0为不可移动
    int EraseJudge(int position);//position为移动后的位置或新产生的位置,只有在position附近会发生消除,返回消去的个数
    int ShowNext(int color);//显示预告,color是预告的颜色值为第一张*100+第二张*10+第三张
    int ShowMap();//显示棋盘
    int CircleProduce();//返回值为x*10+y,确保不覆盖,若返回-1,则游戏结束
    int ShowPredictionAndChange();//出现预告中棋子并更新预告,若返回-1则已填满,游戏结束.
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
