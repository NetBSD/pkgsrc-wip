$NetBSD: patch-Makefile.inc,v 1.1 2011/09/19 05:01:01 ryo-on Exp $

* Pass checking for missing run-time search paths

--- Makefile.inc.orig	2010-11-08 14:21:11.000000000 +0000
+++ Makefile.inc
@@ -1,7 +1,7 @@
 CC=gcc
 
 CFLAGS=-Wall -g
-CLIBS=-lsqlite3 -ldl -lncurses
+CLIBS=-lsqlite3 -ldl -lncurses -Wl,-rpath=${PREFIX}/lib
 
 PREFIX=/usr
 BIN_DIR=$(PREFIX)/bin
