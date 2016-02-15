$NetBSD$

--- src/vm/util.cpp.orig	2016-02-13 00:18:27.000000000 +0000
+++ src/vm/util.cpp
@@ -3913,7 +3913,7 @@ INT32 InternalCasingHelper::InvariantToL
     __lszInWide = WszMultiByteToWideChar(CP_UTF8, 0, szInSave, -1, 0, 0);
     if (__lszInWide > MAKE_MAX_LENGTH)
          RaiseException(EXCEPTION_INT_OVERFLOW, EXCEPTION_NONCONTINUABLE, 0, 0);
-    szInWide = (LPWSTR) alloca(__lszInWide*sizeof(WCHAR));
+    szInWide = (LPWSTR) Alloca(__lszInWide*sizeof(WCHAR));
     if (szInWide == NULL) {
         if (fAllowThrow) {
             COMPlusThrowOM();
@@ -4066,8 +4066,8 @@ HRESULT GetFileVersion(                 
     }
 
     // Allocate the buffer for the version info structure
-    // _alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
-    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(_alloca(bufSize));
+    // Alloca() can't return NULL -- raises STATUS_STACK_OVERFLOW.
+    BYTE* pVersionInfoBuffer = reinterpret_cast< BYTE* >(Alloca(bufSize));
 
     ret = GetFileVersionInfoW(wszFilePath, dwHandle, bufSize, pVersionInfoBuffer);
     if (!ret)
