$NetBSD$

--- src/libs/xpcom18a4/nsprpub/pr/src/linking/prlink.c.orig	2018-12-18 13:01:26.000000000 +0000
+++ src/libs/xpcom18a4/nsprpub/pr/src/linking/prlink.c
@@ -1810,7 +1810,7 @@ PR_LoadStaticLibrary(const char *name, c
 PR_IMPLEMENT(char *)
 PR_GetLibraryFilePathname(const char *name, PRFuncPtr addr)
 {
-#if defined(SOLARIS) || defined(LINUX) || defined(FREEBSD)
+#if defined(SOLARIS) || defined(LINUX) || defined(FREEBSD) || defined(NETBSD)
     Dl_info dli;
     char *result;
 
