$NetBSD: patch-config_rules.mk,v 1.3 2014/11/06 15:47:24 thomasklausner Exp $

--- config/rules.mk.orig	2014-11-06 09:56:12.000000000 +0000
+++ config/rules.mk
@@ -770,6 +770,7 @@ endif
 ifdef DTRACE_PROBE_OBJ
 EXTRA_DEPS += $(DTRACE_PROBE_OBJ)
 OBJS += $(DTRACE_PROBE_OBJ)
+EXCLUDED_OBJS += $(DTRACE_PROBE_OBJ)
 endif
 
 $(filter %.$(LIB_SUFFIX),$(LIBRARY)): $(OBJS) $(STATIC_LIBS_DEPS) $(filter %.$(LIB_SUFFIX),$(EXTRA_LIBS)) $(EXTRA_DEPS) $(GLOBAL_DEPS)
