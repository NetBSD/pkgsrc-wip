$NetBSD: patch-config_makefiles_rust.mk,v 1.13 2024/08/01 15:41:09 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Use less memory to fix build under NetBSD/i386.
From: https://bugzilla.mozilla.org/show_bug.cgi?id=1644409

--- config/makefiles/rust.mk.orig	2024-07-04 17:04:12.000000000 +0000
+++ config/makefiles/rust.mk
@@ -60,6 +60,9 @@ ifdef MOZ_TSAN
 cargo_build_flags += -Zbuild-std=std,panic_abort
 RUSTFLAGS += -Zsanitizer=thread
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += @RUST_MAKE_JOBS@
+endif
 
 rustflags_sancov =
 ifdef LIBFUZZER
@@ -92,7 +95,7 @@ ifndef rustflags_sancov
 # Never enable when coverage is enabled to work around https://github.com/rust-lang/rust/issues/90045.
 ifndef MOZ_CODE_COVERAGE
 ifeq (,$(findstring gkrust_gtest,$(RUST_LIBRARY_FILE)))
-cargo_rustc_flags += -Clto$(if $(filter full,$(MOZ_LTO_RUST_CROSS)),=fat)
+cargo_rustc_flags += -Clto=thin
 endif
 # We need -Cembed-bitcode=yes for all crates when using -Clto.
 RUSTFLAGS += -Cembed-bitcode=yes
