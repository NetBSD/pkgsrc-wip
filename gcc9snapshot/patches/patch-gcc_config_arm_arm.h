$NetBSD: patch-gcc_config_arm_arm.h,v 1.1 2017/05/03 00:21:03 maya Exp $

driver-arm.o is only included for freebsd/arm and linux/arm, and
it is responsible for the definition of host_detect_local_cpu.

Without it, we get an undefined reference.

GCC bugzilla #77800

--- gcc/config/arm/arm.h.orig	2017-06-16 21:04:23.000000000 +0000
+++ gcc/config/arm/arm.h
@@ -2203,7 +2203,7 @@ extern const char *arm_target_thumb_only
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && (defined(__FreeBSD__) || defined(__linux__))
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define MCPU_MTUNE_NATIVE_FUNCTIONS			\
