$NetBSD$

--- src/ToolBox/SOS/Strike/stressLogDump.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/stressLogDump.cpp
@@ -255,7 +255,7 @@ void formatOutput(struct IDebugDataSpace
                 // need to _alloca, instead of declaring a local buffer
                 // since we may have more than one %s in the format
                 ULONG cbStrBuf = 256;
-                char* strBuf = (char *)_alloca(cbStrBuf);
+                char* strBuf = (char *)alloca(cbStrBuf);
                 
                 hr = memCallBack->ReadVirtual(TO_CDADDR((char* )args[iArgCount]), strBuf, cbStrBuf, 0);
                 if (hr != S_OK) 
@@ -272,7 +272,7 @@ void formatOutput(struct IDebugDataSpace
                 // need to _alloca, instead of declaring a local buffer
                 // since we may have more than one %s in the format
                 ULONG cbWstrBuf = 256 * sizeof(WCHAR);
-                WCHAR* wstrBuf = (WCHAR *)_alloca(cbWstrBuf);
+                WCHAR* wstrBuf = (WCHAR *)alloca(cbWstrBuf);
                 
                 hr = memCallBack->ReadVirtual(TO_CDADDR((char* )args[iArgCount]), wstrBuf, cbWstrBuf, 0);
                 if (hr != S_OK)
