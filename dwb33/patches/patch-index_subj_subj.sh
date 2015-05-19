$NetBSD: patch-index_subj_subj.sh,v 1.1 2015/05/19 14:23:22 n-t-roff Exp $

Make executeable

--- index/subj/subj.sh.orig	2015-05-19 16:08:15.000000000 +0200
+++ index/subj/subj.sh	2015-05-19 16:08:26.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 trap  'rm -f /tmp/sbj*$$; exit' 1 2 3 15
 UL=/usr/lib/dwb
 d=d
