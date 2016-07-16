$NetBSD$

Use pkgsrc libLLVM.

--- mk/main.mk.orig	2016-06-30 23:21:42.000000000 +0000
+++ mk/main.mk
@@ -295,7 +295,7 @@ LLVM_REQUIRED_COMPONENTS=ipo bitreader b
 
 ifneq ($(CFG_LLVM_ROOT),)
 # Ensure we only try to link targets that the installed LLVM actually has:
-LLVM_COMPONENTS := $(filter $(shell $(CFG_LLVM_ROOT)/bin/llvm-config$(X_$(CFG_BUILD)) --components),\
+LLVM_COMPONENTS := $(filter $(shell $(CFG_LLVM_ROOT)/libexec/libLLVM/llvm-config$(X_$(CFG_BUILD)) --components),\
 			$(LLVM_OPTIONAL_COMPONENTS)) $(LLVM_REQUIRED_COMPONENTS)
 else
 LLVM_COMPONENTS := $(LLVM_OPTIONAL_COMPONENTS) $(LLVM_REQUIRED_COMPONENTS)
@@ -315,7 +315,7 @@ CFG_LLVM_INST_DIR_$(1):=$$(CFG_LLVM_ROOT
 endif
 
 # Any rules that depend on LLVM should depend on LLVM_CONFIG
-LLVM_CONFIG_$(1):=$$(CFG_LLVM_INST_DIR_$(1))/bin/llvm-config$$(X_$(1))
+LLVM_CONFIG_$(1):=$$(CFG_LLVM_INST_DIR_$(1))/libexec/libLLVM/llvm-config$$(X_$(1))
 LLVM_MC_$(1):=$$(CFG_LLVM_INST_DIR_$(1))/bin/llvm-mc$$(X_$(1))
 LLVM_AR_$(1):=$$(CFG_LLVM_INST_DIR_$(1))/bin/llvm-ar$$(X_$(1))
 LLVM_VERSION_$(1)=$$(shell "$$(LLVM_CONFIG_$(1))" --version)
