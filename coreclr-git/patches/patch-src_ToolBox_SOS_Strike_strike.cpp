$NetBSD$

--- src/ToolBox/SOS/Strike/strike.cpp.orig	2016-02-10 22:49:42.000000000 +0000
+++ src/ToolBox/SOS/Strike/strike.cpp
@@ -12752,7 +12752,7 @@ DECLARE_API(SaveModule)
 
     int nSection = Header.FileHeader.NumberOfSections;
     ExtOut("%u sections in file\n",nSection);
-    MemLocation *memLoc = (MemLocation*)_alloca(nSection*sizeof(MemLocation));
+    MemLocation *memLoc = (MemLocation*)alloca(nSection*sizeof(MemLocation));
     int indxSec = -1;
     int slot;
     for (int n = 0; n < nSection; n++)
@@ -12805,7 +12805,7 @@ DECLARE_API(SaveModule)
     }
 
     ULONG pageSize = OSPageSize();
-    char *buffer = (char *)_alloca(pageSize);
+    char *buffer = (char *)alloca(pageSize);
     DWORD nRead;
     DWORD nWrite;
     
