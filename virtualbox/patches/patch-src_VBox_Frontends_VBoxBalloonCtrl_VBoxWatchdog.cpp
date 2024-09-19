$NetBSD$

--- src/VBox/Frontends/VBoxBalloonCtrl/VBoxWatchdog.cpp.orig	2016-03-04 19:28:59.000000000 +0000
+++ src/VBox/Frontends/VBoxBalloonCtrl/VBoxWatchdog.cpp
@@ -112,7 +112,7 @@ enum GETOPTDEF_WATCHDOG
  * Command line arguments.
  */
 static const RTGETOPTDEF g_aOptions[] = {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     { "--background",           'b',                                       RTGETOPT_REQ_NOTHING },
 #endif
     /** For displayHelp(). */
@@ -854,7 +854,7 @@ static void displayHelp(const char *pszI
                 pcszDescr = "Print this help message and exit.";
                 break;
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             case 'b':
                 pcszDescr = "Run in background (daemon mode).";
                 break;
@@ -992,7 +992,7 @@ int main(int argc, char *argv[])
                 g_fVerbose = true;
                 break;
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             case 'b':
                 g_fDaemonize = true;
                 break;
@@ -1072,7 +1072,7 @@ int main(int argc, char *argv[])
     if (RT_FAILURE(rc))
         return RTMsgErrorExit(RTEXITCODE_FAILURE, "failed to open release log (%s, %Rrc)", szError, rc);
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     if (g_fDaemonize)
     {
         /* prepare release logging */
@@ -1160,4 +1160,3 @@ int main(int argc, char *argv[])
     return RTEXITCODE_SUCCESS;
 #endif /* VBOX_ONLY_DOCS */
 }
-
