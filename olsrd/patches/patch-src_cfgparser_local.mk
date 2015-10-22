$NetBSD: patch-src_cfgparser_local.mk,v 1.1 2012/09/28 22:44:11 khorben Exp $

Fixed invocation of flex

--- src/cfgparser/local.mk.orig	2014-12-29 11:17:09.000000000 +0000
+++ src/cfgparser/local.mk
@@ -45,6 +45,8 @@ SRCS += $(foreach file,olsrd_conf oparse
 OBJS += $(foreach file,olsrd_conf oparse oscan cfgfile_gen,$(C)$(file).o)
 HDRS += $(foreach file,olsrd_conf oparse,$(C)$(file).h)
 
+FLEX ?= flex
+
 $(C)oscan.c: $(C)oscan.lex $(C)Makefile
 ifeq ($(VERBOSE),0)
 	@echo "[FLEX] $@"
