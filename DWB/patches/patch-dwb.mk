$NetBSD: patch-dwb.mk,v 1.1 2015/08/21 14:06:58 leot1990 Exp $

Adjust GROUP, OWNER and ROOT variables making them MAKE_ENV friendly.

--- dwb.mk.orig	2015-05-17 16:28:51.000000000 +0000
+++ dwb.mk
@@ -178,14 +178,14 @@ MAKEFILE=dwb.mk
 SYSTEM=BSD4_2
 VERSION=3.3
 
-GROUP=bin
-OWNER=root
+GROUP?=bin
+OWNER?=root
 
 HYPHALG=0
 NDEVNAME=37
 TDEVNAME=post
 
-ROOT=/usr/local/dwb
+ROOT?=/usr/local/dwb
 BINDIR=$(ROOT)/bin
 FONTDIR=$(ROOT)/lib/font
 HOSTDIR=$(ROOT)/lib/font/postscript
