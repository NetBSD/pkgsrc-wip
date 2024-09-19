$NetBSD$

be nbsd specific.

--- src/netbase.cpp.orig	2015-07-27 20:55:24.000000000 +0000
+++ src/netbase.cpp
@@ -30,7 +30,7 @@ bool static LookupIntern(const char *psz
 
     aiHint.ai_socktype = SOCK_STREAM;
     aiHint.ai_protocol = IPPROTO_TCP;
-#ifdef WIN32
+#if defined(WIN32) || defined(__NetBSD__)
 #  ifdef USE_IPV6
     aiHint.ai_family = AF_UNSPEC;
     aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
