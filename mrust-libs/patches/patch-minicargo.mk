$NetBSD$

--- minicargo.mk.orig	2022-08-14 04:09:16.000000000 +0000
+++ minicargo.mk
@@ -135,7 +135,7 @@ OVERRIDE_DIR := script-overrides/$(RUSTC
 # ---------------------------------------------------------------------
 
 .PHONY: $(OUTDIR)libstd.rlib $(OUTDIR)libtest.rlib $(OUTDIR)libpanic_unwind.rlib $(OUTDIR)libproc_macro.rlib
-.PHONY: $(OUTDIR)rustc $(OUTDIR)cargo
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
@@ -176,9 +176,12 @@ $(RUSTC_SRC_TARBALL):
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
