$NetBSD$

be nbsd specific.

--- src/netbase.cpp.orig	2013-08-05 12:37:21.000000000 +0000
+++ src/netbase.cpp
@@ -77,7 +77,7 @@ bool static LookupIntern(const char *psz
 #else
     aiHint.ai_family = AF_INET;
 #endif
-#ifdef WIN32
+#if defined(WIN32) || defined(__NetBSD__)
     aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
 #else
     aiHint.ai_flags = fAllowLookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
