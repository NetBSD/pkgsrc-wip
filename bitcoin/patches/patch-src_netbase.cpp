$NetBSD$

It is unclear why this patch exists.  NetBSD 6 and 7 have AI_ADDRCONFIG,
although NetBSD 5 does not.  Arguably upstream should have an autoconf
test instead.  This is not known to be reported upstream.

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
