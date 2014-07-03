$NetBSD: patch-src_llvm_unittests_ADT_TripleTest.cpp,v 1.1 2014/07/03 03:11:32 schmonz Exp $

Detect NetBSD.

--- src/llvm/unittests/ADT/TripleTest.cpp.orig	2014-06-27 19:54:08.000000000 +0000
+++ src/llvm/unittests/ADT/TripleTest.cpp
@@ -499,7 +499,7 @@ TEST(TripleTest, getOSVersion) {
 TEST(TripleTest, FileFormat) {
   EXPECT_EQ(Triple::ELF, Triple("i686-unknown-linux-gnu").getObjectFormat());
   EXPECT_EQ(Triple::ELF, Triple("i686-unknown-freebsd").getObjectFormat());
-  EXPECT_EQ(Triple::ELF, Triple("i686-unknown-netbsd").getObjectFormat());
+  EXPECT_EQ(Triple::ELF, Triple("i686--netbsd").getObjectFormat());
   EXPECT_EQ(Triple::ELF, Triple("i686--win32-elf").getObjectFormat());
   EXPECT_EQ(Triple::ELF, Triple("i686---elf").getObjectFormat());
 
