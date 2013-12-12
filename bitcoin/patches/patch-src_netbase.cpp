$NetBSD: patch-src_netbase.cpp,v 1.1 2013/12/12 20:45:11 noud4 Exp $

be nbsd specific.

--- src/netbase.cpp.orig	2013-09-12 10:43:31.000000000 +0000
+++ src/netbase.cpp
@@ -80,8 +80,12 @@ bool static LookupIntern(const char *psz
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
