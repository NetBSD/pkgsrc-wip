$NetBSD$

--- sendmail/readcf.c.orig	2023-12-19 05:29:19.000000000 +0000
+++ sendmail/readcf.c
@@ -26,6 +26,10 @@ SM_RCSID("@(#)$Id: readcf.c,v 8.692 2013
 # include <arpa/inet.h>
 #endif
 
+#if NAMED_BIND
+extern struct __res_state sm_res;
+#endif
+
 
 #define SECONDS
 #define MINUTES	* 60
@@ -3208,6 +3212,9 @@ static struct optioninfo
 	{ "CipherSuites",		O_CIPHERSUITES,	OI_NONE	},
 #endif
 
+# define O_BLACKLIST   0xfb
+	{ "UseBlacklist",		O_BLACKLIST,	OI_NONE },
+
 	{ NULL,				'\0',		OI_NONE	}
 };
 
@@ -3618,13 +3625,13 @@ setoption(opt, val, safe, sticky, e)
 			if (rfp->rf_name == NULL)
 				syserr("readcf: I option value %s unrecognized", q);
 			else if (clearmode)
-				_res.options &= ~rfp->rf_bits;
+				sm_res.options &= ~rfp->rf_bits;
 			else
-				_res.options |= rfp->rf_bits;
+				sm_res.options |= rfp->rf_bits;
 		}
 		if (tTd(8, 2))
-			sm_dprintf("_res.options = %x, HasWildcardMX = %d\n",
-				   (unsigned int) _res.options, HasWildcardMX);
+			sm_dprintf("sm_res.options = %x, HasWildcardMX = %d\n",
+				   (unsigned int) sm_res.options, HasWildcardMX);
 #else /* NAMED_BIND */
 		usrerr("name server (I option) specified but BIND not compiled in");
 #endif /* NAMED_BIND */
@@ -4946,6 +4953,10 @@ setoption(opt, val, safe, sticky, e)
 		break;
 #endif
 
+	  case O_BLACKLIST:
+		UseBlacklist = atobool(val);
+		break;
+		
 	  default:
 		if (tTd(37, 1))
 		{
