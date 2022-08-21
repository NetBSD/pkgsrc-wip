$NetBSD$

--- minicargo.mk.orig	2022-08-14 04:09:16.000000000 +0000
+++ minicargo.mk
@@ -134,8 +134,8 @@ OVERRIDE_DIR := script-overrides/$(RUSTC
 #  Top-level targets
 # ---------------------------------------------------------------------
 
-.PHONY: $(OUTDIR)libstd.rlib $(OUTDIR)libtest.rlib $(OUTDIR)libpanic_unwind.rlib $(OUTDIR)libproc_macro.rlib
-.PHONY: $(OUTDIR)rustc $(OUTDIR)cargo
+###.PHONY: $(OUTDIR)libstd.rlib $(OUTDIR)libtest.rlib $(OUTDIR)libpanic_unwind.rlib $(OUTDIR)libproc_macro.rlib
+###.PHONY: $(OUTDIR)rustc $(OUTDIR)cargo
 
 .PHONY: all test LIBS
 .PHONY: RUSTCSRC
@@ -155,7 +155,7 @@ rust_tests: RUST_TESTS_run-pass
 # rust_tests-compile-fail
 
 # --- Ensure that mrustc/minicargo are built ---
-.PHONY: bin/mrustc$(EXESUF) bin/minicargo$(EXESUF) bin/testrunner$(EXESUF)
+###.PHONY: bin/mrustc$(EXESUF) bin/minicargo$(EXESUF) bin/testrunner$(EXESUF)
 bin/mrustc$(EXESUF):
 	$(MAKE) -f Makefile all
 	test -e $@
@@ -176,15 +176,18 @@ $(RUSTC_SRC_TARBALL):
 	@echo [CURL] $@
 	@rm -f $@
 	@curl -sS https://static.rust-lang.org/dist/$@ -o $@
-$(RUSTC_SRC_DL): $(RUSTC_SRC_TARBALL) rustc-$(RUSTC_VERSION)-src.patch
-	tar -xf $(RUSTC_SRC_TARBALL)
+##$(RUSTC_SRC_DL): $(RUSTC_SRC_TARBALL) rustc-$(RUSTC_VERSION)-src.patch
+$(RUSTC_SRC_DL): rustc-$(RUSTC_VERSION)-src.patch
+	@###tar -xf $(RUSTC_SRC_TARBALL)
+	@mv ../$(RUSTCSRC) ./
 	cd $(RUSTCSRC) && patch -p0 < ../rustc-$(RUSTC_VERSION)-src.patch;
+	find $(RUSTCSRC) -name '*.[oa]' -print0 | xargs -0 rm
 	touch $(RUSTC_SRC_DL)
 
 # Standard library crates
 # - libstd, libpanic_unwind, libtest and libgetopts
 # - libproc_macro (mrustc)
-$(OUTDIR)libstd.rlib: $(MRUSTC) $(MINICARGO) $(RUSTC_SRC_DL)
+$(OUTDIR)libstd.rlib: $(MRUSTC) $(MINICARGO)
 	$(MINICARGO) $(RUSTCSRC)$(RUST_LIB_PREFIX)std --vendor-dir $(VENDOR_DIR) --script-overrides $(OVERRIDE_DIR) --output-dir $(OUTDIR) $(MINICARGO_FLAGS)
 	@test -e $@
 $(OUTDIR)libpanic_unwind.rlib: $(OUTDIR)libstd.rlib
@@ -199,7 +202,7 @@ $(OUTDIR)libproc_macro.rlib: $(OUTDIR)li
 	@test -e $@
 
 # Dynamically linked version of the standard library
-$(OUTDIR)test/libtest.so: $(RUSTC_SRC_DL)
+$(OUTDIR)test/libtest.so:
 	mkdir -p $(dir $@)
 	MINICARGO_DYLIB=1 $(MINICARGO) $(RUSTCSRC)$(RUST_LIB_PREFIX)std          --vendor-dir $(VENDOR_DIR) --script-overrides $(OVERRIDE_DIR) --output-dir $(dir $@) $(MINICARGO_FLAGS)
 	MINICARGO_DYLIB=1 $(MINICARGO) $(RUSTCSRC)$(RUST_LIB_PREFIX)panic_unwind --vendor-dir $(VENDOR_DIR) --script-overrides $(OVERRIDE_DIR) --output-dir $(dir $@) $(MINICARGO_FLAGS)
