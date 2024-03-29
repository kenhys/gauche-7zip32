/*
 * gauche_7zip32.h
 */

/* Prologue */
#ifndef GAUCHE_GAUCHE_7ZIP32_H
#define GAUCHE_GAUCHE_7ZIP32_H

#include <gauche.h>
#include <gauche/extend.h>

#include <windows.h>
#include "7-zip32.h"

SCM_DECL_BEGIN

typedef struct _C7Zip32 {
  HANDLE dll;
  HANDLE handle;
} C7Zip32;

typedef struct _CHarc {
  HARC handle;
} CHarc;

/* LHA.DLL compatible API */
typedef int WINAPI (*WINAPI_SEVENZIP)(const HWND _hwnd, LPCSTR _szCmdLine, LPSTR _szOutput, const DWORD _dwSize);
typedef WORD  WINAPI (*WINAPI_SEVENZIPGETVERSION)(void);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETCURSORMODE)(void);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPSETCURSORMODE)(const BOOL _CursorMode);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETBACKGROUNDMODE)(void);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPSETBACKGROUNDMODE)(const BOOL _BackGroundMode);
typedef WORD  WINAPI (*WINAPI_SEVENZIPGETCURSORINTERVAL)(void);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPSETCURSORINTERVAL)(const WORD _Interval);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETRUNNING)(void);

typedef BOOL  WINAPI (*WINAPI_SEVENZIPCONFIGDIALOG)(const HWND _hwnd, LPSTR _szOptionBuffer, const int _iMode);
typedef BOOL WINAPI (*WINAPI_SEVENZIPCHECKARCHIVE)(LPCSTR _szFileName, const int _iMode);
typedef int   WINAPI (*WINAPI_SEVENZIPGETFILECOUNT)(LPCSTR _szArcFile);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPQUERYFUNCTIONLIST)(const int _iFunction);

typedef HARC  WINAPI (*WINAPI_SEVENZIPOPENARCHIVE)(const HWND _hwnd, LPCSTR _szFileName, const DWORD _dwMode);
typedef int   WINAPI (*WINAPI_SEVENZIPCLOSEARCHIVE)(HARC _harc);
typedef int   WINAPI (*WINAPI_SEVENZIPFINDFIRST)(HARC _harc, LPCSTR _szWildName, INDIVIDUALINFO *_lpSubInfo);
typedef int   WINAPI (*WINAPI_SEVENZIPFINDNEXT)(HARC _harc, INDIVIDUALINFO *_lpSubInfo);
typedef int   WINAPI (*WINAPI_SEVENZIPGETARCFILENAME)(HARC _harc, LPSTR _lpBuffer, const int _nSize);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETARCFILESIZE)(HARC _harc);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETARCORIGINALSIZE)(HARC _harc);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETARCCOMPRESSEDSIZE)(HARC _harc);
typedef WORD  WINAPI (*WINAPI_SEVENZIPGETARCRATIO)(HARC _harc);
typedef WORD  WINAPI (*WINAPI_SEVENZIPGETARCDATE)(HARC _harc);
typedef WORD  WINAPI (*WINAPI_SEVENZIPGETARCTIME)(HARC _harc);
typedef UINT  WINAPI (*WINAPI_SEVENZIPGETARCOSTYPE)(HARC _harc);
typedef int   WINAPI (*WINAPI_SEVENZIPISSFXFILE)(HARC _harc);
typedef int   WINAPI (*WINAPI_SEVENZIPGETFILENAME)(HARC _harc, LPSTR _lpBuffer, const int _nSize);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETORIGINALSIZE)(HARC _harc);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETCOMPRESSEDSIZE)(HARC _harc);
typedef WORD  WINAPI (*WINAPI_SEVENZIPGETRATIO)(HARC _harc);
typedef WORD  WINAPI (*WINAPI_SEVENZIPGETDATE)(HARC _harc);
typedef	WORD  WINAPI (*WINAPI_SEVENZIPGETTIME)(HARC _harc);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETCRC)(HARC _harc);
typedef int   WINAPI (*WINAPI_SEVENZIPGETATTRIBUTE)(HARC _harc);
typedef UINT  WINAPI (*WINAPI_SEVENZIPGETOSTYPE)(HARC _harc);
typedef int   WINAPI (*WINAPI_SEVENZIPGETMETHOD)(HARC _harc, LPSTR _lpBuffer, const int _nSize);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETWRITETIME)(HARC _harc);
typedef	DWORD WINAPI (*WINAPI_SEVENZIPGETCREATETIME)(HARC _harc);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETACCESSTIME)(HARC _harc);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETWRITETIMEEX)(HARC _harc, FILETIME *_lpftLastWriteTime);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETCREATETIMEEX)(HARC _harc, FILETIME *_lpftLastWriteTime);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETACCESSTIMEEX)(HARC _harc, FILETIME *_lpftLastWriteTime);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETARCCREATETIMEEX)(HARC _harc, FILETIME *_lpftCreationTime);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETARCACCESSTIMEEX)(HARC _harc, FILETIME *_lpftLastAccessTime);
typedef	BOOL  WINAPI (*WINAPI_SEVENZIPGETARCWRITETIMEEX)(HARC _harc, FILETIME *_lpftLastWriteTime);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETARCFILESIZEEX)(HARC _harc, ULHA_INT64 *_lpllSize);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETARCORIGINALSIZEEX)(HARC _harc, ULHA_INT64 *_lpllSize);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETARCCOMPRESSEDSIZEEX)(HARC _harc, ULHA_INT64 *_lpllSize);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETORIGINALSIZEEX)(HARC _harc, ULHA_INT64 *_lpllSize);
typedef BOOL  WINAPI (*WINAPI_SEVENZIPGETCOMPRESSEDSIZEEX)(HARC _harc, ULHA_INT64 *_lpllSize);

typedef BOOL WINAPI (*WINAPI_SEVENZIPSETOWNERWINDOW)(HWND _hwnd);
typedef BOOL WINAPI (*WINAPI_SEVENZIPCLEAROWNERWINDOW)(void);
typedef BOOL WINAPI (*WINAPI_SEVENZIPSETOWNERWINDOWEX)(HWND _hwnd, LPARCHIVERPROC _lpArcProc);
typedef BOOL WINAPI (*WINAPI_SEVENZIPKILLOWNERWINDOWEX)(HWND _hwnd);
typedef BOOL WINAPI (*WINAPI_SEVENZIPSETOWNERWINDOWEX64)(HWND _hwnd, LPARCHIVERPROC _lpArcProc, DWORD _dwStructSize);
typedef BOOL WINAPI (*WINAPI_SEVENZIPKILLOWNERWINDOWEX64)(HWND _hwnd);

typedef WORD WINAPI (*WINAPI_SEVENZIPGETSUBVERSION)();
typedef int  WINAPI (*WINAPI_SEVENZIPGETARCHIVETYPE)(LPCSTR _szFileName);
typedef BOOL WINAPI (*WINAPI_SEVENZIPSETUNICODEMODE)(BOOL _bUnicode);
typedef int WINAPI (*WINAPI_SEVENZIPSETDEFAULTPASSWORD)(HARC _harc, LPCSTR _szPassword);
typedef DWORD WINAPI (*WINAPI_SEVENZIPGETDEFAULTPASSWORD)(HARC _harc, LPSTR _szPassword, DWORD _dwSize);
typedef int WINAPI (*WINAPI_SEVENZIPPASSWORDDIALOG)(HWND _hwnd, LPSTR _szBuffer, DWORD _dwSize);
typedef BOOL WINAPI (*WINAPI_SEVENZIPSETPRIORITY)(const int _nPriority);

/*
 * The following entry is a dummy one.
 * Replace it for your declarations.
 */

extern ScmObj test_gauche_7zip32(void);

extern ScmClass *C7Zip32Class;
extern ScmClass *CHarcClass;

#define C7ZIP32_P(obj)      SCM_XTYPEP(obj, C7Zip32Class)
#define C7ZIP32_UNBOX(obj)  SCM_FOREIGN_POINTER_REF(C7Zip32*, obj)
#define C7ZIP32_BOX(ptr)    Scm_MakeForeignPointer(C7Zip32Class, ptr)

#define CHARC_P(obj)      SCM_XTYPEP(obj, CHarcClass)
#define CHARC_UNBOX(obj)  SCM_FOREIGN_POINTER_REF(CHarc*, obj)
#define CHARC_BOX(ptr)    Scm_MakeForeignPointer(CHarcClass, ptr)

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_GAUCHE_7ZIP32_H */
