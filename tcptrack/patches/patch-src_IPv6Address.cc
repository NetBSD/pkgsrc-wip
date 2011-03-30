$NetBSD: patch-src_IPv6Address.cc,v 1.1 2011/03/30 10:30:18 moubctez Exp $

Some systems define s6_addr16 as private, so redefine it here.

--- work/tcptrack-1.4.0/src/IPv6Address.cc.orig	2011-03-30 10:23:27.000000000 +0000
+++ work/tcptrack-1.4.0/src/IPv6Address.cc
@@ -7,6 +7,10 @@
 #include "IPv6Address.h"
 #include "util.h"
 
+#ifndef s6_addr16
+#define s6_addr16 __u6_addr.__u6_addr16
+#endif
+
 uint16_t IPv6Address::GetShort( int index ) const
 {
 	assert(index >= 0);
