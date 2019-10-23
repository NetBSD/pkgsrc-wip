$NetBSD$

--- lld/test/ELF/gnustack.s.orig	2019-10-23 20:24:36.334197305 +0000
+++ lld/test/ELF/gnustack.s
@@ -10,6 +10,9 @@
 # RUN: ld.lld %t1 -o %t -z noexecstack
 # RUN: llvm-readobj --program-headers -S %t | FileCheck --check-prefix=RW %s
 
+# RUN: ld.lld %t1 -o %t -z noexecstack
+# RUN: llvm-readobj --program-headers -S %t | FileCheck --check-prefix=NOGNUSTACK %s
+
 # RW:      Type: PT_GNU_STACK
 # RW-NEXT: Offset: 0x0
 # RW-NEXT: VirtualAddress: 0x0
@@ -35,5 +38,7 @@
 # RWX-NEXT: ]
 # RWX-NEXT: Alignment: 0
 
+# NOGNUSTACK-NOT: Type: PT_GNU_STACK
+
 .globl _start
 _start:
