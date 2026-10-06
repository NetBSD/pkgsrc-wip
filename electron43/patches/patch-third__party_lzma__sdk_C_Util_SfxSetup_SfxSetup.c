$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Util/SfxSetup/SfxSetup.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Util/SfxSetup/SfxSetup.c
@@ -1,5 +1,5 @@
 /* SfxSetup.c - 7z SFX Setup
-2019-02-02 : Igor Pavlov : Public domain */
+2024-01-24 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -11,6 +11,7 @@
 #define _UNICODE
 #endif
 
+// SHELLEXECUTEINFO
 #include <windows.h>
 #include <shellapi.h>
 
@@ -18,17 +19,23 @@
 #include <stdio.h>
 #endif
 
-#include "7z.h"
-#include "7zAlloc.h"
-#include "7zCrc.h"
-#include "7zFile.h"
-#include "CpuArch.h"
-#include "DllSecur.h"
+#include "../../7z.h"
+#include "../../7zAlloc.h"
+#include "../../7zCrc.h"
+#include "../../7zFile.h"
+#include "../../CpuArch.h"
+#include "../../DllSecur.h"
 
 #define k_EXE_ExtIndex 2
 
 #define kInputBufSize ((size_t)1 << 18)
 
+
+#define wcscat lstrcatW
+#define wcslen (size_t)lstrlenW
+#define wcscpy lstrcpyW
+// wcsncpy() and lstrcpynW() work differently. We don't use them.
+
 static const char * const kExts[] =
 {
     "bat"
@@ -67,7 +74,7 @@ static unsigned FindExt(const wchar_t *s
   return len;
 }
 
-#define MAKE_CHAR_UPPER(c) ((((c) >= 'a' && (c) <= 'z') ? (c) -= 0x20 : (c)))
+#define MAKE_CHAR_UPPER(c) ((((c) >= 'a' && (c) <= 'z') ? (c) - 0x20 : (c)))
 
 static unsigned FindItem(const char * const *items, unsigned num, const wchar_t *s, unsigned len)
 {
@@ -75,13 +82,13 @@ static unsigned FindItem(const char * co
   for (i = 0; i < num; i++)
   {
     const char *item = items[i];
-    unsigned itemLen = (unsigned)strlen(item);
+    const unsigned itemLen = (unsigned)strlen(item);
     unsigned j;
     if (len != itemLen)
       continue;
     for (j = 0; j < len; j++)
     {
-      unsigned c = (Byte)item[j];
+      const unsigned c = (Byte)item[j];
       if (c != s[j] && MAKE_CHAR_UPPER(c) != s[j])
         break;
     }
@@ -99,10 +106,20 @@ static BOOL WINAPI HandlerRoutine(DWORD 
 }
 #endif
 
+
+#ifdef _CONSOLE
+static void PrintStr(const char *s)
+{
+  fputs(s, stdout);
+}
+#endif
+
 static void PrintErrorMessage(const char *message)
 {
   #ifdef _CONSOLE
-  printf("\n7-Zip Error: %s\n", message);
+  PrintStr("\n7-Zip Error: ");
+  PrintStr(message);
+  PrintStr("\n");
   #else
   #ifdef UNDER_CE
   WCHAR messageW[256 + 4];
@@ -182,7 +199,7 @@ static WRes RemoveDirWithSubItems(WCHAR 
   WIN32_FIND_DATAW fd;
   HANDLE handle;
   WRes res = 0;
-  size_t len = wcslen(path);
+  const size_t len = wcslen(path);
   wcscpy(path + len, L"*");
   handle = FindFirstFileW(path, &fd);
   path[len] = L'\0';
@@ -231,7 +248,7 @@ static WRes RemoveDirWithSubItems(WCHAR 
 }
 
 #ifdef _CONSOLE
-int MY_CDECL main()
+int Z7_CDECL main(void)
 #else
 int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
   #ifdef UNDER_CE
@@ -265,10 +282,10 @@ int APIENTRY WinMain(HINSTANCE hInstance
   #ifdef _CONSOLE
   SetConsoleCtrlHandler(HandlerRoutine, TRUE);
   #else
-  UNUSED_VAR(hInstance);
-  UNUSED_VAR(hPrevInstance);
-  UNUSED_VAR(lpCmdLine);
-  UNUSED_VAR(nCmdShow);
+  UNUSED_VAR(hInstance)
+  UNUSED_VAR(hPrevInstance)
+  UNUSED_VAR(lpCmdLine)
+  UNUSED_VAR(nCmdShow)
   #endif
 
   CrcGenerateTable();
@@ -293,7 +310,7 @@ int APIENTRY WinMain(HINSTANCE hInstance
       BoolInt quoteMode = False;
       for (;; cmdLineParams++)
       {
-        wchar_t c = *cmdLineParams;
+        const wchar_t c = *cmdLineParams;
         if (c == L'\"')
           quoteMode = !quoteMode;
         else if (c == 0 || (c == L' ' && !quoteMode))
@@ -327,7 +344,7 @@ int APIENTRY WinMain(HINSTANCE hInstance
         unsigned k;
         for (k = 0; k < 8; k++)
         {
-          unsigned t = value & 0xF;
+          const unsigned t = value & 0xF;
           value >>= 4;
           s[7 - k] = (wchar_t)((t < 10) ? ('0' + t) : ('A' + (t - 10)));
         }
@@ -389,7 +406,7 @@ int APIENTRY WinMain(HINSTANCE hInstance
     {
       lookStream.bufSize = kInputBufSize;
       lookStream.realStream = &archiveStream.vt;
-      LookToRead2_Init(&lookStream);
+      LookToRead2_INIT(&lookStream)
     }
   }
 
@@ -458,11 +475,11 @@ int APIENTRY WinMain(HINSTANCE hInstance
           unsigned extLen;
           const WCHAR *name = temp + nameStartPos;
           unsigned len = (unsigned)wcslen(name);
-          unsigned nameLen = FindExt(temp + nameStartPos, &extLen);
-          unsigned extPrice = FindItem(kExts, sizeof(kExts) / sizeof(kExts[0]), name + len - extLen, extLen);
-          unsigned namePrice = FindItem(kNames, sizeof(kNames) / sizeof(kNames[0]), name, nameLen);
+          const unsigned nameLen = FindExt(temp + nameStartPos, &extLen);
+          const unsigned extPrice = FindItem(kExts, sizeof(kExts) / sizeof(kExts[0]), name + len - extLen, extLen);
+          const unsigned namePrice = FindItem(kNames, sizeof(kNames) / sizeof(kNames[0]), name, nameLen);
 
-          unsigned price = namePrice + extPrice * 64 + (nameStartPos == 0 ? 0 : (1 << 12));
+          const unsigned price = namePrice + extPrice * 64 + (nameStartPos == 0 ? 0 : (1 << 12));
           if (minPrice > price)
           {
             minPrice = price;
@@ -503,12 +520,13 @@ int APIENTRY WinMain(HINSTANCE hInstance
         #endif
         
         {
-          SRes res2 = File_Close(&outFile);
+          const WRes res2 = File_Close(&outFile);
           if (res != SZ_OK)
             break;
-          if (res2 != SZ_OK)
+          if (res2 != 0)
           {
-            res = res2;
+            errorMessage = "Can't close output file";
+            res = SZ_ERROR_FAIL;
             break;
           }
         }
@@ -553,7 +571,7 @@ int APIENTRY WinMain(HINSTANCE hInstance
     WCHAR oldCurDir[MAX_PATH + 2];
     oldCurDir[0] = 0;
     {
-      DWORD needLen = GetCurrentDirectory(MAX_PATH + 1, oldCurDir);
+      const DWORD needLen = GetCurrentDirectory(MAX_PATH + 1, oldCurDir);
       if (needLen == 0 || needLen > MAX_PATH)
         oldCurDir[0] = 0;
       SetCurrentDirectory(workCurDir);
