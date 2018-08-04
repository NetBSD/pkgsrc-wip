$NetBSD$

--- hfuzz_cc/hfuzz-cc.c.orig	2018-04-19 13:37:38.000000000 +0000
+++ hfuzz_cc/hfuzz-cc.c
@@ -102,6 +102,13 @@ static bool isLDMode(int argc, char** ar
     return true;
 }
 
+static int
+hf_execvp(const char *file, char *argv[])
+{
+	argv[0] = (char *)file;
+	return execvp(file, argv);
+}
+
 static int execCC(int argc, char** argv) {
     if (useASAN()) {
         argv[argc++] = "-fsanitize=address";
@@ -117,14 +124,14 @@ static int execCC(int argc, char** argv)
     if (isCXX) {
         const char* cxx_path = getenv("HFUZZ_CXX_PATH");
         if (cxx_path != NULL) {
-            execvp(cxx_path, argv);
+            hf_execvp(cxx_path, argv);
             PLOG_E("execvp('%s')", cxx_path);
             return EXIT_FAILURE;
         }
     } else {
         const char* cc_path = getenv("HFUZZ_CC_PATH");
         if (cc_path != NULL) {
-            execvp(cc_path, argv);
+            hf_execvp(cc_path, argv);
             PLOG_E("execvp('%s')", cc_path);
             return EXIT_FAILURE;
         }
@@ -132,37 +139,37 @@ static int execCC(int argc, char** argv)
 
     if (isGCC) {
         if (isCXX) {
-            execvp("g++", argv);
-            execvp("gcc", argv);
+            hf_execvp("g++", argv);
+            hf_execvp("gcc", argv);
         } else {
-            execvp("gcc", argv);
+            hf_execvp("gcc", argv);
         }
     } else {
         if (isCXX) {
             /* Try the default one, then newest ones (hopefully) first */
-            execvp("clang++", argv);
-            execvp("clang++-devel", argv);
-            execvp("clang++-10.0", argv);
-            execvp("clang++-9.0", argv);
-            execvp("clang++-8.0", argv);
-            execvp("clang++-7.0", argv);
-            execvp("clang++-7", argv);
-            execvp("clang++-6.0", argv);
-            execvp("clang++-5.0", argv);
-            execvp("clang++-4.0", argv);
-            execvp("clang", argv);
+            hf_execvp("clang++", argv);
+            hf_execvp("clang++-devel", argv);
+            hf_execvp("clang++-10.0", argv);
+            hf_execvp("clang++-9.0", argv);
+            hf_execvp("clang++-8.0", argv);
+            hf_execvp("clang++-7.0", argv);
+            hf_execvp("clang++-7", argv);
+            hf_execvp("clang++-6.0", argv);
+            hf_execvp("clang++-5.0", argv);
+            hf_execvp("clang++-4.0", argv);
+            hf_execvp("clang", argv);
         } else {
             /* Try the default one, then newest ones (hopefully) first */
-            execvp("clang", argv);
-            execvp("clang-devel", argv);
-            execvp("clang-10.0", argv);
-            execvp("clang-9.0", argv);
-            execvp("clang-8.0", argv);
-            execvp("clang-7.0", argv);
-            execvp("clang-7", argv);
-            execvp("clang-6.0", argv);
-            execvp("clang-5.0", argv);
-            execvp("clang-4.0", argv);
+            hf_execvp("clang", argv);
+            hf_execvp("clang-devel", argv);
+            hf_execvp("clang-10.0", argv);
+            hf_execvp("clang-9.0", argv);
+            hf_execvp("clang-8.0", argv);
+            hf_execvp("clang-7.0", argv);
+            hf_execvp("clang-7", argv);
+            hf_execvp("clang-6.0", argv);
+            hf_execvp("clang-5.0", argv);
+            hf_execvp("clang-4.0", argv);
         }
     }
 
