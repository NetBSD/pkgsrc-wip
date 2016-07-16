$NetBSD$

Allow use of RUSTFLAGS$(STAGE)_$(CRATE) to be used here too, needed to
sucessfully complete rustc.

--- mk/target.mk.orig	2016-07-04 18:04:09.000000000 +0000
+++ mk/target.mk
@@ -144,6 +144,7 @@ $$(TBIN$(1)_T_$(2)_H_$(3))/$(4)$$(X_$(2)
 	@$$(call E, rustc: $$@)
 	$$(STAGE$(1)_T_$(2)_H_$(3)) \
 		$$(LLVM_LIBDIR_RUSTFLAGS_$(2)) \
+		$$(RUSTFLAGS$(1)_$(4)) \
 		-o $$@ $$< --cfg $(4)
 
 endef
