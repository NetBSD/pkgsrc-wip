$NetBSD$

--- vm/src/unix/os/itimer_unix.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/unix/os/itimer_unix.cpp
@@ -37,7 +37,7 @@ class TimerEntry: public AbstractTimerEn
 };
 
 
-#if TARGET_OS_VERSION != SOLARIS_VERSION && TARGET_OS_VERSION != MACOSX_VERSION && TARGET_OS_VERSION != LINUX_VERSION
+#if TARGET_OS_VERSION != SOLARIS_VERSION && TARGET_OS_VERSION != MACOSX_VERSION && TARGET_OS_VERSION != LINUX_VERSION && TARGET_OS_VERSION != NETBSD_VERSION
 extern "C" int setitimer(int which,
                          struct itimerval *value,
                          struct itimerval *ovalue);
@@ -93,7 +93,8 @@ void IntervalTimer::enable() {
   struct sigaction action;
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
   ||  TARGET_OS_VERSION ==  MACOSX_VERSION \
-  ||  TARGET_OS_VERSION ==   LINUX_VERSION
+  ||  TARGET_OS_VERSION ==   LINUX_VERSION \
+  ||  TARGET_OS_VERSION ==  NETBSD_VERSION
   action.sa_sigaction = (void (*)(int, siginfo_t*, void*)) IntervalTimerTick;
   
 # elif COMPILER != GCC_COMPILER  &&  TARGET_OS_VERSION == SUNOS_VERSION
@@ -264,4 +265,3 @@ void IntervalTimer::do_async_tasks() {
 }
 
 TimerEntry* IntervalTimer::entry_at(int i) { return &entries()[i]; }
-
