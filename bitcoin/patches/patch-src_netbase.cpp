$NetBSD$

--- src/netbase.cpp.orig	2015-07-10 17:23:55.000000000 +0000
+++ src/netbase.cpp
@@ -126,8 +126,12 @@ bool static LookupIntern(const char *psz
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
 #ifdef HAVE_GETADDRINFO_A
