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
@@ -339,20 +347,19 @@ extern "C" int32_t SystemNative_ConvertE
         case PAL_EXDEV:
             return EXDEV;
         case PAL_ENONSTANDARD:
-            break; // fall through to assert
+        default:
+            // We should not use this function to round-trip platform -> pal
+            // -> platform. It's here only to synthesize a platform number
+            // from the fixed set above. Note that the assert is outside the
+            // switch rather than in a default case block because not
+            // having a default will trigger a warning (as error) if there's
+            // an enum value we haven't handled. Should that trigger, make
+            // note that there is probably a corresponding missing case in the
+            // other direction above, but the compiler can't warn in that case
+            // because the platform values are not part of an enum.
+            assert(false && "Unknown error code");
+            return -1;
     }
-
-    // We should not use this function to round-trip platform -> pal
-    // -> platform. It's here only to synthesize a platform number
-    // from the fixed set above. Note that the assert is outside the
-    // switch rather than in a default case block because not
-    // having a default will trigger a warning (as error) if there's
-    // an enum value we haven't handled. Should that trigger, make
-    // note that there is probably a corresponding missing case in the
-    // other direction above, but the compiler can't warn in that case
-    // because the platform values are not part of an enum.
-    assert(false && "Unknown error code");
-    return -1;
 }
 
 extern "C" const char* SystemNative_StrErrorR(int32_t platformErrno, char* buffer, int32_t bufferSize)
