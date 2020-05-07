$NetBSD$

--- runtime/druntime/src/core/stdc/errno.d.orig	2020-05-07 08:52:13.684688490 +0000
+++ runtime/druntime/src/core/stdc/errno.d
@@ -1414,6 +1414,138 @@ else version( DragonFlyBSD )
     enum EASYNC             = 99;
     enum ELAST              = 99;
 }
+else version (NetBSD)
+{
+    enum EPERM           = 1               /** Operation not permitted */;
+    enum ENOENT          = 2               /** No such file or directory */;
+    enum ESRCH           = 3               /** No such process */;
+    enum EINTR           = 4               /** Interrupted system call */;
+    enum EIO             = 5               /** Input/output error */;
+    enum ENXIO           = 6               /** Device not configured */;
+    enum E2BIG           = 7               /** Argument list too long */;
+    enum ENOEXEC         = 8               /** Exec format error */;
+    enum EBADF           = 9               /** Bad file descriptor */;
+    enum ECHILD          = 10              /** No child processes */;
+    enum EDEADLK         = 11              /** Resource deadlock avoided */;
+    /* 11 was EAGAIN */
+    enum ENOMEM          = 12              /** Cannot allocate memory */;
+    enum EACCES          = 13              /** Permission denied */;
+    enum EFAULT          = 14              /** Bad address */;
+    enum ENOTBLK         = 15              /** Block device required */;
+    enum EBUSY           = 16              /** Device busy */;
+    enum EEXIST          = 17              /** File exists */;
+    enum EXDEV           = 18              /** Cross-device link */;
+    enum ENODEV          = 19              /** Operation not supported by device */;
+    enum ENOTDIR         = 20              /** Not a directory */;
+    enum EISDIR          = 21              /** Is a directory */;
+    enum EINVAL          = 22              /** Invalid argument */;
+    enum ENFILE          = 23              /** Too many open files in system */;
+    enum EMFILE          = 24              /** Too many open files */;
+    enum ENOTTY          = 25              /** Inappropriate ioctl for device */;
+    enum ETXTBSY         = 26              /** Text file busy */;
+    enum EFBIG           = 27              /** File too large */;
+    enum ENOSPC          = 28              /** No space left on device */;
+    enum ESPIPE          = 29              /** Illegal seek */;
+    enum EROFS           = 30              /** Read-only file system */;
+    enum EMLINK          = 31              /** Too many links */;
+    enum EPIPE           = 32              /** Broken pipe */;
+    /* math software */
+    enum EDOM            = 33              /** Numerical argument out of domain */;
+    enum ERANGE          = 34              /** Result too large or too small */;
+
+    /* non-blocking and interrupt i/o */
+    enum EAGAIN          = 35              /** Resource temporarily unavailable */;
+    enum EWOULDBLOCK     = EAGAIN          /** Operation would block */;
+    enum EINPROGRESS     = 36              /** Operation now in progress */;
+    enum EALREADY        = 37              /** Operation already in progress */;
+
+    /* ipc/network software -- argument errors */
+    enum ENOTSOCK        = 38              /** Socket operation on non-socket */;
+    enum EDESTADDRREQ    = 39              /** Destination address required */;
+    enum EMSGSIZE        = 40              /** Message too long */;
+    enum EPROTOTYPE      = 41              /** Protocol wrong type for socket */;
+    enum ENOPROTOOPT     = 42              /** Protocol option not available */;
+    enum EPROTONOSUPPORT = 43              /** Protocol not supported */;
+    enum ESOCKTNOSUPPORT = 44              /** Socket type not supported */;
+    enum EOPNOTSUPP      = 45              /** Operation not supported */;
+    enum EPFNOSUPPORT    = 46              /** Protocol family not supported */;
+    enum EAFNOSUPPORT    = 47              /** Address family not supported by protocol family */;
+    enum EADDRINUSE      = 48              /** Address already in use */;
+    enum EADDRNOTAVAIL   = 49              /** Can't assign requested address */;
+
+    /* ipc/network software -- operational errors */
+    enum ENETDOWN        = 50              /** Network is down */;
+    enum ENETUNREACH     = 51              /** Network is unreachable */;
+    enum ENETRESET       = 52              /** Network dropped connection on reset */;
+    enum ECONNABORTED    = 53              /** Software caused connection abort */;
+    enum ECONNRESET      = 54              /** Connection reset by peer */;
+    enum ENOBUFS         = 55              /** No buffer space available */;
+    enum EISCONN         = 56              /** Socket is already connected */;
+    enum ENOTCONN        = 57              /** Socket is not connected */;
+    enum ESHUTDOWN       = 58              /** Can't send after socket shutdown */;
+    enum ETOOMANYREFS    = 59              /** Too many references: can't splice */;
+    enum ETIMEDOUT       = 60              /** Operation timed out */;
+    enum ECONNREFUSED    = 61              /** Connection refused */;
+    enum ELOOP           = 62              /** Too many levels of symbolic links */;
+    enum ENAMETOOLONG    = 63              /** File name too long */;
+
+    /* should be rearranged */
+    enum EHOSTDOWN       = 64              /** Host is down */;
+    enum EHOSTUNREACH    = 65              /** No route to host */;
+    enum ENOTEMPTY       = 66              /** Directory not empty */;
+
+    /* quotas & mush */
+    enum EPROCLIM        = 67              /** Too many processes */;
+    enum EUSERS          = 68              /** Too many users */;
+    enum EDQUOT          = 69              /** Disc quota exceeded */;
+
+    /* Network File System */
+    enum ESTALE          = 70              /** Stale NFS file handle */;
+    enum EREMOTE         = 71              /** Too many levels of remote in path */;
+    enum EBADRPC         = 72              /** RPC struct is bad */;
+    enum ERPCMISMATCH    = 73              /** RPC version wrong */;
+    enum EPROGUNAVAIL    = 74              /** RPC prog. not avail */;
+    enum EPROGMISMATCH   = 75              /** Program version wrong */;
+    enum EPROCUNAVAIL    = 76              /** Bad procedure for program */;
+
+    enum ENOLCK          = 77              /** No locks available */;
+    enum ENOSYS          = 78              /** Function not implemented */;
+
+    enum EFTYPE          = 79              /** Inappropriate file type or format */;
+    enum EAUTH           = 80              /** Authentication error */;
+    enum ENEEDAUTH       = 81              /** Need authenticator */;
+
+    /* SystemV IPC */
+    enum EIDRM           = 82              /** Identifier removed */;
+    enum ENOMSG          = 83              /** No message of desired type */;
+    enum EOVERFLOW       = 84              /** Value too large to be stored in data type */;
+    /* Wide/multibyte-character handling, ISO/IEC 9899/AMD1:1995 */
+    enum EILSEQ          = 85              /** Illegal byte sequence */;
+
+    /* From IEEE Std 1003.1-2001 */
+    /* Base, Realtime, Threads or Thread Priority Scheduling option errors */
+    enum ENOTSUP         = 86              /** Not supported */;
+
+    /* Realtime option errors */
+    enum ECANCELED       = 87              /** Operation canceled */;
+
+    /* Realtime, XSI STREAMS option errors */
+    enum EBADMSG         = 88              /** Bad or Corrupt message */;
+
+    /* XSI STREAMS option errors  */
+    enum ENODATA         = 89              /** No message available */;
+    enum ENOSR           = 90              /** No STREAM resources */;
+    enum ENOSTR          = 91              /** Not a STREAM */;
+    enum ETIME           = 92              /** STREAM ioctl timeout */;
+
+    /* File system extended attribute errors */
+    enum ENOATTR         = 93              /** Attribute not found */;
+
+    /* Realtime, XSI STREAMS option errors */
+    enum EMULTIHOP       = 94              /** Multihop attempted */;
+    enum ENOLINK         = 95              /** Link has been severed */;
+    enum EPROTO          = 96              /** Protocol error */;
+}
 else version (Solaris)
 {
     enum EPERM =  1       /** Not super-user                       */;
