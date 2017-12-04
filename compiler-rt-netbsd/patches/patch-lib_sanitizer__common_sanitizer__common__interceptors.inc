$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-11-20 18:08:35.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -69,6 +69,46 @@
 #define iconv __bsd_iconv
 #endif
 
+#if SANITIZER_NETBSD
+#define clock_getres __clock_getres50
+#define clock_gettime __clock_gettime50
+#define clock_settime __clock_settime50
+#define ctime __ctime50
+#define ctime_r __ctime_r50
+#define getitimer __getitimer50
+#define getpwent __getpwent50
+#define getpwnam __getpwnam50
+#define getpwnam_r __getpwnam_r50
+#define getpwuid __getpwuid50
+#define getpwuid_r __getpwuid_r50
+#define getutent __getutent50
+#define getutxent __getutxent50
+#define getutxid __getutxid50
+#define getutxline __getutxline50
+#define glob __glob30
+#define gmtime __gmtime50
+#define gmtime_r __gmtime_r50
+#define localtime_r __localtime_r50
+#define mktime __mktime50
+#define opendir __opendir30
+#define readdir __readdir30
+#define readdir_r __readdir_r30
+#define scandir __scandir30
+#define setitimer __setitimer50
+#define setlocale __setlocale50
+#define shmctl __shmctl50
+#define sigemptyset __sigemptyset14
+#define sigfillset __sigfillset14
+#define sigpending __sigpending14
+#define sigprocmask __sigprocmask14
+#define sigtimedwait __sigtimedwait50
+#define stat __stat50
+#define time __time50
+#define times __times13
+#define wait3 __wait350
+#define wait4 __wait450
+#endif
+
 // Platform-specific options.
 #if SANITIZER_MAC
 namespace __sanitizer {
