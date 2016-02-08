$NetBSD$

--- src/Native/System.Native/pal_errno.cpp.orig	2016-02-07 13:49:29.000000000 +0000
+++ src/Native/System.Native/pal_errno.cpp
@@ -126,8 +126,10 @@ extern "C" Error SystemNative_ConvertErr
             return PAL_ENOTDIR;
         case ENOTEMPTY:
             return PAL_ENOTEMPTY;
+#if HAVE_ENOTRECOVERABLE
         case ENOTRECOVERABLE:
             return PAL_ENOTRECOVERABLE;
+#endif
         case ENOTSOCK:
             return PAL_ENOTSOCK;
         case ENOTSUP:
@@ -138,8 +140,10 @@ extern "C" Error SystemNative_ConvertErr
             return PAL_ENXIO;
         case EOVERFLOW:
             return PAL_EOVERFLOW;
+#if HAVE_EOWNERDEAD
         case EOWNERDEAD:
             return PAL_EOWNERDEAD;
+#endif
         case EPERM:
             return PAL_EPERM;
         case EPIPE:
@@ -299,7 +303,11 @@ extern "C" int32_t SystemNative_ConvertE
         case PAL_ENOTEMPTY:
             return ENOTEMPTY;
         case PAL_ENOTRECOVERABLE:
+#if HAVE_ENOTRECOVERABLE
             return ENOTRECOVERABLE;
+#else
+            return -1;
+#endif
         case PAL_ENOTSOCK:
             return ENOTSOCK;
         case PAL_ENOTSUP:
@@ -311,7 +319,11 @@ extern "C" int32_t SystemNative_ConvertE
         case PAL_EOVERFLOW:
             return EOVERFLOW;
         case PAL_EOWNERDEAD:
+#if HAVE_EOWNERDEAD
             return EOWNERDEAD;
+#else
+            return -1;
+#endif
         case PAL_EPERM:
             return EPERM;
         case PAL_EPIPE:
