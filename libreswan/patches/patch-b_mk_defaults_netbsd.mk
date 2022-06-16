$NetBSD$

Backport patch from upstream.

commit 8861abd461ad049f915fb4aad8ac123188f407a7
Author: Andrew Cagney <cagney@gnu.org>
Date:   Tue Jun 14 20:54:55 2022 -0400

    NetBSD: install manual pages in $(PREFIX)/man
    
    not share/man

diff --git a/mk/defaults/netbsd.mk b/mk/defaults/netbsd.mk
index 4c623089f5..d9e3d262f8 100644
--- a/mk/defaults/netbsd.mk
+++ b/mk/defaults/netbsd.mk
@@ -33,3 +33,4 @@ FINALRUNDIR=/var/run/pluto
 FINALSYSCONFDIR=$(PREFIX)/etc
 FINALNSSDIR=$(PREFIX)/etc/ipsec.d
 FINALEXAMPECONFDIR=$(PREFIX)/share/examples/libreswan
+FINALMANDIR=$(PREFIX)/man
