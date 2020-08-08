#pragma once

//DLL

#ifndef DLL_IMPORT
#define		DLL		__declspec(dllexport)
#else
#define		DLL		__declspec(dllimport)
#endif

#define		CCHECK(a,b,r)		if(a == b) return r
#define		NCCHECK(a,b,r)		if(a != b) return r


#define		RET_VOID
#define		RET_INT			0
#define		RET_CHAR		''
#define		RET_STR			""
#define		RET_FLOAT		0.0f
#define		RET_DOUBLE		0.0