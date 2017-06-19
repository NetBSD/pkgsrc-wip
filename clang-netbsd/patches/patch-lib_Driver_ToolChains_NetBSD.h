$NetBSD$

--- lib/Driver/ToolChains/NetBSD.h.orig	2017-03-18 00:58:03.000000000 +0000
+++ lib/Driver/ToolChains/NetBSD.h
@@ -66,6 +66,7 @@ public:
       llvm::opt::ArgStringList &CC1Args) const override;
 
   bool IsUnwindTablesDefault() const override { return true; }
+  SanitizerMask getSupportedSanitizers() const override;
 
 protected:
   Tool *buildAssembler() const override;
