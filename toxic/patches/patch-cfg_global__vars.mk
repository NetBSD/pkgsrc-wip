$NetBSD$

Allow overwriting PREFIX.

--- cfg/global_vars.mk.orig	2015-12-26 05:56:46.000000000 +0000
+++ cfg/global_vars.mk
@@ -23,7 +23,7 @@ SNDFILES += ToxicRecvMessage.wav ToxicOu
 SNDFILES += ToxicTransferComplete.wav ToxicTransferStart.wav
 
 # Install directories
-PREFIX = /usr/local
+PREFIX ?= /usr/local
 BINDIR = $(PREFIX)/bin
 DATADIR = $(PREFIX)/share/toxic
 MANDIR = $(PREFIX)/share/man
