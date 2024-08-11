$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2024-07-24 02:44:30.736209900 +0000
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -58,7 +58,7 @@ void GetApplicationDirs(std::vector<base
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   // TODO: Respect users' PATH variables.
   // Until then, we use an approximation of the most common defaults.
@@ -125,7 +125,7 @@ std::vector<base::FilePath> GetChromePro
             chrome::kGoogleChromeForTestingBrowserProcessExecutablePath),
         base::FilePath(chrome::kGoogleChromeBrowserProcessExecutablePath),
         base::FilePath(chrome::kChromiumBrowserProcessExecutablePath),
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::FilePath(chrome::kBrowserProcessExecutablePath),
         base::FilePath("chrome"),  // Chrome for Testing or Google Chrome
         base::FilePath("google-chrome"), base::FilePath("chromium"),
@@ -141,7 +141,7 @@ std::vector<base::FilePath> GetHeadlessS
   return {
 #if BUILDFLAG(IS_WIN)
     base::FilePath(FILE_PATH_LITERAL("chrome-headless-shell.exe")),
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::FilePath("chrome-headless-shell"),
 #else
     // it will compile but won't work on other OSes
