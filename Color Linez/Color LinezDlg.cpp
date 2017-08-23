
// Color LinezDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Color Linez.h"
#include "Color LinezDlg.h"
#include "afxdialogex.h"
#include "GetNameDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



//ȫ�ֱ���
int map[9][9];
int choicemap[9][9];
int searchmap[9][9];
int gameturn;
int gamestatus;//��Ϸ״̬,1Ϊ��Ϸ��,0Ϊ��Ϸ��
int combo;//������
int next[3];//Ԥ�����������ɫ
const int x[4][4] = {
    { -1,0,1,0 },
    { 0,1,0,-1 },
    { 1,0,-1,0 },
    { 0,-1,0,1 }
};
const int y[4][4] = {
    { 0,-1,0,1 },
    { -1,0,1,0 },
    { 0,1,0,-1 },
    { 1,0,-1,0 }
};
int rank[8] = {20000,15000,13000,10000,9000,7000,5000,1000};
CString name[8] = { _T("̫������"),_T("��ˮ����н��"),_T("����ɳ��van��"),_T("����֮��"),_T("�������ְ���"),_T("̩ʽϴͷ��"),_T("�η౦"),_T("����Ƕ�үү") };
CString myname = _T("����ȼ����");





// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CColorLinezDlg �Ի���



CColorLinezDlg::CColorLinezDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COLORLINEZ_DIALOG, pParent)
    , m_score(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CColorLinezDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_Score, m_score);
    DDX_Control(pDX, IDC_STATIC_NEXT1, m_next1);
    DDX_Control(pDX, IDC_STATIC_NEXT2, m_next2);
    DDX_Control(pDX, IDC_STATIC_NEXT3, m_next3);
    DDX_Control(pDX, IDC_STATIC_MAP00, m_map00);
    DDX_Control(pDX, IDC_STATIC_MAP10, m_map01);
    DDX_Control(pDX, IDC_STATIC_MAP20, m_map02);
    DDX_Control(pDX, IDC_STATIC_MAP30, m_map03);
    DDX_Control(pDX, IDC_STATIC_MAP40, m_map04);
    DDX_Control(pDX, IDC_STATIC_MAP50, m_map05);
    DDX_Control(pDX, IDC_STATIC_MAP60, m_map06);
    DDX_Control(pDX, IDC_STATIC_MAP70, m_map07);
    DDX_Control(pDX, IDC_STATIC_MAP80, m_map08);
    DDX_Control(pDX, IDC_STATIC_MAP01, m_map10);
    DDX_Control(pDX, IDC_STATIC_MAP11, m_map11);
    DDX_Control(pDX, IDC_STATIC_MAP21, m_map12);
    DDX_Control(pDX, IDC_STATIC_MAP31, m_map13);
    DDX_Control(pDX, IDC_STATIC_MAP41, m_map14);
    DDX_Control(pDX, IDC_STATIC_MAP51, m_map15);
    DDX_Control(pDX, IDC_STATIC_MAP61, m_map16);
    DDX_Control(pDX, IDC_STATIC_MAP71, m_map17);
    DDX_Control(pDX, IDC_STATIC_MAP81, m_map18);
    DDX_Control(pDX, IDC_STATIC_MAP02, m_map20);
    DDX_Control(pDX, IDC_STATIC_MAP12, m_map21);
    DDX_Control(pDX, IDC_STATIC_MAP22, m_map22);
    DDX_Control(pDX, IDC_STATIC_MAP32, m_map23);
    DDX_Control(pDX, IDC_STATIC_MAP42, m_map24);
    DDX_Control(pDX, IDC_STATIC_MAP52, m_map25);
    DDX_Control(pDX, IDC_STATIC_MAP62, m_map26);
    DDX_Control(pDX, IDC_STATIC_MAP72, m_map27);
    DDX_Control(pDX, IDC_STATIC_MAP82, m_map28);
    DDX_Control(pDX, IDC_STATIC_MAP03, m_map30);
    DDX_Control(pDX, IDC_STATIC_MAP13, m_map31);
    DDX_Control(pDX, IDC_STATIC_MAP23, m_map32);
    DDX_Control(pDX, IDC_STATIC_MAP33, m_map33);
    DDX_Control(pDX, IDC_STATIC_MAP43, m_map34);
    DDX_Control(pDX, IDC_STATIC_MAP53, m_map35);
    DDX_Control(pDX, IDC_STATIC_MAP63, m_map36);
    DDX_Control(pDX, IDC_STATIC_MAP73, m_map37);
    DDX_Control(pDX, IDC_STATIC_MAP83, m_map38);
    DDX_Control(pDX, IDC_STATIC_MAP04, m_map40);
    DDX_Control(pDX, IDC_STATIC_MAP14, m_map41);
    DDX_Control(pDX, IDC_STATIC_MAP24, m_map42);
    DDX_Control(pDX, IDC_STATIC_MAP34, m_map43);
    DDX_Control(pDX, IDC_STATIC_MAP44, m_map44);
    DDX_Control(pDX, IDC_STATIC_MAP54, m_map45);
    DDX_Control(pDX, IDC_STATIC_MAP64, m_map46);
    DDX_Control(pDX, IDC_STATIC_MAP74, m_map47);
    DDX_Control(pDX, IDC_STATIC_MAP84, m_map48);
    DDX_Control(pDX, IDC_STATIC_MAP05, m_map50);
    DDX_Control(pDX, IDC_STATIC_MAP15, m_map51);
    DDX_Control(pDX, IDC_STATIC_MAP25, m_map52);
    DDX_Control(pDX, IDC_STATIC_MAP35, m_map53);
    DDX_Control(pDX, IDC_STATIC_MAP45, m_map54);
    DDX_Control(pDX, IDC_STATIC_MAP55, m_map55);
    DDX_Control(pDX, IDC_STATIC_MAP65, m_map56);
    DDX_Control(pDX, IDC_STATIC_MAP75, m_map57);
    DDX_Control(pDX, IDC_STATIC_MAP85, m_map58);
    DDX_Control(pDX, IDC_STATIC_MAP06, m_map60);
    DDX_Control(pDX, IDC_STATIC_MAP16, m_map61);
    DDX_Control(pDX, IDC_STATIC_MAP26, m_map62);
    DDX_Control(pDX, IDC_STATIC_MAP36, m_map63);
    DDX_Control(pDX, IDC_STATIC_MAP46, m_map64);
    DDX_Control(pDX, IDC_STATIC_MAP56, m_map65);
    DDX_Control(pDX, IDC_STATIC_MAP66, m_map66);
    DDX_Control(pDX, IDC_STATIC_MAP76, m_map67);
    DDX_Control(pDX, IDC_STATIC_MAP86, m_map68);
    DDX_Control(pDX, IDC_STATIC_MAP07, m_map70);
    DDX_Control(pDX, IDC_STATIC_MAP17, m_map71);
    DDX_Control(pDX, IDC_STATIC_MAP27, m_map72);
    DDX_Control(pDX, IDC_STATIC_MAP37, m_map73);
    DDX_Control(pDX, IDC_STATIC_MAP47, m_map74);
    DDX_Control(pDX, IDC_STATIC_MAP57, m_map75);
    DDX_Control(pDX, IDC_STATIC_MAP67, m_map76);
    DDX_Control(pDX, IDC_STATIC_MAP77, m_map77);
    DDX_Control(pDX, IDC_STATIC_MAP87, m_map78);
    DDX_Control(pDX, IDC_STATIC_MAP08, m_map80);
    DDX_Control(pDX, IDC_STATIC_MAP18, m_map81);
    DDX_Control(pDX, IDC_STATIC_MAP28, m_map82);
    DDX_Control(pDX, IDC_STATIC_MAP38, m_map83);
    DDX_Control(pDX, IDC_STATIC_MAP48, m_map84);
    DDX_Control(pDX, IDC_STATIC_MAP58, m_map85);
    DDX_Control(pDX, IDC_STATIC_MAP68, m_map86);
    DDX_Control(pDX, IDC_STATIC_MAP78, m_map87);
    DDX_Control(pDX, IDC_STATIC_MAP88, m_map88);
}

BEGIN_MESSAGE_MAP(CColorLinezDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_COMMAND(ID_GAME_EXIT, &CColorLinezDlg::OnGameExit)
    ON_COMMAND(ID_HELP_ABOUTTHISGAME, &CColorLinezDlg::OnHelpAboutthisgame)
    ON_BN_CLICKED(IDCANCEL, &CColorLinezDlg::OnBnClickedCancel)
    ON_COMMAND(ID_HELP_RULES, &CColorLinezDlg::OnHelpRules)
    ON_WM_LBUTTONDOWN()
    ON_COMMAND(ID_GAME_NEWGAME, &CColorLinezDlg::OnGameNewgame)
    ON_COMMAND(ID_GAME_LEADERBOARD, &CColorLinezDlg::OnGameLeaderboard)
END_MESSAGE_MAP()


// CColorLinezDlg ��Ϣ�������

BOOL CColorLinezDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CColorLinezDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CColorLinezDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CColorLinezDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}









//��Ϸ�������
void CColorLinezDlg::OnGameExit()
{
    // TODO: �ڴ���������������
    if (IDYES == MessageBox(_T("�˳�?"), _T("��ɫ����"), MB_YESNO))
    {
        exit(0);
    }
}

void CColorLinezDlg::OnHelpAboutthisgame()
{
    // TODO: �ڴ���������������
    MessageBox(_T("�汾:1.0.1\n����:HHB"), _T("��ɫ����"));
}

void CColorLinezDlg::OnBnClickedCancel()
{

    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if (IDYES == MessageBox(_T("�˳�?"), _T("��ɫ����"), MB_YESNO))
    {
        exit(0);
    }
    //CDialogEx::OnCancel();
}

void CColorLinezDlg::OnHelpRules()
{
    // TODO: �ڴ���������������
    MessageBox(_T("���㽫5��������ͬɫС���ų�һ�����ߡ����߻�б��ʱ����ЩС�򶼻ᱻ��ȥ�����ҵ÷֡�\nͬʱ��ȥ��С��Խ�࣬�÷�Խ�ߣ�����������ȥС����н����÷֡�\n������ƶ�С�������Ե�������еط���\nÿһ���ƶ�֮����������3��С��С��һ����������ɫ��"), _T("��ɫ����"));
}

void CColorLinezDlg::OnGameNewgame()
{
    // TODO: �ڴ���������������
    GameStart();
}

void CColorLinezDlg::OnGameLeaderboard()
{
    // TODO: �ڴ���������������
    CString ranking;
    for (int i = 0; i < 8; ++i)
    {
        CString tmp;
        tmp.Format(_T("%-15s%-d\n"), name[i], rank[i]);
        ranking += tmp;
    }
    MessageBox(ranking,_T("��ɫ����"));

}




//��Ϸ�߼�����
void CColorLinezDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    if(gamestatus==0)//������Ϸ��
        CDialogEx::OnLButtonDown(nFlags, point);
    else 
    {

        int mouse_x, mouse_y;
        mouse_x = point.x;
        mouse_y = point.y;
        if (mouse_x >= 200 && mouse_x <= 649 && mouse_y >= 200 && mouse_y <= 649)
        {
            GameMain((mouse_x - 200) / 50, (mouse_y - 200) / 50);//��Чλ��
        }
        CDialogEx::OnLButtonDown(nFlags, point);
    }
}

void CColorLinezDlg::GameMain(int pos_x, int pos_y)
{
    //�ж���Ϸ�Ƿ����
    int flag = 0;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (map[i][j] == 0)//�п�λʱflag=1
                flag = 1;
        }
    }
    if (flag == 0)
        GameOver();



    static int from_x = -1, from_y = -1, to_x = -1, to_y = -1;
    gameturn++;
    if (gameturn % 2 == 1)//����ѡ��,gameturnΪ����
    {
        if (map[pos_x][pos_y] == 0)//ѡ��ʧ��
        {
            gameturn--;
            ShowMap();
            return;
        }
        else//ѡ�ӳɹ�
        {
            choicemap[pos_x][pos_y] = 1;
            from_x = pos_x;
            from_y = pos_y;
        }


        ShowMap();
        return;
    }



    //��������,gameturnΪż��
    if (choicemap[pos_x][pos_y] == 1)//��������,����ȡ����ѡ��
    {
        choicemap[pos_x][pos_y] = 0;
        from_x = -1;
        from_y = -1;
        gameturn -= 2;
        ShowMap();
        return;
    }
    else if (map[pos_x][pos_y] != 0)//����ʧ��,�ѱ�ռ��,ȡ����ѡ��
    {
        choicemap[from_x][from_y] = 0;
        from_x = -1;
        from_y = -1;
        gameturn -= 2;
        ShowMap();
        return;
    }


    else//���ӳɹ�,����֪�Ƿ���Գɹ��ƶ�
    {
        to_x = pos_x;
        to_y = pos_y;
        

        if (MoveJudge(from_x * 10 + from_y, to_x * 10 + to_y) == 0)//�ƶ�ʧ�ܵ�������ʧ��,ȡ����ѡ��
        {
            choicemap[from_x][from_y] = 0;
            to_x = -1;
            to_y = -1;
            from_x = -1;
            from_y = -1;
            gameturn -= 2;
            ShowMap();
            return;
        }
        else//�ɹ��ƶ�
        {

            choicemap[from_x][from_y] = 0;

            //�ƶ�
            map[to_x][to_y] = map[from_x][from_y];
            map[from_x][from_y] = 0;
            


            int erase = EraseJudge(to_x * 10 + to_y);//������ȥС��ĸ���
            if (erase != 0)//�ж��Ƿ�����ȥ,
            {
                combo++;
                m_score += combo * 200 + (erase - 2) * 100;//����÷�
                UpdateData(FALSE);
            }
            else
            {
                combo = 0;
            }

            from_x = -1;
            from_y = -1;
            to_x = -1;
            to_y = -1;


            //����Ԥ�������Ӳ�����Ԥ��
            if (ShowPredictionAndChange() == -1)
            {
                //��Ϸ����
                GameOver();
            }
            return;


        }






    }
    ShowMap();
    MessageBox(_T("Unexpected Result!\nError:GameMain()"));
    return;





}

void CColorLinezDlg::GameStart()
{
    //�жϵ�ǰ�����Ƿ��Ƽ�¼
    int myrank;
    for (myrank = 7; myrank >= 0;)
    {
        if (m_score > rank[myrank])
        {
            --myrank;
        }
        else
        {
            break;
        }
    }
    myrank++;
    if (myrank <= 7)
    {
        //��������,��ȡ����
        int res;
        CGetNameDialog dia;
        res = dia.DoModal();



        //��������
        int t_score, mm_score = m_score, t_rank = myrank;
        CString t_name, mm_name = myname;
        for (; t_rank < 8; t_rank++)
        {
            t_score = rank[t_rank];
            t_name = name[t_rank];
            rank[t_rank] = mm_score;
            name[t_rank] = mm_name;
            mm_score = t_score;
            mm_name = t_name;

        }
    }


    //�ؿ���Ϸ
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            map[i][j] = 0;
            choicemap[i][j] = 0;
        }
    }
    srand(time(0));
    gamestatus = 1;
    gameturn = 0;
    m_score = 0;
    UpdateData(FALSE);

    //������ʼ���
    for (int i = 0; i < 5; ++i)
    {
        int pos = CircleProduce();//����λ��
        int x = pos / 10, y = pos % 10;
        map[x][y] = 1 + rand() % 5;//������ɫ,0Ϊ��,1Ϊ��,2Ϊ��,3Ϊ��,4Ϊ��,5Ϊ��
    }
    ShowMap();

    //Ԥ�������
    
    for (int i = 0; i < 3; ++i)
    {
        next[i] = 1 + rand() % 5;
    }
    ShowNext(next[0] * 100 + next[1] * 10 + next[2]);
    
}

int CColorLinezDlg::GameOver()
{
    gamestatus = 0;
    MessageBox(_T("��Ϸ����"), _T("��ɫ����"));
    int myrank;
    for (myrank = 7; myrank >= 0;)
    {
        if (m_score > rank[myrank])
        {
            --myrank;
        }
        else
        {
            break;
        }
    }
    myrank++;
    if (myrank <= 7)
    {
        //��������,��ȡ����
        int res;
        CGetNameDialog dia;
        res = dia.DoModal();



        //��������
        int t_score, mm_score = m_score, t_rank = myrank;
        CString t_name, mm_name = myname;
        for (; t_rank < 8; t_rank++)
        {
            t_score = rank[t_rank];
            t_name = name[t_rank];
            rank[t_rank] = mm_score;
            name[t_rank] = mm_name;
            mm_score = t_score;
            mm_name = t_name;

        }



    }


    return 0;
}

int CColorLinezDlg::MoveJudge(const int froms, const int tos)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            searchmap[i][j] = 0;
        }
    }
    int from_x, from_y, to_x, to_y;
    from_x = froms / 10;
    from_y = froms % 10;
    to_x = tos / 10;
    to_y = tos % 10;
    if(map[to_x][to_y]!=0)
        return 0;


    //DFS ׼��
    //����Ϊ: 0�������� ,1��������,2��������,3��������
    

    int direction;
    if (to_y < from_y && to_x >= from_x)
    {
        direction = 1;//������������
    }
    else if (to_y >= from_y && to_x > from_x)
    {
        direction = 2;//������������
    }
    else if (to_y > from_y && to_x <= from_x)
    {
        direction = 3;//������������
    }
    else if (to_y <= from_y && to_x < from_x)
    {
        direction = 0;//������������
    }


    return dfs(direction, 1, from_x + x[direction][0], from_y + y[direction][0], to_x, to_y) || dfs(direction,  1, from_x + x[direction][1], from_y + y[direction][1], to_x, to_y) || dfs(direction, 1, from_x + x[direction][2], from_y + y[direction][2], to_x, to_y) || dfs(direction, 1, from_x + x[direction][3], from_y + y[direction][3], to_x, to_y);
     
}


int CColorLinezDlg::dfs(int direction,  int deep,int from_x,int from_y, const int& to_x, const int& to_y)
{
    if (from_x < 0 || from_x>8 || from_y < 0 || from_y>8)//����Խ��
    {
        return 0;
    }

    if (searchmap[from_x][from_y] == 1)//�����ظ�����
    {
        return 0;
    }
    searchmap[from_x][from_y] = 1;

    

    if (from_x == to_x && from_y == to_y)//�ɹ��ƶ�
    {
        return 1;
    }
    else if (map[from_x][from_y] != 0)//����ͨ��
    {
        return 0;
    }
    else if (deep>500)//�����������
    {
        return 0;
    }
    else//��������
    {
        return dfs(direction, deep + 1, from_x + x[direction][0], from_y + y[direction][0], to_x, to_y) || dfs(direction, deep + 1, from_x + x[direction][1], from_y + y[direction][1], to_x, to_y) || dfs(direction, deep + 1, from_x + x[direction][2], from_y + y[direction][2], to_x, to_y) || dfs(direction, deep + 1, from_x + x[direction][3], from_y + y[direction][3], to_x, to_y);
    }
}


int CColorLinezDlg::EraseJudge(int postion)
{
    int pos_x = postion / 10, pos_y = postion % 10;
    int erase = 0;
    int delta = 1;

    //����
    for (delta = 1; pos_x - delta >= 0;delta++)//���
    {
        if (map[pos_x][pos_y]== map[pos_x-delta][pos_y])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    for (delta = 1; pos_x + delta <= 8; delta++)//�ұ�
    {
        if (map[pos_x][pos_y] == map[pos_x + delta][pos_y])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    if (erase >= 4)//�ɳɹ���ȥerase��
    {
        //��ȥ
        for (delta = 1; pos_x - delta >= 0; delta++)
        {
            if (map[pos_x][pos_y] == map[pos_x - delta][pos_y])
            {
                map[pos_x - delta][pos_y] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        for (delta = 1; pos_x + delta <= 8; delta++)
        {
            if (map[pos_x][pos_y] == map[pos_x + delta][pos_y])
            {
                map[pos_x + delta][pos_y] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        map[pos_x][pos_y] = 0;
        return erase + 1;
    }
    erase = 0;//����5��,��ȥʧ��

    //����
    for (delta = 1; pos_y - delta >= 0; delta++)//�ϱ�
    {
        if (map[pos_x][pos_y] == map[pos_x][pos_y - delta])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    for (delta = 1; pos_y + delta <= 8; delta++)//�±�
    {
        if (map[pos_x][pos_y] == map[pos_x][pos_y + delta])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    if (erase >= 4)//�ɳɹ���ȥerase��
    {
        //��ȥ
        for (delta = 1; pos_y - delta >= 0; delta++)//�ϱ�
        {
            if (map[pos_x][pos_y] == map[pos_x][pos_y - delta])//����ȥ,����һ����5��
            {
                map[pos_x][pos_y - delta] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        for (delta = 1; pos_y + delta <= 8; delta++)//�±�
        {
            if (map[pos_x][pos_y] == map[pos_x][pos_y + delta])//����ȥ,����һ����5��
            {
                map[pos_x][pos_y + delta] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        map[pos_x][pos_y] = 0;
        return erase + 1;
    }
    erase = 0;//����5��,��ȥʧ��

    //����
    for (delta = 1; pos_x - delta >= 0 && pos_y - delta >= 0; delta++)//����
    {
        if (map[pos_x][pos_y] == map[pos_x - delta][pos_y - delta])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    for (delta = 1; pos_x + delta <= 8 && pos_y + delta <= 8; delta++)//����
    {
        if (map[pos_x][pos_y] == map[pos_x + delta][pos_y + delta])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    if (erase >= 4)//�ɳɹ���ȥerase��
    {
        //��ȥ
        for (delta = 1; pos_x - delta >= 0 && pos_y - delta >= 0; delta++)//����
        {
            if (map[pos_x][pos_y] == map[pos_x - delta][pos_y - delta])//����ȥ,����һ����5��
            {
                map[pos_x - delta][pos_y - delta] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        for (delta = 1; pos_x + delta <= 8 && pos_y + delta <= 8; delta++)//����
        {
            if (map[pos_x][pos_y] == map[pos_x + delta][pos_y + delta])//����ȥ,����һ����5��
            {
                map[pos_x + delta][pos_y + delta] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        map[pos_x][pos_y] = 0;
        return erase + 1;
    }
    erase = 0;//����5��,��ȥʧ��

    //����
    for (delta = 1; pos_x + delta <= 8 && pos_y - delta >= 0; delta++)//����
    {
        if (map[pos_x][pos_y] == map[pos_x + delta][pos_y - delta])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    for (delta = 1; pos_x - delta >= 0 && pos_y + delta <= 8; delta++)//����
    {
        if (map[pos_x][pos_y] == map[pos_x - delta][pos_y + delta])//����ȥ,����һ����5��
        {
            erase++;
        }
        else//������ȥ
        {
            break;
        }
    }
    if (erase >= 4)//�ɳɹ���ȥerase��
    {
        //��ȥ
        for (delta = 1; pos_x + delta <= 8 && pos_y - delta >= 0; delta++)//����
        {
            if (map[pos_x][pos_y] == map[pos_x + delta][pos_y - delta])//����ȥ,����һ����5��
            {
                map[pos_x + delta][pos_y - delta] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        for (delta = 1; pos_x - delta >= 0 && pos_y + delta <= 8; delta++)//����
        {
            if (map[pos_x][pos_y] == map[pos_x - delta][pos_y + delta])//����ȥ,����һ����5��
            {
                map[pos_x - delta][pos_y + delta] = 0;
            }
            else//������ȥ
            {
                break;
            }
        }
        map[pos_x][pos_y] = 0;
        return erase + 1;
    }
    erase = 0;//����5��,��ȥʧ��


    //������ȥ
    return 0;
    
}

int CColorLinezDlg::shownext(int color)
{
    UpdateWindow();
    int next[3];
    next[0] = color / 100;
    next[1] = (color - next[0] * 100) / 10;
    next[2] = color % 10;

    static CStatic *pm_next[3] = { &m_next1, &m_next2,&m_next3 }; 
    CBitmap bitmap;
    HBITMAP hbmp;
    for (int i = 0; i < 3; ++i)
    {
        bitmap.LoadBitmapW(IDB_BITMAP1 + next[i] * 2);
        hbmp = (HBITMAP)bitmap.GetSafeHandle();
        (*pm_next[i]).SetBitmap(hbmp);
        bitmap.DeleteObject();
    }
    return 0;
}

int CColorLinezDlg::showmap()
{
    UpdateWindow();
    static CStatic *pm_map[9][9] = {
        { &m_map00,&m_map01, &m_map02,&m_map03,&m_map04,&m_map05,&m_map06,&m_map07,&m_map08 },
        { &m_map10,&m_map11, &m_map12,&m_map13,&m_map14,&m_map15,&m_map16,&m_map17,&m_map18 },
        { &m_map20,&m_map21, &m_map22,&m_map23,&m_map24,&m_map25,&m_map26,&m_map27,&m_map28 },
        { &m_map30,&m_map31, &m_map32,&m_map33,&m_map34,&m_map35,&m_map36,&m_map37,&m_map38 },
        { &m_map40,&m_map41, &m_map42,&m_map43,&m_map44,&m_map45,&m_map46,&m_map47,&m_map48 },
        { &m_map50,&m_map51, &m_map52,&m_map53,&m_map54,&m_map55,&m_map56,&m_map57,&m_map58 },
        { &m_map60,&m_map61, &m_map62,&m_map63,&m_map64,&m_map65,&m_map66,&m_map67,&m_map68 },
        { &m_map70,&m_map71, &m_map72,&m_map73,&m_map74,&m_map75,&m_map76,&m_map77,&m_map78 },
        { &m_map80,&m_map81, &m_map82,&m_map83,&m_map84,&m_map85,&m_map86,&m_map87,&m_map88 }
    };
    CBitmap bitmap;
    HBITMAP hbmp;
    int choice = 0;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (choicemap[i][j] == 1)
            {
                choice = 1;
            }
            else
            {
                choice = 0;
            }
            bitmap.LoadBitmapW(IDB_BITMAP1 + map[i][j] * 2 + choice);
            hbmp = (HBITMAP)bitmap.GetSafeHandle();
            (*pm_map[i][j]).SetBitmap(hbmp);
            bitmap.DeleteObject();
        }
    }
    return 0;
}

int CColorLinezDlg::CircleProduce()
{
    //�ж���Ϸ�Ƿ����
    int flag = 0;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (map[i][j]==0)//�п�λʱflag=1
                flag = 1;
        }
    }
    if (flag == 0)
        return -1;

    //
    int t_x, t_y;
    do
    {
        t_x = rand() % 9;
        t_y = rand() % 9;
    } while (map[t_x][t_y]);
    return t_x * 10 + t_y;
}

int CColorLinezDlg::ShowPredictionAndChange()
{
    //����Ԥ���е�����
    int next_xy;
    int pos[3];//�ϴ�Ԥ�Ե�����
    for (int i = 0; i < 3; ++i)
    {
        next_xy = CircleProduce();
        if (next_xy == -1)
            return -1;
        pos[i] = next_xy;
        map[next_xy / 10][next_xy % 10] = next[i];
    }
    ShowMap();

    //�ж��²������Ƿ�����ȥ
    int res = 0;
    res += EraseJudge(pos[0]);
    res += EraseJudge(pos[1]);
    res += EraseJudge(pos[2]);

    if (res > 0)//����ȥ
    {
        Sleep(1000);
        ShowMap();
    }


    //Ԥ�������
    
    for (int i = 0; i < 3; ++i)
    {
        next[i] = 1 + rand() % 5;
    }
    ShowNext(next[0] * 100 + next[1] * 10 + next[2]);

    return 0;
}


int CColorLinezDlg::ShowMap()
{
    showmap();
    showmap();
    return 0;
}

int CColorLinezDlg::ShowNext(int color)
{
    shownext(color);
    shownext(color);
    return 0;
}




