$NetBSD$

--- vm/src/unix/os/sig_unix.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/unix/os/sig_unix.cpp
@@ -13,7 +13,8 @@ int SignalInterface::currentTimerSignal 
 
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
   ||  TARGET_OS_VERSION ==  MACOSX_VERSION \
-  ||  TARGET_OS_VERSION ==   LINUX_VERSION
+  ||  TARGET_OS_VERSION ==   LINUX_VERSION \
+  ||  TARGET_OS_VERSION ==  NETBSD_VERSION
   static void signal_handler(int sig, self_code_info_t *info = NULL, self_sig_context_t *scp = NULL);
 # elif TARGET_OS_VERSION == SUNOS_VERSION
   static void signal_handler(int sig, int code = 0, self_sig_context_t *scp = NULL, char *addr = NULL);
@@ -209,7 +210,8 @@ static int32 ctrl_z_handler(int sig) {
 
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
   ||  TARGET_OS_VERSION ==  MACOSX_VERSION \
-  ||  TARGET_OS_VERSION ==   LINUX_VERSION
+  ||  TARGET_OS_VERSION ==   LINUX_VERSION \
+  ||  TARGET_OS_VERSION ==  NETBSD_VERSION
 static void signal_handler(int sig, self_code_info_t *info, self_sig_context_t *scp) {
   if (InterruptedContext::the_interrupted_context->forwarded_to_self_thread(sig))
     return;
@@ -255,7 +257,8 @@ static void signal_handler(int sig, self
 
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
   ||  TARGET_OS_VERSION == MACOSX_VERSION \
-  ||  TARGET_OS_VERSION ==  LINUX_VERSION
+  ||  TARGET_OS_VERSION ==  LINUX_VERSION \
+  ||  TARGET_OS_VERSION == NETBSD_VERSION
 
 void SignalInterface::init_signal_stack() {
   // ensure generic val is enough for ppc
