/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.20                          *
*        Compiled Mar 19 2013, 15:01:00                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "includes.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_0    (GUI_ID_USER + 0x01)
#define ID_BUTTON_1    (GUI_ID_USER + 0x02)
#define ID_TEXT_0      (GUI_ID_USER + 0x03)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static const char Cancel[]="\xe5\x8f\x96\xe6\xb6\x88";
static const char Confirm[]="\xe7\xa1\xae\xe5\xae\x9a";
static const char Worning[]="\xe8\xad\xa6\xe5\x91\x8a";
static const char WrnText[]="\xe7\xa1\xae\xe5\xae\x9a\xe6\xa0\xbc\xe5\xbc\x8f\xe5\x8c\x96\xe5\x86\x85\xe5\xad\x98\xe5\x90\x97\xef\xbc\x9f?";

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "ErrNote", ID_FRAMEWIN_0, 50,  82,  140, 120, 0, 0x64, 0 },
  { BUTTON_CreateIndirect,   Confirm,   ID_BUTTON_0,   7,   70, 50,  20,  0, 0x0,  0 },
  { BUTTON_CreateIndirect,   Cancel,    ID_BUTTON_1,   76,  70, 50,  20,  0, 0x0,  0 },
  { TEXT_CreateIndirect,     WrnText,    ID_TEXT_0,    7,   32,  125, 20,  0, 0x0,  0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};


WM_HWIN ERR_Get_Text(void)
{
    return WM_GetDialogItem(g_hWin_Err,ID_TEXT_0);
}


void ERR_Sel_Win(void)
{
    if(g_hWin_mem > 0)
    {
        WM_SetFocus(g_hWin_mem);
    }
    if(g_hWin_TimeSet> 0)
    {
        WM_SetFocus(g_hWin_TimeSet);
    }
    if(g_hWin_relay > 0)
    {
        WM_SetFocus(g_hWin_relay);
    }
    if(g_hWin_std>0)
    {
        WM_SetFocus(g_hWin_std);
    }
    if(g_hWin_about>0)
    {
        WM_SetFocus(g_hWin_about);
    }
}





/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  u8    sbuf[64];
  FRESULT res;
  FATFS fs;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'ErrNote'
    //
    //hItem = pMsg->hWin;
    FRAMEWIN_SetTitleHeight(pMsg->hWin, 16);
    FRAMEWIN_SetText(pMsg->hWin, Worning);
    FRAMEWIN_SetClientColor(pMsg->hWin,GUI_WHITE);
    
    hItem=WM_GetDialogItem(pMsg->hWin,ID_BUTTON_0);
    //WIDGET_AndState(hItem,WIDGET_STATE_FOCUSSABLE);
    BUTTON_SetBkColor(hItem,0,GUI_GREEN);

    hItem=WM_GetDialogItem(pMsg->hWin,ID_BUTTON_1);
    //WIDGET_AndState(hItem,WIDGET_STATE_FOCUSSABLE);
    BUTTON_SetBkColor(hItem,0,GUI_YELLOW);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {;}
    break;
  case WM_KEY:
    if((((WM_KEY_INFO *)(pMsg->Data.p))->PressedCnt)==1)
    {
        switch((((WM_KEY_INFO*)(pMsg->Data.p))->Key))
        {
            case GUI_KEY_YELLOW:
                WM_DeleteWindow(g_hWin_Err);
                ERR_Sel_Win();
                break;
            case GUI_KEY_GREEN:
                WM_DeleteWindow(g_hWin_Err);
                if(g_hWin_mem>0)
                {
                    SYS_ADD_TASK(SYS_TASK_FORMAT_DISK);
                }
                if(g_hWin_about>0)
                {
                  
                  if(g_sys_register_para.bootFlag != BOOT_REQUEST_ACT)
                  {
                      g_sys_register_para.bootFlag = BOOT_REQUEST_ACT;
                      DEV_Parameters_Write();
                  }
                  DEV_SoftReset();
                }
                ERR_Sel_Win();
                break;
        }
        break;
    }
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}


/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateErrNote
*/
WM_HWIN CreateErrNote(WM_HWIN paraentWin);
WM_HWIN CreateErrNote(WM_HWIN paraentWin)
{
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, g_hWin_mem, 0, 0);
  return hWin;
}

void ERR_NOTE(WM_HWIN paraentWin,int err_no);//,unsigned char *err_text);

void ERR_NOTE(WM_HWIN paraentWin,int err_no)//unsigned char *err_text)
{
    //WM_HWIN hWin;
    WM_HWIN hItem;
    g_hWin_Err=CreateErrNote(paraentWin);
    WM_SetFocus(g_hWin_Err);
    hItem=WM_GetDialogItem(g_hWin_Err,ID_TEXT_0);
    TEXT_SetText(hItem,&gc_messageBoxText[err_no][0]);

}

/*************************** End of file ****************************/
