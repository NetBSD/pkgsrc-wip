$NetBSD$

--- src/jit/error.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/jit/error.cpp
@@ -293,7 +293,7 @@ void  __cdecl   assertAbort(const char *
     const char* msg = why;
     LogEnv* env = LogEnv::cur();
     const int BUFF_SIZE = 8192;
-    char *buff = (char*)alloca(BUFF_SIZE);
+    char *buff = (char*)Alloca(BUFF_SIZE);
     if (env->compiler) {
         _snprintf_s(buff, BUFF_SIZE, _TRUNCATE, "Assertion failed '%s' in '%s' (IL size %d)\n", why, env->compiler->info.compFullName, env->compiler->info.compILCodeSize);
         msg = buff;
