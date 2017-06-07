$NetBSD$

Use the Linux frontend on BSD since the BSD frontend is incomplete.

--- frontend/frontend_driver.c.orig	2017-05-31 23:25:41.000000000 +0000
+++ frontend/frontend_driver.c
@@ -46,12 +46,9 @@ static frontend_ctx_driver_t *frontend_c
 #if defined(__APPLE__) && defined(__MACH__)
    &frontend_ctx_darwin,
 #endif
-#if defined(__linux__)
+#if defined(__linux__) || (defined(BSD) && !defined(__MACH__))
    &frontend_ctx_linux,
 #endif
-#if defined(BSD) && !defined(__MACH__)
-   &frontend_ctx_bsd,
-#endif
 #if defined(PSP) || defined(VITA)
    &frontend_ctx_psp,
 #endif
