$NetBSD: patch-xbmc_addons_AddonManager.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/addons/AddonManager.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/addons/AddonManager.cpp
@@ -1009,7 +1009,7 @@ std::string CAddonMgr::GetPlatformLibrar
   std::string libraryName;
 #if defined(TARGET_ANDROID)
   libraryName = GetExtValue(base, "@library_android");
-#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD)
+#elif defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #if defined(TARGET_FREEBSD)
   libraryName = GetExtValue(base, "@library_freebsd");
   if (libraryName.empty())
