$NetBSD: patch-az,v 1.4 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/srvrsmtp.c.orig	2023-12-05 09:53:22.000000000 +0000
+++ sendmail/srvrsmtp.c
@@ -51,6 +51,10 @@ static bool	tls_ok_srv = false;
 static bool	NotFirstDelivery = false;
 #endif
 
+#if NAMED_BIND
+extern struct __res_state sm_res;
+#endif
+
 /* server features */
 #define SRV_NONE	0x00000000	/* none... */
 #define SRV_OFFER_TLS	0x00000001	/* offer STARTTLS */
@@ -1513,6 +1517,7 @@ smtp(nullserver, d_flags, e)
 					  (int) tp->tv_sec +
 						(tp->tv_usec >= 500000 ? 1 : 0)
 					 );
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "pre-greeting traffic");				
 			}
 		}
 	}
@@ -1801,7 +1806,12 @@ smtp(nullserver, d_flags, e)
 			/* get an OK if we're done */
 			if (result == SASL_OK)
 			{
+				int fd;
+
   authenticated:
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_AUTH_OK, fd, "AUTH OK");
+
 				message("235 2.0.0 OK Authenticated");
 				authenticating = SASL_IS_AUTH;
 				macdefine(&BlankEnvelope.e_macro, A_TEMP,
@@ -1946,6 +1956,7 @@ smtp(nullserver, d_flags, e)
 	{	\
 		SET_AUTH_USER_CONDITIONALLY	\
 		message("535 5.7.0 authentication failed");	\
+		BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL), "AUTH FAIL");	\
 		if (LogLevel >= 9)	\
 			sm_syslog(LOG_WARNING, e->e_id,	\
 				  "AUTH failure (%s): %s (%d) %s%s%.*s, relay=%.100s",	\
@@ -2061,6 +2072,10 @@ smtp(nullserver, d_flags, e)
 				if (nullserver != NULL &&
 				    ++n_badcmds > MAXBADCOMMANDS)
 				{
+					int fd;
+
+					fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+					BLACKLIST_NOTIFY(BLACKLIST_ABUSIVE_BEHAVIOR, fd, "too many bad commands");
 					message("421 4.7.0 %s Too many bad commands; closing connection",
 						MyHostName);
 
@@ -3921,7 +3936,11 @@ smtp(nullserver, d_flags, e)
 #if MAXBADCOMMANDS > 0
 			if (++n_badcmds > MAXBADCOMMANDS)
 			{
+				int fd;
+
   stopattack:
+				fd = sm_io_getinfo(InChannel, SM_IO_WHAT_FD, NULL);
+				BLACKLIST_NOTIFY(BLACKLIST_ABUSIVE_BEHAVIOR, fd, "too many bad commands");
 				message("421 4.7.0 %s Too many bad commands; closing connection",
 					MyHostName);
 
@@ -4414,8 +4433,8 @@ smtp_data(smtp, e, check_stuffing)
 	id = e->e_id;
 
 #if NAMED_BIND
-	_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
-	_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
+	sm_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
+	sm_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
 #endif
 
 #if _FFR_PROXY
