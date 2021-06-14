$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_os__bsd__aarch64.cpp,v 1.1 2019/12/04 12:19:25 tnn Exp $

NetBSD/evbarm-aarch64 support

--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp	2021-06-10 13:21:44.742107421 -0400
@@ -104,6 +104,8 @@
   return (address)uc->uc_mcontext.mc_gpregs.gp_elr;
 #elif defined(__OpenBSD__)
   return (address)uc->sc_elr;
+#elif defined(__NetBSD__)
+  return (address)uc->uc_mcontext.__gregs[_REG_ELR];
 #endif
 }
 
@@ -112,6 +114,8 @@
   uc->uc_mcontext.mc_gpregs.gp_elr = (intptr_t)pc;
 #elif defined(__OpenBSD__)
   uc->sc_elr = (unsigned long)pc;
+#elif defined(__NetBSD__)
+  uc->uc_mcontext.__gregs[_REG_ELR] = (__greg_t)pc;
 #endif
 }
 
@@ -120,6 +124,8 @@
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_sp;
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_sp;
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_SP];
 #endif
 }
 
@@ -128,6 +134,8 @@
   return (intptr_t*)uc->uc_mcontext.mc_gpregs.gp_x[REG_FP];
 #elif defined(__OpenBSD__)
   return (intptr_t*)uc->sc_x[REG_FP];
+#elif defined(__NetBSD__)
+  return (intptr_t*)uc->uc_mcontext.__gregs[_REG_FP];
 #endif
 }
 
@@ -170,6 +178,9 @@
 #elif defined(__OpenBSD__)
       address pc = (address)(uc->sc_lr
                          - NativeInstruction::instruction_size);
+#elif defined(__NetBSD__)
+      address pc = (address)(uc->uc_mcontext.__gregs[_REG_LR]
+                         - NativeInstruction::instruction_size);
 #endif
   return frame(sp, fp, pc);
 }
@@ -402,6 +413,8 @@
     print_location(st, uc->uc_mcontext.mc_gpregs.gp_x[r]);
 #elif defined(__OpenBSD__)
     print_location(st, uc->sc_x[r]);
+#elif defined(__NetBSD__)
+    print_location(st, uc->uc_mcontext.__gregs[r]);
 #endif
   }
   st->cr();
@@ -438,6 +451,8 @@
     st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->uc_mcontext.mc_gpregs.gp_x[r]);
 #elif defined(__OpenBSD__)
     st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->sc_x[r]);
+#elif defined(__NetBSD__)
+    st->print_cr(  "R%d=" INTPTR_FORMAT, r, (uintptr_t)uc->uc_mcontext.__gregs[r]);
 #endif
   st->cr();
 }
