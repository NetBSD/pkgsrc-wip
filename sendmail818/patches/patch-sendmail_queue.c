$NetBSD: patch-av,v 1.2 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/queue.c.orig	2020-05-27 16:32:09.000000000 +0000
+++ sendmail/queue.c
@@ -34,6 +34,10 @@ SM_RCSID("@(#)$Id: queue.c,v 8.1000 2013
 # define SM_OPEN_EXLOCK 0
 #endif
 
+#if NAMED_BIND
+extern struct __res_state sm_res;
+#endif
+
 /*
 **  Historical notes:
 **	QF_VERSION == 4 was sendmail 8.10/8.11 without _FFR_QUEUEDELAY
@@ -4394,13 +4398,13 @@ readqf(e, openonly)
 			/* adjust BIND parameters immediately */
 			if (e->e_ntries == 0)
 			{
-				_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
-				_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
+				sm_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
+				sm_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
 			}
 			else
 			{
-				_res.retry = TimeOuts.res_retry[RES_TO_NORMAL];
-				_res.retrans = TimeOuts.res_retrans[RES_TO_NORMAL];
+				sm_res.retry = TimeOuts.res_retry[RES_TO_NORMAL];
+				sm_res.retrans = TimeOuts.res_retrans[RES_TO_NORMAL];
 			}
 #endif /* NAMED_BIND */
 			break;
