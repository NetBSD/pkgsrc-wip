$NetBSD$

Fix test suite for mips64el-unknown-netbsd.

--- tests/assembly-llvm/targets/targets-elf.rs.orig	2025-09-19 21:53:43.152938454 +0000
+++ tests/assembly-llvm/targets/targets-elf.rs
@@ -301,6 +301,9 @@
 //@ revisions: mips64el_unknown_linux_muslabi64
 //@ [mips64el_unknown_linux_muslabi64] compile-flags: --target mips64el-unknown-linux-muslabi64
 //@ [mips64el_unknown_linux_muslabi64] needs-llvm-components: mips
+//@ revisions: mips64el_unknown_netbsd
+//@ [mips64el_unknown_netbsd] compile-flags: --target mips64el_unknown_netbsd-unknown-linux-muslabi64
+//@ [mips64el_unknown_netbsd] needs-llvm-components: mips
 //@ revisions: mips_unknown_linux_gnu
 //@ [mips_unknown_linux_gnu] compile-flags: --target mips-unknown-linux-gnu
 //@ [mips_unknown_linux_gnu] needs-llvm-components: mips
