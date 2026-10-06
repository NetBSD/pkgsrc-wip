$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/DllSecur.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/DllSecur.c
@@ -1,114 +1,99 @@
 /* DllSecur.c -- DLL loading security
-2022-07-15 : Igor Pavlov : Public domain */
+2023-12-03 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
 #ifdef _WIN32
 
-#include <Windows.h>
+#include "7zWindows.h"
 
 #include "DllSecur.h"
 
 #ifndef UNDER_CE
 
-#if defined(__GNUC__) && (__GNUC__ >= 8)
-  #pragma GCC diagnostic ignored "-Wcast-function-type"
-#endif
+Z7_DIAGNOSTIC_IGNORE_CAST_FUNCTION
 
 typedef BOOL (WINAPI *Func_SetDefaultDllDirectories)(DWORD DirectoryFlags);
 
 #define MY_LOAD_LIBRARY_SEARCH_USER_DIRS 0x400
 #define MY_LOAD_LIBRARY_SEARCH_SYSTEM32  0x800
 
+#define DELIM "\0"
+
 static const char * const g_Dlls =
+         "userenv"
+  DELIM  "setupapi"
+  DELIM  "apphelp"
+  DELIM  "propsys"
+  DELIM  "dwmapi"
+  DELIM  "cryptbase"
+  DELIM  "oleacc"
+  DELIM  "clbcatq"
+  DELIM  "version"
   #ifndef _CONSOLE
-  "UXTHEME\0"
+  DELIM  "uxtheme"
   #endif
-  "USERENV\0"
-  "SETUPAPI\0"
-  "APPHELP\0"
-  "PROPSYS\0"
-  "DWMAPI\0"
-  "CRYPTBASE\0"
-  "OLEACC\0"
-  "CLBCATQ\0"
-  "VERSION\0"
-  ;
+  DELIM;
+
+#endif
 
+#ifdef __clang__
+  #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
+#endif
+#if defined (_MSC_VER) && _MSC_VER >= 1900
+// sysinfoapi.h: kit10: GetVersion was declared deprecated
+#pragma warning(disable : 4996)
 #endif
 
-// #define MY_CAST_FUNC  (void(*)())
-#define MY_CAST_FUNC
+#define IF_NON_VISTA_SET_DLL_DIRS_AND_RETURN \
+    if ((UInt16)GetVersion() != 6) { \
+      const \
+       Func_SetDefaultDllDirectories setDllDirs = \
+      (Func_SetDefaultDllDirectories) Z7_CAST_FUNC_C GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), \
+           "SetDefaultDllDirectories"); \
+      if (setDllDirs) if (setDllDirs(MY_LOAD_LIBRARY_SEARCH_SYSTEM32 | MY_LOAD_LIBRARY_SEARCH_USER_DIRS)) return; }
 
-void My_SetDefaultDllDirectories()
+void My_SetDefaultDllDirectories(void)
 {
   #ifndef UNDER_CE
-  
-    OSVERSIONINFO vi;
-    vi.dwOSVersionInfoSize = sizeof(vi);
-    if (!GetVersionEx(&vi) || vi.dwMajorVersion != 6 || vi.dwMinorVersion != 0)
-    {
-      Func_SetDefaultDllDirectories setDllDirs = (Func_SetDefaultDllDirectories)
-          MY_CAST_FUNC GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "SetDefaultDllDirectories");
-      if (setDllDirs)
-        if (setDllDirs(MY_LOAD_LIBRARY_SEARCH_SYSTEM32 | MY_LOAD_LIBRARY_SEARCH_USER_DIRS))
-          return;
-    }
-
+  IF_NON_VISTA_SET_DLL_DIRS_AND_RETURN
   #endif
 }
 
 
-void LoadSecurityDlls()
+void LoadSecurityDlls(void)
 {
   #ifndef UNDER_CE
-  
-  wchar_t buf[MAX_PATH + 100];
-
-  {
-    // at Vista (ver 6.0) : CoCreateInstance(CLSID_ShellLink, ...) doesn't work after SetDefaultDllDirectories() : Check it ???
-    OSVERSIONINFO vi;
-    vi.dwOSVersionInfoSize = sizeof(vi);
-    if (!GetVersionEx(&vi) || vi.dwMajorVersion != 6 || vi.dwMinorVersion != 0)
-    {
-      Func_SetDefaultDllDirectories setDllDirs = (Func_SetDefaultDllDirectories)
-          MY_CAST_FUNC GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "SetDefaultDllDirectories");
-      if (setDllDirs)
-        if (setDllDirs(MY_LOAD_LIBRARY_SEARCH_SYSTEM32 | MY_LOAD_LIBRARY_SEARCH_USER_DIRS))
-          return;
-    }
-  }
-
-  {
-    unsigned len = GetSystemDirectoryW(buf, MAX_PATH + 2);
-    if (len == 0 || len > MAX_PATH)
-      return;
-  }
+  // at Vista (ver 6.0) : CoCreateInstance(CLSID_ShellLink, ...) doesn't work after SetDefaultDllDirectories() : Check it ???
+  IF_NON_VISTA_SET_DLL_DIRS_AND_RETURN
   {
+    wchar_t buf[MAX_PATH + 100];
     const char *dll;
-    unsigned pos = (unsigned)lstrlenW(buf);
-
+    unsigned pos = GetSystemDirectoryW(buf, MAX_PATH + 2);
+    if (pos == 0 || pos > MAX_PATH)
+      return;
     if (buf[pos - 1] != '\\')
       buf[pos++] = '\\';
-    
-    for (dll = g_Dlls; dll[0] != 0;)
+    for (dll = g_Dlls; *dll != 0;)
     {
-      unsigned k = 0;
+      wchar_t *dest = &buf[pos];
       for (;;)
       {
-        char c = *dll++;
-        buf[pos + k] = (Byte)c;
-        k++;
+        const char c = *dll++;
         if (c == 0)
           break;
+        *dest++ = (Byte)c;
       }
-
-      lstrcatW(buf, L".dll");
+      dest[0] = '.';
+      dest[1] = 'd';
+      dest[2] = 'l';
+      dest[3] = 'l';
+      dest[4] = 0;
+      // lstrcatW(buf, L".dll");
       LoadLibraryExW(buf, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
     }
   }
-  
   #endif
 }
 
-#endif
+#endif // _WIN32
