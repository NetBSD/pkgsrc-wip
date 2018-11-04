$NetBSD$

Backport patch from upstream (commit 5d2b9e21fdf019f461ebe62738d615428d5db963)
to fix build with curl 7.62.0.

From CHANGES:
ssl: deprecate CURLE_SSL_CACERT in favour of a unified error code
     Long live CURLE_PEER_FAILED_VERIFICATION

--- src/http.c.orig	2018-06-27 17:42:33.000000000 +0000
+++ src/http.c
@@ -1555,7 +1555,9 @@ void ebcurl_setError(CURLcode curlret, c
 		break;
 
 	case CURLE_PEER_FAILED_VERIFICATION:
+#if LIBCURL_VERSION_NUM < 0x073e00
 	case CURLE_SSL_CACERT:
+#endif
 		(*fn) (MSG_NoCertify, host);
 		break;
 
