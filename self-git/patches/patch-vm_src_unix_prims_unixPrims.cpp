$NetBSD$

--- vm/src/unix/prims/unixPrims.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/unix/prims/unixPrims.cpp
@@ -5,6 +5,7 @@
 
 # if !( TARGET_OS_VERSION ==  MACOSX_VERSION \
   ||    TARGET_OS_VERSION ==   LINUX_VERSION \
+  ||    TARGET_OS_VERSION ==  NETBSD_VERSION \
   || (  TARGET_OS_VERSION == SOLARIS_VERSION  && TARGET_ARCH == I386_ARCH))
   # define FD_SETSIZE     256             /* max. number of open files */
 # endif
@@ -73,7 +74,8 @@ class IOCleanup {
   || TARGET_OS_VERSION ==   LINUX_VERSION
     if (isatty(STDIN))
       ioctl(STDIN, TCGETS, (caddr_t)&normalSettings);
-# elif TARGET_OS_VERSION == MACOSX_VERSION
+# elif TARGET_OS_VERSION == MACOSX_VERSION \
+  || TARGET_OS_VERSION ==  NETBSD_VERSION
     // not sure what to do
     if (isatty(STDIN))
       ioctl(STDIN, TIOCGETA, (caddr_t)&normalSettings);
@@ -92,7 +94,8 @@ void resetTerminal() {
   ||  TARGET_OS_VERSION ==   LINUX_VERSION
     if (isatty(STDIN))
       ioctl(STDIN, TCSETS, (caddr_t)&normalSettings);
-# elif TARGET_OS_VERSION == MACOSX_VERSION
+# elif TARGET_OS_VERSION == MACOSX_VERSION \
+  ||  TARGET_OS_VERSION ==   NETBSD_VERSION
     if (isatty(STDIN))
       ioctl(STDIN, TIOCSETA, (caddr_t)&normalSettings);
 # else
@@ -162,7 +165,7 @@ void resetTerminal() {
     }
   # endif  
 
-# elif  TARGET_OS_VERSION == LINUX_VERSION
+# elif  TARGET_OS_VERSION == LINUX_VERSION || TARGET_OS_VERSION == NETBSD_VERSION
     static int c_lib_write(int fd, const char* buf, int nbytes) {
       return write(fd, buf, nbytes);
     }    
@@ -170,7 +173,7 @@ void resetTerminal() {
   # error what?
 # endif
 
- # if TARGET_OS_VERSION != MACOSX_VERSION  &&  TARGET_OS_VERSION != LINUX_VERSION
+ # if TARGET_OS_VERSION != MACOSX_VERSION  &&  TARGET_OS_VERSION != LINUX_VERSION && TARGET_OS_VERSION != NETBSD_VERSION
 
 extern "C" int write(int fd, const void* b, nbytes_t nbytes) {
     int32 res;
@@ -251,7 +254,8 @@ static void set_sockaddr_in(struct socka
   long aLong;
 #   if  TARGET_OS_VERSION == SOLARIS_VERSION  \
     ||  TARGET_OS_VERSION == MACOSX_VERSION   \
-    ||  TARGET_OS_VERSION == LINUX_VERSION
+    ||  TARGET_OS_VERSION == LINUX_VERSION \
+    ||  TARGET_OS_VERSION == NETBSD_VERSION
     memcpy((char*) &aLong, address, sizeof(long));
     memset(a.sin_zero, 0, sizeof(a.sin_zero));
 # elif  TARGET_OS_VERSION == SUNOS_VERSION
@@ -588,7 +592,8 @@ void unixPrims_init() { ioC = new IOClea
 void unixPrims_exit() { delete ioC; }
 
 # if TARGET_OS_VERSION == MACOSX_VERSION \
-  || TARGET_OS_VERSION ==  LINUX_VERSION
+  || TARGET_OS_VERSION ==  LINUX_VERSION \
+  || TARGET_OS_VERSION ==  NETBSD_VERSION
   static struct utsname my_utsname;
   char*  sysname_wrap(void* FH) { return uname(&my_utsname) ? (unix_failure(FH), (char*)NULL) : my_utsname. sysname; }
   char* nodename_wrap(void* FH) { return uname(&my_utsname) ? (unix_failure(FH), (char*)NULL) : my_utsname.nodename; }
