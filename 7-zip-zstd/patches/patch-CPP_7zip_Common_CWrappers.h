$NetBSD$

Add missing macros used by Lzma2 code.

--- CPP/7zip/Common/CWrappers.h.orig	2023-06-18 13:11:43.000000000 +0000
+++ CPP/7zip/Common/CWrappers.h
@@ -6,6 +6,14 @@
 #include "../ICoder.h"
 #include "../../Common/MyCom.h"
 
+#ifndef max
+#define max(a, b) ((a) > (b) ? (a) : (b))
+#endif
+
+#ifndef min
+#define min(a, b) ((a) < (b) ? (a) : (b))
+#endif
+
 SRes HRESULT_To_SRes(HRESULT res, SRes defaultRes) throw();
 HRESULT SResToHRESULT(SRes res) throw();
 
