$NetBSD: patch-net_tools_hresolv_hresolv.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- net/tools/hresolv/hresolv.cc.orig	2011-04-13 08:01:16.000000000 +0000
+++ net/tools/hresolv/hresolv.cc
@@ -48,9 +48,11 @@ static const FlagName kAddrinfoFlagNames
   {AI_PASSIVE, "AI_PASSIVE"},
   {AI_CANONNAME, "AI_CANONNAME"},
   {AI_NUMERICHOST, "AI_NUMERICHOST"},
+#if !defined(OS_NETBSD)
   {AI_V4MAPPED, "AI_V4MAPPED"},
   {AI_ALL, "AI_ALL"},
   {AI_ADDRCONFIG, "AI_ADDRCONFIG"},
+#endif
 #if !defined(OS_MACOSX)
   {AI_NUMERICSERV, "AI_NUMERICSERV"},
 #endif
