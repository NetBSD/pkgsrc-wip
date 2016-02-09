$NetBSD$

--- src/Native/System.Native/pal_errno.cpp.orig	2016-02-07 13:49:29.000000000 +0000
+++ src/Native/System.Native/pal_errno.cpp
@@ -126,8 +126,10 @@ extern "C" Error SystemNative_ConvertErr
             return PAL_ENOTDIR;
         case ENOTEMPTY:
             return PAL_ENOTEMPTY;
+#ifdef ENOTRECOVERABLE
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
+#ifdef EOWNERDEAD
         case EOWNERDEAD:
             return PAL_EOWNERDEAD;
+#endif
         case EPERM:
             return PAL_EPERM;
         case EPIPE:
@@ -298,8 +302,10 @@ extern "C" int32_t SystemNative_ConvertE
             return ENOTDIR;
         case PAL_ENOTEMPTY:
             return ENOTEMPTY;
+#ifdef ENOTRECOVERABLE
         case PAL_ENOTRECOVERABLE:
             return ENOTRECOVERABLE;
+#endif
         case PAL_ENOTSOCK:
             return ENOTSOCK;
         case PAL_ENOTSUP:
@@ -310,8 +316,10 @@ extern "C" int32_t SystemNative_ConvertE
             return ENXIO;
         case PAL_EOVERFLOW:
             return EOVERFLOW;
+#ifdef EOWNERDEAD
         case PAL_EOWNERDEAD:
             return EOWNERDEAD;
+#endif
         case PAL_EPERM:
             return EPERM;
         case PAL_EPIPE:
