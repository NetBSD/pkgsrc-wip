$NetBSD$

--- src/vm/ceeload.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/ceeload.cpp
@@ -5203,7 +5203,7 @@ OBJECTHANDLE Module::ResolveStringRef(DW
         #ifdef LOGGING 
         int length = strData.GetCharCount();
         length = min(length, 100);
-        WCHAR *szString = (WCHAR *)_alloca((length + 1) * sizeof(WCHAR));
+        WCHAR *szString = (WCHAR *)Alloca((length + 1) * sizeof(WCHAR));
         memcpyNoGCRefs((void*)szString, (void*)strData.GetStringBuffer(), length * sizeof(WCHAR));
         szString[length] = '\0';
         LOG((LF_APPDOMAIN, LL_INFO10000, "String literal \"%S\" won't be interned due to NoInterningAttribute\n", szString));
@@ -9057,7 +9057,7 @@ MethodDesc* Module::LoadIBCMethodHelper(
             if (!ClrSafeInt<SIZE_T>::multiply(nargs, sizeof(TypeHandle), cbMem/* passed by ref */))
                 ThrowHR(COR_E_OVERFLOW);
             
-            TypeHandle * pInst = (TypeHandle*) _alloca(cbMem);
+            TypeHandle * pInst = (TypeHandle*) Alloca(cbMem);
             SigTypeContext typeContext;   // empty type context
 
             for (DWORD i = 0; i < nargs; i++)
