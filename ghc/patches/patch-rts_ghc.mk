$NetBSD: patch-rts_ghc.mk,v 1.1 2011/05/06 02:30:25 phonohawk Exp $

The first section:
  HC bootstrapping has bitrotted further. We need to build RtsProbes.h
  before compiling Capability.hc but rts/ghc.mk doesn't have such
  rule.

The second section:
  This is pkgsrc specific. /usr/sbin/dtrace gets confused when we have
  ghc wrappers in the PATH so we have to hide them.


--- rts/ghc.mk.orig	2011-03-26 18:10:07.000000000 +0000
+++ rts/ghc.mk
@@ -452,12 +452,14 @@ rts_dist_MKDEPENDC_OPTS += -DPROFILING -
 ifeq "$(USE_DTRACE)" "YES"
 
 rts_dist_MKDEPENDC_OPTS += -Irts/dist/build
+rts_CC_OPTS += -Irts/dist/build
 
 endif
 
 $(eval $(call build-dependencies,rts,dist,1))
 
 $(rts_dist_depfile_c_asm) : libffi/dist-install/build/ffi.h $(DTRACEPROBES_H)
+rts/dist/build/Capability.o : $(DTRACEPROBES_H)
 
 #-----------------------------------------------------------------------------
 # libffi stuff
@@ -489,7 +491,7 @@ endif
 
 DTRACEPROBES_SRC = rts/RtsProbes.d
 $(DTRACEPROBES_H): $(DTRACEPROBES_SRC) includes/ghcplatform.h | $$(dir $$@)/.
-	"$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
+	env PATH=/usr/bin "$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
 endif
 
 # -----------------------------------------------------------------------------
