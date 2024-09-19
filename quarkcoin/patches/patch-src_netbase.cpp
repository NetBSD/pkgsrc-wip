$NetBSD$

--- src/netbase.cpp.orig	2015-05-31 10:15:00.000000000 +0000
+++ src/netbase.cpp
@@ -79,7 +79,7 @@ bool static LookupIntern(const char *psz
     aiHint.ai_socktype = SOCK_STREAM;
     aiHint.ai_protocol = IPPROTO_TCP;
     aiHint.ai_family = AF_UNSPEC;
-#ifdef WIN32
+#if defined(WIN32) || defined(__NetBSD__)
     aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
 #else
     aiHint.ai_flags = fAllowLookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
