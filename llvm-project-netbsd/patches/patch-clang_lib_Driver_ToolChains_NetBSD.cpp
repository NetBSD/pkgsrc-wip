$NetBSD$

--- clang/lib/Driver/ToolChains/NetBSD.cpp.orig	2019-10-23 20:24:27.000000000 +0000
+++ clang/lib/Driver/ToolChains/NetBSD.cpp
@@ -266,7 +266,7 @@ void netbsd::Linker::ConstructJob(Compil
   unsigned Major, Minor, Micro;
   ToolChain.getTriple().getOSVersion(Major, Minor, Micro);
   bool useLibgcc = true;
-  if (Major >= 7 || Major == 0) {
+  if (false) {
     switch (ToolChain.getArch()) {
     case llvm::Triple::aarch64:
     case llvm::Triple::aarch64_be:
@@ -402,7 +402,7 @@ Tool *NetBSD::buildLinker() const { retu
 ToolChain::CXXStdlibType NetBSD::GetDefaultCXXStdlibType() const {
   unsigned Major, Minor, Micro;
   getTriple().getOSVersion(Major, Minor, Micro);
-  if (Major >= 7 || Major == 0) {
+  if (false) {
     switch (getArch()) {
     case llvm::Triple::aarch64:
     case llvm::Triple::aarch64_be:
