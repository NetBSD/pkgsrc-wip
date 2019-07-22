$NetBSD$

--- vm/src/any/runtime/allocation.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/runtime/allocation.cpp
@@ -312,7 +312,7 @@ static int32 true_size_of_malloced_obj(i
       -2;
 #   elif  TARGET_ARCH == I386_ARCH   &&  COMPILER == GCC_COMPILER   &&   TARGET_OS_VERSION == MACOSX_VERSION
       -2;
-#   elif  TARGET_ARCH == I386_ARCH   &&  COMPILER == GCC_COMPILER   &&    (TARGET_OS_VERSION ==  LINUX_VERSION  ||  TARGET_OS_VERSION == SOLARIS_VERSION)
+#   elif  TARGET_ARCH == I386_ARCH   &&  COMPILER == GCC_COMPILER   &&    (TARGET_OS_VERSION ==  LINUX_VERSION  ||  TARGET_OS_VERSION == SOLARIS_VERSION || TARGET_OS_VERSION == NETBSD_VERSION)
       -1;
 #   else
 	# error What is it?
