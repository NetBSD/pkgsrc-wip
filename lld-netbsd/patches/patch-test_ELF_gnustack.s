$NetBSD$

--- test/ELF/gnustack.s.orig	2019-03-14 17:33:28.000000000 +0000
+++ test/ELF/gnustack.s
@@ -10,6 +10,9 @@
 # RUN: ld.lld %t1 -o %t -z noexecstack
 # RUN: llvm-readobj --program-headers -s %t | FileCheck --check-prefix=RW %s
 
+# RUN: ld.lld %t1 -o %t -z nognustack
+# RUN: llvm-readobj --program-headers -s %t | FileCheck --check-prefix=NOGNUSTACK %s
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
