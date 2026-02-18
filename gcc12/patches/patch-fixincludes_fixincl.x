$NetBSD$

Fix build on Darwin for macOS 26.2.

Patch from https://github.com/markmentovai/gcc/commit/8708938
fixincludes, Darwin: Handle macOS 15 SDK
The macOS 15 SDK has declarations that use the _Float16 type in its
<math.h>, but GCC 12 doesn't support that type in C++ code, support
having been introduced in b042088 (in GCC 13). Add a fixincludes
hack to hide these declarations inside #ifndef __cplusplus guards.

--- fixincludes/fixincl.x.orig	2026-02-18 05:39:44.820015042 +0000
+++ fixincludes/fixincl.x
@@ -2796,6 +2796,46 @@ extern \"C\" {\n\
 #endif\n",
     (char*)NULL };
 
+
+/* * * * * * * * * * * * * * * * * * * * * * * * * *
+ *
+ *  Description of Darwin_Float16 fix
+ */
+tSCC zDarwin_Float16Name[] =
+     "darwin_float16";
+
+/*
+ *  File name selection pattern
+ */
+tSCC zDarwin_Float16List[] =
+  "math.h\0";
+/*
+ *  Machine/OS name selection pattern
+ */
+tSCC* apzDarwin_Float16Machs[] = {
+        "*-*-darwin*",
+        (const char*)NULL };
+
+/*
+ *  content selection pattern - do fix if pattern found
+ */
+tSCC zDarwin_Float16Select0[] =
+       "^.*(^|[ \t])_Float16[ \t]+__[0-9A-Za-z_]+f16[ \t]*\\([ \t]*_Float16[,) \t].*$";
+
+#define    DARWIN_FLOAT16_TEST_CT  1
+static tTestDesc aDarwin_Float16Tests[] = {
+  { TT_EGREP,    zDarwin_Float16Select0, (regex_t*)NULL }, };
+
+/*
+ *  Fix Command Arguments for Darwin_Float16
+ */
+static const char* apzDarwin_Float16Patch[] = {
+    "format",
+    "#ifndef __cplusplus\n\
+%0\n\
+#endif",
+    (char*)NULL };
+
 /* * * * * * * * * * * * * * * * * * * * * * * * * *
  *
  *  Description of Darwin_Gcc4_Breakage fix
@@ -10864,9 +10904,9 @@ static const char* apzX11_SprintfPatch[]
  *
  *  List of all fixes
  */
-#define REGEX_COUNT          304
+#define REGEX_COUNT          305
 #define MACH_LIST_SIZE_LIMIT 187
-#define FIX_COUNT            267
+#define FIX_COUNT            268
 
 /*
  *  Enumerate the fixes
@@ -10938,6 +10978,7 @@ typedef enum {
     CXX_UNREADY_FIXIDX,
     DARWIN_9_LONG_DOUBLE_FUNCS_2_FIXIDX,
     DARWIN_EXTERNC_FIXIDX,
+    DARWIN_FLOAT16_FIXIDX,
     DARWIN_GCC4_BREAKAGE_FIXIDX,
     DARWIN_LL_FUNCS_AVAIL_FIXIDX,
     DARWIN_LONGJMP_NORETURN_FIXIDX,
@@ -11472,6 +11513,11 @@ tFixDesc fixDescList[ FIX_COUNT ] = {
      DARWIN_EXTERNC_TEST_CT, FD_MACH_ONLY | FD_SUBROUTINE,
      aDarwin_ExterncTests,   apzDarwin_ExterncPatch, 0 },
 
+  {  zDarwin_Float16Name,    zDarwin_Float16List,
+     apzDarwin_Float16Machs,
+     DARWIN_FLOAT16_TEST_CT, FD_MACH_ONLY | FD_SUBROUTINE,
+     aDarwin_Float16Tests,   apzDarwin_Float16Patch, 0 },
+
   {  zDarwin_Gcc4_BreakageName,    zDarwin_Gcc4_BreakageList,
      apzDarwin_Gcc4_BreakageMachs,
      DARWIN_GCC4_BREAKAGE_TEST_CT, FD_MACH_ONLY | FD_SUBROUTINE,
