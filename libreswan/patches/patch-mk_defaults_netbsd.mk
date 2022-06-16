$NetBSD$

Backport patch from upstream.

commit 8861abd461ad049f915fb4aad8ac123188f407a7
Author: Andrew Cagney <cagney@gnu.org>
Date:   Tue Jun 14 20:54:55 2022 -0400

    NetBSD: install manual pages in $(PREFIX)/man

    not share/man

--- mk/defaults/netbsd.mk.orig	2022-05-24 17:23:22.000000000 +0000
+++ mk/defaults/netbsd.mk
@@ -30,3 +30,4 @@ FINALRUNDIR=/var/run/pluto
 FINALSYSCONFDIR=$(PREFIX)/etc
 FINALNSSDIR=$(PREFIX)/etc/ipsec.d
 FINALEXAMPECONFDIR=$(PREFIX)/share/examples/libreswan
+FINALMANDIR=$(PREFIX)/man
