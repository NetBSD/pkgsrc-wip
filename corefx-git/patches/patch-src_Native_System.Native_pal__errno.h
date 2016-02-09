$NetBSD$

--- src/Native/System.Native/pal_errno.h.orig	2016-02-07 13:49:29.000000000 +0000
+++ src/Native/System.Native/pal_errno.h
@@ -84,13 +84,17 @@ enum Error : int32_t
     PAL_ENOTCONN = 0x10038,        // The socket is not connected.
     PAL_ENOTDIR = 0x10039,         // Not a directory or a symbolic link to a directory.
     PAL_ENOTEMPTY = 0x1003A,       // Directory not empty.
+#ifdef ENOTRECOVERABLE
     PAL_ENOTRECOVERABLE = 0x1003B, // State not recoverable.
+#endif
     PAL_ENOTSOCK = 0x1003C,        // Not a socket.
     PAL_ENOTSUP = 0x1003D,         // Not supported (same value as EOPNOTSUP).
     PAL_ENOTTY = 0x1003E,          // Inappropriate I/O control operation.
     PAL_ENXIO = 0x1003F,           // No such device or address.
     PAL_EOVERFLOW = 0x10040,       // Value too large to be stored in data type.
+#ifdef EOWNERDEAD
     PAL_EOWNERDEAD = 0x10041,      // Previous owner died.
+#endif
     PAL_EPERM = 0x10042,           // Operation not permitted.
     PAL_EPIPE = 0x10043,           // Broken pipe.
     PAL_EPROTO = 0x10044,          // Protocol error.
