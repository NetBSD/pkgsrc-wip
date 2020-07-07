$NetBSD$

Use pthreads on NetBSD.

From upstream pull request #355:

 <https://github.com/9fans/plan9port/pull/355>

--- include/u.h.orig	2020-06-22 15:22:27.000000000 +0000
+++ include/u.h
@@ -108,6 +108,8 @@ typedef long p9jmp_buf[sizeof(sigjmp_buf
 #elif defined(__NetBSD__)
 #	include <sched.h>
 #	include <sys/types.h>
+#	include <pthread.h>
+#	define PLAN9PORT_USING_PTHREADS 1
 #	undef _NEEDUSHORT
 #	undef _NEEDUINT
 #	undef _NEEDULONG
