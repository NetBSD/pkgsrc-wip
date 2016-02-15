$NetBSD$

--- src/ToolBox/SOS/Strike/util.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/util.h
@@ -683,7 +683,7 @@ namespace Output
             if (IsDMLEnabled() && mDml != Output::DML_None)
             {
                 const int len = GetDMLWidth(mDml);
-                char *buffer = (char*)alloca(len);
+                char *buffer = (char*)Alloca(len);
             
                 BuildDML(buffer, len, (CLRDATA_ADDRESS)mValue, mFormat, mDml);
                 DMLOut(buffer);
@@ -732,7 +732,7 @@ namespace Output
             if (IsDMLEnabled() && mDml != Output::DML_None)
             {
                 const int len = GetDMLColWidth(mDml, width);
-                char *buffer = (char*)alloca(len);
+                char *buffer = (char*)Alloca(len);
             
                 BuildDMLCol(buffer, len, (CLRDATA_ADDRESS)mValue, mFormat, mDml, leftAlign, width);
                 DMLOut(buffer);
@@ -782,7 +782,7 @@ namespace Output
             const char *cstr = (const char *)str;
         
             int len = MultiByteToWideChar(CP_ACP, 0, cstr, -1, NULL, 0);
-            WCHAR *buffer = (WCHAR *)alloca(len*sizeof(WCHAR));
+            WCHAR *buffer = (WCHAR *)Alloca(len*sizeof(WCHAR));
         
             MultiByteToWideChar(CP_ACP, 0, cstr, -1, buffer, len);
         
@@ -798,7 +798,7 @@ namespace Output
             if (IsDMLEnabled() && mDml != Output::DML_None)
             {
                 const int len = GetDMLColWidth(mDml, 0);
-                char *buffer = (char*)alloca(len);
+                char *buffer = (char*)Alloca(len);
             
                 BuildDMLCol(buffer, len, (CLRDATA_ADDRESS)mValue, mFormat, mDml, false, 0);
                 return buffer;
