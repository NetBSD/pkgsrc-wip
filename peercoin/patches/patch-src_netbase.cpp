$NetBSD: patch-src_netbase.cpp,v 1.1 2014/09/22 11:21:19 othyro Exp $

be nbsd specific.

--- src/netbase.cpp.orig	2014-04-05 03:59:47.000000000 +0000
+++ src/netbase.cpp
@@ -30,7 +30,7 @@ bool static LookupIntern(const char *psz
 
     aiHint.ai_socktype = SOCK_STREAM;
     aiHint.ai_protocol = IPPROTO_TCP;
-#ifdef WIN32
+#if defined(WIN32) || defined(__NetBSD__)
 #  ifdef USE_IPV6
     aiHint.ai_family = AF_UNSPEC;
     aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
