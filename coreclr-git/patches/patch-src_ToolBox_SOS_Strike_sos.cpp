$NetBSD$

--- src/ToolBox/SOS/Strike/sos.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/sos.cpp
@@ -729,7 +729,7 @@ namespace sos
             if (!ClrSafeInt<DWORD>::multiply(sizeof(CLRDATA_ADDRESS), mNumHeaps, dwAllocSize))
                 sos::Throw<Exception>("Failed to get GCHeaps: Integer overflow.");
 
-            CLRDATA_ADDRESS *heapAddrs = (CLRDATA_ADDRESS*)alloca(dwAllocSize);
+            CLRDATA_ADDRESS *heapAddrs = (CLRDATA_ADDRESS*)Alloca(dwAllocSize);
             if (FAILED(g_sos->GetGCHeapList(mNumHeaps, heapAddrs, NULL)))
                 sos::Throw<DataRead>("Failed to get GCHeaps.");
 
