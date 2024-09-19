$NetBSD$

--- minicargo.mk.orig	2021-09-12 00:15:52.000000000 +0000
+++ minicargo.mk
@@ -56,7 +56,6 @@ RUSTC_TARGET ?= x86_64-unknown-linux-gnu
 LLVM_TARGETS ?= X86;ARM;AArch64#;Mips;PowerPC;SystemZ;JSBackend;MSP430;Sparc;NVPTX
 OVERRIDE_DIR := script-overrides/$(RUSTC_CHANNEL)-$(RUSTC_VERSION)$(OVERRIDE_SUFFIX)/
 
-.PHONY: bin/mrustc bin/minicargo
 .PHONY: $(OUTDIR)libstd.rlib $(OUTDIR)libtest.rlib $(OUTDIR)libpanic_unwind.rlib $(OUTDIR)libproc_macro.rlib
 .PHONY: $(OUTDIR)rustc $(OUTDIR)cargo
 
