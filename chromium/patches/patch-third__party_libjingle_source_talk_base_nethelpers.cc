$NetBSD: patch-third__party_libjingle_source_talk_base_nethelpers.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- third_party/libjingle/source/talk/base/nethelpers.cc.orig	2011-05-24 08:20:06.000000000 +0000
+++ third_party/libjingle/source/talk/base/nethelpers.cc
@@ -154,6 +154,8 @@ hostent* SafeGetHostByName(const char* h
 #elif defined(OSX) || defined(IOS)
   // Mac OS returns an object with everything allocated.
   result = getipnodebyname(hostname, AF_INET, AI_DEFAULT, herrno);
+#elif defined(BSD)
+  result = gethostbyname(hostname);
 #else
 #error "I don't know how to do gethostbyname safely on your system."
 #endif
