$NetBSD$

--- test/Driver/fsanitize.c.orig	2017-08-09 17:39:17.394187956 +0000
+++ test/Driver/fsanitize.c
@@ -516,6 +516,29 @@
 // RUN: %clang -target x86_64-unknown-cloudabi -fsanitize=safe-stack %s -### 2>&1 | FileCheck %s -check-prefix=SAFESTACK-CLOUDABI
 // SAFESTACK-CLOUDABI: "-fsanitize=safe-stack"
 
+// RUN: %clang -target i386--netbsd -fsanitize=address %s -### 2>&1 | FileCheck %s -check-prefix=ADDRESS-NETBSD
+// RUN: %clang -target x86_64--netbsd -fsanitize=address %s -### 2>&1 | FileCheck %s -check-prefix=ADDRESS-NETBSD
+// ADDRESS-NETBSD: "-fsanitize=address"
+
+// RUN: %clang -target i386--netbsd -fsanitize=vptr %s -### 2>&1 | FileCheck %s -check-prefix=VPTR-NETBSD
+// RUN: %clang -target x86_64--netbsd -fsanitize=vptr %s -### 2>&1 | FileCheck %s -check-prefix=VPTR-NETBSD
+// VPTR-NETBSD: "-fsanitize=vptr"
+
+// RUN: %clang -target i386--netbsd -fsanitize=safe-stack %s -### 2>&1 | FileCheck %s -check-prefix=SAFESTACK-NETBSD
+// RUN: %clang -target x86_64--netbsd -fsanitize=safe-stack %s -### 2>&1 | FileCheck %s -check-prefix=SAFESTACK-NETBSD
+// SAFESTACK-NETBSD: "-fsanitize=safe-stack"
+
+// RUN: %clang -target i386--netbsd -fsanitize=function %s -### 2>&1 | FileCheck %s -check-prefix=FUNCTION-NETBSD
+// RUN: %clang -target x86_64--netbsd -fsanitize=function %s -### 2>&1 | FileCheck %s -check-prefix=FUNCTION-NETBSD
+// FUNCTION-NETBSD: "-fsanitize=function"
+
+// RUN: %clang -target i386--netbsd -fsanitize=leak %s -### 2>&1 | FileCheck %s -check-prefix=LEAK-NETBSD
+// RUN: %clang -target x86_64--netbsd -fsanitize=leak %s -### 2>&1 | FileCheck %s -check-prefix=LEAK-NETBSD
+// LEAK-NETBSD: "-fsanitize=leak"
+
+// RUN: %clang -target x86_64--netbsd -fsanitize=thread %s -### 2>&1 | FileCheck %s -check-prefix=THREAD-NETBSD
+// THREAD-NETBSD: "-fsanitize=thread"
+
 // RUN: %clang -target x86_64-scei-ps4 -fsanitize=function -fsanitize=undefined %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-FSAN-UBSAN-PS4
 // CHECK-FSAN-UBSAN-PS4: unsupported option '-fsanitize=function' for target 'x86_64-scei-ps4'
 // RUN: %clang -target x86_64-scei-ps4 -fsanitize=function %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-FSAN-PS4
