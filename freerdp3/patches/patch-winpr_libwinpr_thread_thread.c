$NetBSD: patch-winpr_libwinpr_thread_thread.c,v 1.1 2023/01/19 08:01:37 markd Exp $

NetBSD9 and some others dont define ENOTRECOVERABLE

--- winpr/libwinpr/thread/thread.c.orig	2025-04-14 13:11:41.000000000 +0000
+++ winpr/libwinpr/thread/thread.c
@@ -278,7 +278,9 @@ static BOOL mux_condition_bundle_wait(mu
 			         winpr_strerror(r, ebuffer, sizeof(ebuffer)));
 			switch (r)
 			{
+#ifdef ENOTRECOVERABLE
 				case ENOTRECOVERABLE:
+#endif
 				case EPERM:
 				case ETIMEDOUT:
 				case EINVAL:
