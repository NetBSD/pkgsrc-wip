$NetBSD: patch-rules_build-prog.mk,v 1.1 2012/03/04 04:37:14 phonohawk Exp $

We need to pass some linker options even when we are linking programs
with C compiler. See: patch-utils_ghc-pkg_ghc.mk


--- rules/build-prog.mk.orig	2012-02-01 18:10:32.000000000 +0000
+++ rules/build-prog.mk
@@ -159,7 +159,7 @@ $1/$2/build/tmp/$$($1_$2_PROG) : $$($1_$
 	"$$($1_$2_HC)" -o $$@ $$($1_$2_v_ALL_HC_OPTS) $$(LD_OPTS) $$($1_$2_GHC_LD_OPTS) $$($1_$2_v_HS_OBJS) $$($1_$2_v_C_OBJS) $$($1_$2_v_S_OBJS) $$($1_$2_OTHER_OBJS) $$(addprefix -l,$$($1_$2_EXTRA_LIBRARIES))
 else
 $1/$2/build/tmp/$$($1_$2_PROG) : $$($1_$2_v_HS_OBJS) $$($1_$2_v_C_OBJS) $$($1_$2_v_S_OBJS) $$($1_$2_OTHER_OBJS) | $$$$(dir $$$$@)/.
-	"$$($1_$2_CC)" -o $$@ $$($1_$2_v_ALL_CC_OPTS) $$(LD_OPTS) $$($1_$2_v_HS_OBJS) $$($1_$2_v_C_OBJS) $$($1_$2_v_S_OBJS) $$($1_$2_OTHER_OBJS) $$($1_$2_v_EXTRA_CC_OPTS) $$(addprefix -l,$$($1_$2_EXTRA_LIBRARIES))
+	"$$($1_$2_CC)" -o $$@ $$($1_$2_v_ALL_CC_OPTS) $$(LD_OPTS) $$($1_$2_CC_LD_OPTS) $$($1_$2_v_HS_OBJS) $$($1_$2_v_C_OBJS) $$($1_$2_v_S_OBJS) $$($1_$2_OTHER_OBJS) $$($1_$2_v_EXTRA_CC_OPTS) $$(addprefix -l,$$($1_$2_EXTRA_LIBRARIES))
 endif
 
 # Note [lib-depends] if this program is built with stage1 or greater, we
