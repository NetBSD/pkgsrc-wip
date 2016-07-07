$NetBSD$

--- src/VBox/Frontends/VirtualBox/src/net/UIUpdateManager.cpp.orig	2016-03-04 19:29:10.000000000 +0000
+++ src/VBox/Frontends/VirtualBox/src/net/UIUpdateManager.cpp
@@ -249,6 +249,8 @@ private:
         strPlatform = "os2";
 #elif defined (Q_OS_FREEBSD)
         strPlatform = "freebsd";
+#elif defined (Q_OS_NETBSD)
+        strPlatform = "netbsd";
 #elif defined (Q_OS_SOLARIS)
         strPlatform = "solaris";
 #else
@@ -514,4 +516,3 @@ void UIUpdateManager::sltHandleUpdateFin
 }
 
 #include "UIUpdateManager.moc"
-
