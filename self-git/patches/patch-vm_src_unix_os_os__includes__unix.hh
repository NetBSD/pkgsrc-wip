$NetBSD$

--- vm/src/unix/os/os_includes_unix.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/unix/os/os_includes_unix.hh
@@ -41,7 +41,7 @@ extern "C" { 
 }
 
 # include <stdlib.h>
-#if TARGET_OS_VERSION != MACOSX_VERSION
+#if TARGET_OS_VERSION != MACOSX_VERSION && TARGET_OS_VERSION != NETBSD_VERSION
 # include <alloca.h>
 #endif
 
@@ -78,6 +78,12 @@ extern "C" { 
 #   include <termios.h>
 #   include <sys/ioctl.h>
 #   include <pthread.h>
+# elif TARGET_OS_VERSION == NETBSD_VERSION
+#   include <sys/types.h>
+#   include <sys/ioctl.h>
+#   include <sys/sysctl.h>
+#   include <termios.h>
+#   include <pthread.h>
 # else
 #   include <termio.h>
 # endif
@@ -103,7 +109,8 @@ extern "C" { 
   typedef sigcontext       self_sig_context_t;
   typedef struct sigstack  self_stack_t;
 # elif TARGET_OS_VERSION == MACOSX_VERSION \
-    || TARGET_OS_VERSION ==  LINUX_VERSION
+    || TARGET_OS_VERSION ==  LINUX_VERSION \
+    || TARGET_OS_VERSION ==  NETBSD_VERSION
   typedef siginfo_t        self_code_info_t;
   typedef ucontext_t       self_sig_context_t;
   typedef stack_t          self_stack_t;
@@ -164,7 +171,8 @@ extern "C" {
 
 
 # if TARGET_OS_VERSION != SOLARIS_VERSION  \
-  && TARGET_OS_VERSION != LINUX_VERSION
+  && TARGET_OS_VERSION != LINUX_VERSION \
+  && TARGET_OS_VERSION != NETBSD_VERSION
   #  include <sys/vadvise.h>
    extern "C" {
      int vadvise(int);
@@ -205,6 +213,8 @@ extern "C" {
 # define FORK vfork
 # elif  TARGET_OS_VERSION == LINUX_VERSION
 # define FORK vfork
+# elif  TARGET_OS_VERSION == NETBSD_VERSION
+# define FORK vfork
 # else
    error which?
 #endif
@@ -228,7 +238,8 @@ const int Last_OS_Signal = SIGUSR2+1+20;
 
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
   ||  TARGET_OS_VERSION ==  MACOSX_VERSION \
-  ||  TARGET_OS_VERSION ==   LINUX_VERSION
+  ||  TARGET_OS_VERSION ==   LINUX_VERSION \
+  ||  TARGET_OS_VERSION ==  NETBSD_VERSION
 
   typedef void (*Signal_Handler_t)(int sig, self_code_info_t *info, self_sig_context_t *con);
 
@@ -247,4 +258,4 @@ extern "C" { int malloc_verify(); }
 
 # if TARGET_OS_VERSION == MACOSX_VERSION
   typedef size_t nbytes_t;
-# endif
\ No newline at end of file
+# endif
