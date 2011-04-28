$NetBSD: patch-chrome_common_chrome__constants.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/chrome_constants.cc.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/chrome_constants.cc
@@ -27,7 +27,7 @@ const char kChromeVersionEnvVar[] = "CHR
 #if defined(OS_WIN)
 const FilePath::CharType kBrowserProcessExecutableName[] = FPL("chrome.exe");
 const FilePath::CharType kHelperProcessExecutableName[] = FPL("chrome.exe");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const FilePath::CharType kBrowserProcessExecutableName[] = FPL("chrome");
 // Helper processes end up with a name of "exe" due to execing via
 // /proc/self/exe.  See bug 22703.
@@ -40,7 +40,7 @@ const FilePath::CharType kHelperProcessE
 #if defined(OS_WIN)
 const FilePath::CharType kBrowserProcessExecutablePath[] = FPL("chrome.exe");
 const FilePath::CharType kHelperProcessExecutablePath[] = FPL("chrome.exe");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const FilePath::CharType kBrowserProcessExecutablePath[] = FPL("chrome");
 const FilePath::CharType kHelperProcessExecutablePath[] = FPL("chrome");
 #elif defined(OS_MACOSX)
