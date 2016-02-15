$NetBSD$

--- src/ToolBox/SOS/Strike/gcroot.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/gcroot.cpp
@@ -544,7 +544,7 @@ int GCRootImpl::PrintRootsInOlderGen()
             return 0;
         }
 
-        CLRDATA_ADDRESS *heapAddrs = (CLRDATA_ADDRESS*)alloca(dwAllocSize);
+        CLRDATA_ADDRESS *heapAddrs = (CLRDATA_ADDRESS*)Alloca(dwAllocSize);
         if (g_sos->GetGCHeapList(dwNHeaps, heapAddrs, NULL) != S_OK)
         {
             ExtErr("Failed to get GCHeaps\n");
@@ -625,7 +625,7 @@ int GCRootImpl::PrintRootsOnFQ(bool notR
             return 0;
         }
 
-        CLRDATA_ADDRESS *heapAddrs = (CLRDATA_ADDRESS*)alloca(dwAllocSize);
+        CLRDATA_ADDRESS *heapAddrs = (CLRDATA_ADDRESS*)Alloca(dwAllocSize);
         if (g_sos->GetGCHeapList(dwNHeaps, heapAddrs, NULL) != S_OK)
         {
             ExtErr("Error requesting heap data.\n");
