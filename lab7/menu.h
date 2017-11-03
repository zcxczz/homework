/**************************************************************************************************/
/*  FILE NAME             :  menu.h                                                               */
/*  LANGUAGE              :  C                                                                    */
/*  AUTHOR                :  SA17225354                                                           */
/**************************************************************************************************/

/* Revision log:
 *  2017/11/03
 *
 */


#ifndef __MENU_H__
#define __MENU_H__


int MenuConfig(char* cmd, char* desc, int (*handler)(int argc, char* argv[]));


int ExecuteMenu();

#endif
