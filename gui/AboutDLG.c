/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.22                          *
*        Compiled Jul  4 2013, 15:16:01                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/


#include "DIALOG.h"
#include "includes.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)
#define ID_MULTIEDIT_0     (GUI_ID_USER + 0x01)
#define ID_BUTTON_0     (GUI_ID_USER + 0x02)
#define ID_BUTTON_1     (GUI_ID_USER + 0x03)


/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static const char Cancel[]="\xe8\xbf\x94\xe5\x9b\x9e";


static const char Update[]="\xe5\x8d\x87\xe7\xba\xa7";

//退出
static const char Quit[]="\xe9\x80\x80\xe5\x87\xba";


static const char *HelpMsg[45]={
   "1.\xe7\xbb\xbf\xe8\x89\xb2\xe5\x92\x8c",

    "\xe7\xba\xa2\xe8\x89\xb2\xe6\x8c\x89\xe9\x94\xae",

    "\xe5\xaf\xb9\xe5\xba\x94\xe7\x9a\x84\xe5\xb0\xb1",

    "\xe6\x98\xaf\xe5\xb1\x8f\xe5\xb9\x95\xe4\xb8\xad",

    "\xe7\x9a\x84\xe4\xb8\xa4\xe4\xb8\xaa\xe7\x9b\xb8",

    "\xe5\x90\x8c\xe9\xa2\x9c\xe8\x89\xb2\xe7\x9a\x84",

    "\xe6\x8c\x89\xe9\x92\xae\xef\xbc\x88\xe7\xa1\xae\xe5\xae\x9a",

    "\xe6\x88\x96\xe8\x80\x85\xe9\x80\x80\xe5\x87\xba\xef\xbc\x89\n\n",

    "2.\xe7\x94\xa8\xe4\xb8\x8a\xe4\xb8\x8b",

    "\xe6\x96\xb9\xe5\x90\x91\xe9\x94\xae\xe5\x8f\xaf",

    "\xe4\xbb\xa5\xe5\xaf\xb9\xe7\x9b\xb8\xe5\xba\x94",

    "\xe9\x80\x89\xe9\xa1\xb9\xe8\xbf\x9b\xe8\xa1\x8c",

    "\xe9\x80\x89\xe6\x8b\xa9\n\n",

    "3.\xe9\x80\x89\xe4\xb8\xad\xe7\x9b\xb8",

    "\xe5\xba\x94\xe9\x80\x89\xe9\xa1\xb9\xe5\x90\x8e\xef\xbc\x8c",

    "\xe6\x8c\x89OK\xe9\x94\xae\xe8\xbf\x9b",

    "\xe5\x85\xa5\xe7\xbc\x96\xe8\xbe\x91",
  
};

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, NULL, ID_WINDOW_0, 0, 0, 240, 295, 0, 0x0, 0 },
  { MULTIEDIT_CreateIndirect, NULL, ID_MULTIEDIT_0, 1, 2, 238, 255, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, Quit,    ID_BUTTON_0, 175, 264, 55, 25, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, Update,  ID_BUTTON_1,  8,  264, 55, 25, 0, 0x0, 0 },
};


/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  int i;
  switch (pMsg->MsgId) { 
  case WM_INIT_DIALOG:

    
    GUI_UC_SetEncodeUTF8();
    
     //
    // Initialization of 'Multiedit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIEDIT_0);
    MULTIEDIT_SetFont(hItem,&GUI_Font_Song_16);
    MULTIEDIT_SetWrapWord(hItem);//启用自动换行
    MULTIEDIT_SetReadOnly(hItem,1);//只读模式
    //MULTIEDIT_SetMaxNumChars(hItem,512);
    for(i=0;i<38;i++)
    {
        
        MULTIEDIT_AddText(hItem, HelpMsg[i]);

    }
    hItem=WM_GetDialogItem(pMsg->hWin,ID_BUTTON_0);
    BUTTON_SetBkColor(hItem,0,GUI_YELLOW);
    WIDGET_AndState(hItem,WIDGET_STATE_FOCUSSABLE);
    
    hItem=WM_GetDialogItem(pMsg->hWin,ID_BUTTON_1);
    BUTTON_SetBkColor(hItem,0,GUI_GREEN);
    WIDGET_AndState(hItem,WIDGET_STATE_FOCUSSABLE);

    
    break;
  

  case WM_KEY:
    {
        if((((WM_KEY_INFO *)(pMsg->Data.p))->PressedCnt)==1)
        {
            switch(((WM_KEY_INFO*)(pMsg->Data.p))->Key)
            {
                case GUI_KEY_YELLOW:
                    WM_DeleteWindow(g_hWin_about);
                    g_hWin_about=0;
                    WM_ShowWindow(g_hWin_TimeBar);
                    WM_ShowWindow(g_hWin_Date);
                    WM_SetFocus(g_hWin_menu);
                    break;
                case GUI_KEY_GREEN:
                    //ERR_NOTE(g_hWin_about, GUI_MSBOX_UPDATE_CFM);
                    ERR_NOTE(g_hWin_about,8);
                    
                    //DEV_Power_Off();

                    //while(1);
                    break;
            }
        }
    }
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Createabout
*/
WM_HWIN Createabout(void);
WM_HWIN Createabout(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, g_hWin_menu, 0, 0);
  return hWin;
}






