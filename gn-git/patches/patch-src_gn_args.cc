$NetBSD$

- Handle NetBSD/evbarm correctly.

--- src/gn/args.cc.orig	2025-05-05 14:41:37.597099905 +0000
+++ src/gn/args.cc
@@ -360,6 +360,10 @@ void Args::SetSystemVarsLocked(Scope* de
     arch = kX86;
   else if (os_arch == "x86_64")
     arch = kX64;
+  else if (os_arch == "evbarm" && sizeof(long) == 8)
+    arch = kArm64;
+  else if (os_arch == "evbarm" && sizeof(long) == 4)
+    arch = kArm;
   else if (os_arch == "aarch64" || os_arch == "arm64")
     arch = kArm64;
   else if (os_arch.substr(0, 3) == "arm")
