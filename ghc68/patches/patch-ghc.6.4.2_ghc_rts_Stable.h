$NetBSD$

symbole stable_ptr_table not defined

--- ghc-6.4.2/ghc/includes/Stable.h.orig	2004-08-13 22:09:30.000000000 +0900
+++ ../ghc-6.4.2/ghc/includes/Stable.h	2019-10-06 22:08:49.397808935 +0900
@@ -36,7 +36,7 @@ typedef struct { 
   StgClosure *sn_obj;		/* the StableName object (or NULL) */
 } snEntry;
 
-extern DLL_IMPORT_RTS snEntry *stable_ptr_table;
+       DLL_IMPORT_RTS snEntry *stable_ptr_table;
 
 extern void freeStablePtr(StgStablePtr sp);
 
