$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/netdb.d.orig	2020-05-07 08:52:15.364683708 +0000
+++ runtime/druntime/src/core/sys/posix/netdb.d
@@ -488,6 +488,112 @@ else version( DragonFlyBSD )
     enum NI_NUMERICSCOPE    = 0x40;
 
 }
+else version( NetBSD )
+{
+    struct hostent
+    {
+        char*   h_name;
+        char**  h_aliases;
+        int     h_addrtype;
+        int     h_length;
+        char**  h_addr_list;
+        extern (D) char* h_addr() @property { return h_addr_list[0]; } // non-standard
+    }
+
+    struct netent
+    {
+        char*   n_name;
+        char**  n_aliases;
+        int     n_addrtype;
+        uint32_t n_net;
+/+ todo
+#if (defined(__sparc__) && defined(_LP64)) || \
+    (defined(__sh__) && defined(_LP64) && (_BYTE_ORDER == _BIG_ENDIAN))
+        int             __n_pad0;       /* ABI compatibility */
+#endif
+        uint32_t        n_net;          /*%< network # */
+#if defined(__alpha__) || (defined(__i386__) && defined(_LP64)) || \
+    (defined(__sh__) && defined(_LP64) && (_BYTE_ORDER == _LITTLE_ENDIAN))
+        int             __n_pad0;       /* ABI compatibility */
+#endif
++/
+    }
+
+    struct protoent
+    {
+        char*   p_name;
+        char**  p_aliases;
+        int     p_proto;
+    }
+
+    struct servent
+    {
+        char*   s_name;
+        char**  s_aliases;
+        int     s_port;
+        char*   s_proto;
+    }
+
+    enum IPPORT_RESERVED = 1024;
+
+    //h_errno
+
+    enum HOST_NOT_FOUND = 1;
+    enum NO_DATA        = 4;
+    enum NO_RECOVERY    = 3;
+    enum TRY_AGAIN      = 2;
+
+    struct addrinfo
+    {
+        int         ai_flags;
+        int         ai_family;
+        int         ai_socktype;
+        int         ai_protocol;
+/+todo
+#if defined(__sparc__) && defined(_LP64)
+        int             __ai_pad0;      /* ABI compatibility */
+#endif
++/
+        socklen_t   ai_addrlen;
+/+todo
+#if defined(__alpha__) || (defined(__i386__) && defined(_LP64))
+        int             __ai_pad0;      /* ABI compatibility */
+#endif
++/
+        char*       ai_canonname;
+        sockaddr*   ai_addr;
+        addrinfo*   ai_next;
+    }
+
+    enum AI_PASSIVE         = 0x1;
+    enum AI_CANONNAME       = 0x2;
+    enum AI_NUMERICHOST     = 0x4;
+    enum AI_NUMERICSERV     = 0x8;
+    enum AI_V4MAPPED        = 0x800;
+    enum AI_ALL             = 0x100;
+    enum AI_ADDRCONFIG      = 0x400;
+
+    enum NI_NOFQDN          = 0x1;
+    enum NI_NUMERICHOST     = 0x2;
+    enum NI_NAMEREQD        = 0x4;
+    enum NI_NUMERICSERV     = 0x8;
+    enum NI_DGRAM           = 0x10;
+    enum NI_WITHSCOPEID     = 0x00000020;
+    enum NI_NUMERICSCOPE    = 0x00000040;
+    enum NI_MAXHOST         = 1025; // non-standard
+    enum NI_MAXSERV         = 32;   // non-standard
+
+    enum EAI_AGAIN          = 2;
+    enum EAI_BADFLAGS       = 3;
+    enum EAI_FAIL           = 4;
+    enum EAI_FAMILY         = 5;
+    enum EAI_MEMORY         = 6;
+    enum EAI_NONAME         = 8;
+    enum EAI_SERVICE        = 9;
+    enum EAI_SOCKTYPE       = 10;
+    enum EAI_SYSTEM         = 11;
+    enum EAI_OVERFLOW       = 14;
+}
 else version (Solaris)
 {
     struct hostent
