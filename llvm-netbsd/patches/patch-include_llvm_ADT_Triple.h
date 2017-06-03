$NetBSD$

--- include/llvm/ADT/Triple.h.orig	2017-05-31 16:10:27.000000000 +0000
+++ include/llvm/ADT/Triple.h
@@ -239,7 +239,7 @@ public:
 
   /// Default constructor is the same as an empty string and leaves all
   /// triple fields unknown.
-  Triple() : Data(), Arch(), Vendor(), OS(), Environment(), ObjectFormat() {}
+  Triple() : Data(), Arch(), SubArch(), Vendor(), OS(), Environment(), ObjectFormat() {}
 
   explicit Triple(const Twine &Str);
   Triple(const Twine &ArchStr, const Twine &VendorStr, const Twine &OSStr);
