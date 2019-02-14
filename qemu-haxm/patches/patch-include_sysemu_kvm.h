$NetBSD: patch-include_sysemu_kvm.h,v 1.1 2019/02/13 05:16:12 kamil Exp $

Fix debug build on NetBSD (without Linux-KVM).

--- include/sysemu/kvm.h.orig	2018-08-14 19:10:34.000000000 +0000
+++ include/sysemu/kvm.h
@@ -461,8 +461,16 @@ int kvm_vm_check_extension(KVMState *s, 
         kvm_vcpu_ioctl(cpu, KVM_ENABLE_CAP, &cap);                   \
     })
 
+#ifdef CONFIG_KVM
 uint32_t kvm_arch_get_supported_cpuid(KVMState *env, uint32_t function,
                                       uint32_t index, int reg);
+#else
+#define kvm_arch_get_supported_cpuid(a,b,c,d)                        \
+    ({                                                               \
+        abort();                                                     \
+        0;                                                           \
+    })
+#endif
 
 void kvm_set_sigmask_len(KVMState *s, unsigned int sigmask_len);
 
