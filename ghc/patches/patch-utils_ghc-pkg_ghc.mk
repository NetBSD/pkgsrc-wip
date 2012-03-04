$NetBSD: patch-utils_ghc-pkg_ghc.mk,v 1.1 2012/03/04 04:37:14 phonohawk Exp $

Don't let librts.a/Weak.o to be excluded from the linkage. Otherwise
we get an "undefined symbol" error.


--- utils/ghc-pkg/ghc.mk.orig	2012-02-01 18:10:32.000000000 +0000
+++ utils/ghc-pkg/ghc.mk
@@ -95,6 +95,11 @@ utils/ghc-pkg_dist-install_INSTALL_INPLA
 
 ifeq "$(BootingFromHc)" "YES"
 utils/ghc-pkg_dist-install_OTHER_OBJS += $(ALL_STAGE1_LIBS) $(ALL_STAGE1_LIBS) $(ALL_STAGE1_LIBS) $(ALL_RTS_LIBS) $(libffi_STATIC_LIB)
+ifeq "$(LeadingUnderscore)" "YES"
+utils/ghc-pkg_dist-install_CC_LD_OPTS += -u _base_GHCziWeak_runFinalizzerBatch_closure
+else
+utils/ghc-pkg_dist-install_CC_LD_OPTS += -u base_GHCziWeak_runFinalizzerBatch_closure
+endif
 endif
 
 $(eval $(call build-prog,utils/ghc-pkg,dist-install,1))
