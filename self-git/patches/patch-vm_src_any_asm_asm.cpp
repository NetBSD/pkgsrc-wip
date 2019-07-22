$NetBSD$

--- vm/src/any/asm/asm.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/asm/asm.cpp
@@ -181,7 +181,7 @@ void BaseAssembler::self_test() {
 
 
 static const char *underscoreOrNot =
-  TARGET_OS_VERSION == LINUX_VERSION  ?  ""  :  "_";
+  (TARGET_OS_VERSION == LINUX_VERSION || TARGET_OS_VERSION == NETBSD_VERSION)  ?  ""  :  "_";
 
 void BaseAssembler::prepare_to_test() {
   lprintf_file = fopen(test_file_s, "w");
@@ -203,7 +203,7 @@ void BaseAssembler::assemble_test_file()
   char buf[1000];
   sprintf(buf, "cc -c %s; cc %s -c %s; cc %s %s; ./a.out>%s", 
     test_file_c,
-    # if TARGET_OS_VERSION == LINUX_VERSION
+    # if TARGET_OS_VERSION == LINUX_VERSION || TARGET_OS_VERSION == NETBSD_VERSION
 	"",
     # else
 	"-arch i386",
@@ -255,4 +255,3 @@ void BaseAssembler::generate_test_instru
 
 
 # endif // defined(FAST_COMPILER) || defined(SIC_COMPILER)
-
