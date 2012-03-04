$NetBSD: patch-rts_ghc.mk,v 1.3 2012/03/04 04:37:14 phonohawk Exp $

Hunk #1:
  Specify a C compiler to build C sources when we're bootstrapping.

Hunk #2:
  Missing dependency on generated headers.

Hunk #3:
  This is pkgsrc specific: /usr/sbin/dtrace gets confused when we have
  ghc wrappers in the PATH so we have to hide them.


--- rts/ghc.mk.orig	2012-02-01 18:10:32.000000000 +0000
+++ rts/ghc.mk
@@ -15,6 +15,7 @@
 
 # We build the RTS with stage 1
 rts_dist_HC = $(GHC_STAGE1)
+rts_dist_CC = $(CC_STAGE1)
 
 # merge GhcLibWays and GhcRTSWays but strip out duplicates
 rts_WAYS = $(GhcLibWays) $(filter-out $(GhcLibWays),$(GhcRTSWays))
@@ -457,6 +458,10 @@ $(eval $(call dependencies,rts,dist,1))
 
 $(rts_dist_depfile_c_asm) : $(libffi_HEADERS) $(DTRACEPROBES_H)
 
+ifeq "$(BootingFromHc)" "YES"
+$(rts_C_SRCS) : $(libffi_HEADERS) $(DTRACEPROBES_H)
+endif
+
 # -----------------------------------------------------------------------------
 # compile dtrace probes if dtrace is supported
 
@@ -479,7 +484,7 @@ endif
 
 DTRACEPROBES_SRC = rts/RtsProbes.d
 $(DTRACEPROBES_H): $(DTRACEPROBES_SRC) includes/ghcplatform.h | $$(dir $$@)/.
-	"$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
+	env PATH="/usr/bin" "$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
 endif
 
 # -----------------------------------------------------------------------------
