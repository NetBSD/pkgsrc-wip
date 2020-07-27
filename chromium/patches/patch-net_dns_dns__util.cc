$NetBSD$

--- net/dns/dns_util.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ net/dns/dns_util.cc
@@ -40,6 +40,7 @@ const uint16_t kFlagNamePointer = 0xc000
 }  // namespace
 
 #if defined(OS_POSIX)
+#include <sys/socket.h>
 #include <netinet/in.h>
 #if !defined(OS_NACL)
 #include <net/if.h>
