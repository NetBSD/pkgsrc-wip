$NetBSD: patch-src_cfgparser_local.mk,v 1.1 2012/09/28 22:44:11 khorben Exp $

Fixed invocation of flex

--- src/cfgparser/local.mk.orig	2010-03-31 17:03:53.000000000 +0000
+++ src/cfgparser/local.mk
@@ -45,6 +45,8 @@ SRCS += $(foreach file,olsrd_conf oparse
 OBJS += $(foreach file,olsrd_conf oparse oscan cfgfile_gen,$(C)$(file).o)
 HDRS += $(foreach file,olsrd_conf oparse,$(C)$(file).h)
 
+FLEX ?= flex
+
 $(C)oscan.c: $(C)oscan.lex $(C)Makefile
 	$(FLEX) -Cem -o"$@-tmp" "$<"
 	sed	-e '/^static/s/yy_get_next_buffer[\(][\)]/yy_get_next_buffer(void)/' \
