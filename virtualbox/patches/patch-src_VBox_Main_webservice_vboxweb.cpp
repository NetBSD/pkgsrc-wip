$NetBSD$

--- src/VBox/Main/webservice/vboxweb.cpp.orig	2016-03-04 19:29:42.000000000 +0000
+++ src/VBox/Main/webservice/vboxweb.cpp
@@ -189,7 +189,7 @@ static ThreadsMap               g_mapThr
 static const RTGETOPTDEF g_aOptions[]
     = {
         { "--help",             'h', RTGETOPT_REQ_NOTHING }, /* for DisplayHelp() */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         { "--background",       'b', RTGETOPT_REQ_NOTHING },
 #endif
         { "--host",             'H', RTGETOPT_REQ_STRING },
@@ -236,7 +236,7 @@ static void DisplayHelp()
                 pcszDescr = "Print this help message and exit.";
                 break;
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             case 'b':
                 pcszDescr = "Run in background (daemon mode).";
                 break;
@@ -1161,7 +1161,7 @@ int main(int argc, char *argv[])
                 g_fVerbose = true;
                 break;
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             case 'b':
                 g_fDaemonize = true;
                 break;
@@ -1187,7 +1187,7 @@ int main(int argc, char *argv[])
     if (RT_FAILURE(rc))
         return RTMsgErrorExit(RTEXITCODE_FAILURE, "failed to open release log (%s, %Rrc)", szError, rc);
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_LINUX) || defined (RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     if (g_fDaemonize)
     {
         /* prepare release logging */
