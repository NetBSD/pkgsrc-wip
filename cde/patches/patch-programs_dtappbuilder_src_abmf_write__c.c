$NetBSD: patch-programs_dtappbuilder_src_abmf_write__c.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtappbuilder/src/abmf/write_c.c.orig	2012-09-28 21:08:59.000000000 +0000
+++ programs/dtappbuilder/src/abmf/write_c.c
@@ -350,9 +350,9 @@ write_func_def_params(
 	va_list	va_params
 )
 {
-#if defined(__ppc) || defined(linux)  || defined(__OpenBSD__)
+#if defined(__ppc)
 #define va_start_params() __va_copy(params, va_params)
-#elif defined(__FreeBSD__)
+#elif defined(CSRG_BASED) || defined(linux)
 #define va_start_params() va_copy(params, va_params)
 #else
 #define va_start_params() (params = va_params)
