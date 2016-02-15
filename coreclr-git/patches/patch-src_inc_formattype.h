$NetBSD$

--- src/inc/formattype.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/inc/formattype.h
@@ -105,7 +105,7 @@ inline BOOL IsDup(mdToken tk)
     }
     return FALSE;
 }
-#define MAKE_NAME_IF_NONE(psz, tk) { if((!(psz && *psz))||IsDup(tk)) { char* sz = (char*)_alloca(16); \
+#define MAKE_NAME_IF_NONE(psz, tk) { if((!(psz && *psz))||IsDup(tk)) { char* sz = (char*)Alloca(16); \
 sprintf_s(sz,16,"$%s$%X",szStdNamePrefix[tk>>24],tk&0x00FFFFFF); psz = sz; } }
 
 
