$NetBSD$

--- tests/test-runner.c.orig	2015-11-25 10:00:50.000000000 +0000
+++ tests/test-runner.c
@@ -59,14 +59,14 @@ extern const struct test __start_test_se
 
 /* This is all disabled for FreeBSD because it gives "can't allocate initial
  * thread" aborts otherwise. */
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 static void* (*sys_malloc)(size_t);
 static void (*sys_free)(void*);
 static void* (*sys_realloc)(void*, size_t);
 static void* (*sys_calloc)(size_t, size_t);
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 /* XXX review ptrace() usage */
 #define PTRACE_ATTACH PT_ATTACH
 #define PTRACE_CONT PT_CONTINUE
@@ -88,7 +88,7 @@ static int is_atty = 0;
 
 extern const struct test __start_test_section, __stop_test_section;
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 __attribute__ ((visibility("default"))) void *
 malloc(size_t size)
 {
@@ -378,7 +378,7 @@ int main(int argc, char *argv[])
 	int status;
 #endif
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	/* Load system malloc, free, and realloc */
 	sys_calloc = dlsym(RTLD_NEXT, "calloc");
 	sys_realloc = dlsym(RTLD_NEXT, "realloc");
