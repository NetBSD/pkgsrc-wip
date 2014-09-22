$NetBSD: patch-src_netbase.cpp,v 1.1 2014/09/22 11:23:59 othyro Exp $

be nbsd specific.

--- src/netbase.cpp.orig	2014-06-19 07:51:15.000000000 +0000
+++ src/netbase.cpp
@@ -82,8 +82,12 @@ bool static LookupIntern(const char *psz
 #ifdef WIN32
     aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
 #else
+#if defined(__NetBSD__)
+    aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
+#else
     aiHint.ai_flags = fAllowLookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
 #endif
+#endif
     struct addrinfo *aiRes = NULL;
     int nErr = getaddrinfo(pszName, NULL, &aiHint, &aiRes);
     if (nErr)
