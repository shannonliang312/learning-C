/****************************************************************
 **                                                            											 **
 **    (C)Copyright 2006-2009, American Megatrends Inc.        			 **
 **                                                            											 **
 **            All Rights Reserved.                            									 **
 **                                                            											 **
 **        5555 Oakbrook Pkwy Suite 200, Norcross,             					 **
 **                                                            											 **
 **        Georgia - 30093, USA. Phone-(770)-246-8600.         				 **
 **                                                            											 **
 ****************************************************************/


/*****************************************************************************
 *
 *   coreTypes.h
 *
 *****************************************************************************/
#ifndef CORE_TYPES_H
#define CORE_TYPES_H

#ifdef __KERNEL__
#include <linux/types.h>
#include <linux/version.h>
#endif

/*@-incondefs@*/
/*@-likelybool@*/
/*@-constuse@*/
/*@-typeuse@*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus                         /* thus must be a .c program */
/*@-cppnames@*/
#ifdef __KERNEL__
#if (LINUX_VERSION_CODE <=  KERNEL_VERSION(2,6,15))  //NOTE: bool is already defined in linux/types.h
    typedef unsigned char bool;
#endif
#else
    typedef unsigned char bool;
#endif
    #define false (bool)0
    #define true  (bool)1
    typedef int BOOL ;
/*@=cppnames@*/
#else
    #ifndef _WIN32
        #define BOOL bool
    #endif
#endif


#ifndef FALSE
    #define      FALSE   0
    #define      TRUE    1
#endif

typedef   char int8;
typedef   signed char    int8s;
typedef          char    CHAR;
typedef unsigned char  	 uint8;
#ifndef __KERNEL__
typedef unsigned char    u8;
#endif
typedef unsigned char    UINT8;
typedef unsigned char    UCHAR;
typedef unsigned char    BYTE;            


typedef          short   int16;
typedef          short   INT16;
typedef unsigned short   uint16;
#ifndef __KERNEL__
typedef unsigned short   u16;             
#endif
typedef unsigned short   UINT16;
typedef unsigned short   TWOBYTES;         
typedef unsigned short   WORD;         



typedef          int     int32;
typedef unsigned int     uint32;
#ifndef __KERNEL__
typedef unsigned int     u32;             
#endif
typedef unsigned int   FOURBYTES;


typedef unsigned long long   uint64;


#if defined(_MSC_VER)                       /* automatically specified by VisualStudio compiler */
    /* already defined by basetsd.h, so to avoid warnings, don't define here */
#else
    typedef          bool    BOOLEAN;
    typedef          int    INT32;
    typedef unsigned int    UINT32;
#endif

#ifdef _WIN32
 #define ssize_t size_t
#endif

#ifdef _WIN32
#include <windows.h>
#else
	typedef void *			HANDLE;
	typedef void *			LPVOID;
        typedef unsigned int        	DWORD;         
#endif

/*-------------------------------------------------------------------------
 *
 *  types internal to the core library
 *
 *-------------------------------------------------------------------------*/
#define CORE_CHAR_TO_Core_Id(a,b,c,d) ( ((Core_Id)a<<24) | ((Core_Id)b<<16) | (c<<8) | d )
typedef uint32 Core_Id;

#ifdef __cplusplus
}
#endif

/*@=incondefs@*/
/*@=likelybool@*/
/*@=constuse@*/
/*@=typeuse@*/

#if defined ( __linux__ )
typedef int SOCKET;
#endif

#endif /* __CORE_TYPES_H__ */
