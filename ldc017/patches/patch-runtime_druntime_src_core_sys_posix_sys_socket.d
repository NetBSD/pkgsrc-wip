$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/socket.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/socket.d
@@ -1230,6 +1230,205 @@ else version( DragonFlyBSD )
     int     socketpair(int, int, int, ref int[2]);
 //  void    pfctlinput(int, struct sockaddr *);
 }
+else version( NetBSD )
+{
+    alias uint   socklen_t;
+    alias ubyte  sa_family_t;
+
+    struct sockaddr
+    {
+        ubyte       sa_len;
+        sa_family_t sa_family;
+        byte[14]    sa_data;
+    }
+
+    private
+    {
+        enum _SS_ALIGNSIZE  = long.sizeof;
+        enum _SS_MAXSIZE    = 128;
+        enum _SS_PAD1SIZE   = _SS_ALIGNSIZE - ubyte.sizeof - sa_family_t.sizeof;
+        enum _SS_PAD2SIZE   = _SS_MAXSIZE - ubyte.sizeof - sa_family_t.sizeof - _SS_PAD1SIZE - _SS_ALIGNSIZE;
+    }
+
+    struct sockaddr_storage
+    {
+         ubyte              ss_len;
+         sa_family_t        ss_family;
+         byte[_SS_PAD1SIZE] __ss_pad1;
+         long               __ss_align;
+         byte[_SS_PAD2SIZE] __ss_pad2;
+    }
+
+    struct msghdr
+    {
+        void*     msg_name;
+        socklen_t msg_namelen;
+        iovec*    msg_iov;
+        int       msg_iovlen;
+        void*     msg_control;
+        socklen_t msg_controllen;
+        int       msg_flags;
+    }
+
+    struct cmsghdr
+    {
+         socklen_t cmsg_len;
+         int       cmsg_level;
+         int       cmsg_type;
+    }
+
+    enum : uint
+    {
+        SCM_RIGHTS = 0x01
+    }
+
+    private // <machine/param.h>
+    {
+        enum _ALIGNBYTES = /+c_int+/ int.sizeof - 1;
+        extern (D) size_t _ALIGN( size_t p ) { return (p + _ALIGNBYTES) & ~_ALIGNBYTES; }
+    }
+
+    extern (D) ubyte* CMSG_DATA( cmsghdr* cmsg )
+    {
+        return cast(ubyte*) cmsg + _ALIGN( cmsghdr.sizeof );
+    }
+
+    extern (D) cmsghdr* CMSG_NXTHDR( msghdr* mhdr, cmsghdr* cmsg )
+    {
+        if( cmsg == null )
+        {
+           return CMSG_FIRSTHDR( mhdr );
+        }
+        else
+        {
+            if( cast(ubyte*) cmsg + _ALIGN( cmsg.cmsg_len ) + _ALIGN( cmsghdr.sizeof ) >
+                    cast(ubyte*) mhdr.msg_control + mhdr.msg_controllen )
+                return null;
+            else
+                return cast(cmsghdr*) (cast(ubyte*) cmsg + _ALIGN( cmsg.cmsg_len ));
+        }
+    }
+
+    extern (D) cmsghdr* CMSG_FIRSTHDR( msghdr* mhdr )
+    {
+        return mhdr.msg_controllen >= cmsghdr.sizeof ? cast(cmsghdr*) mhdr.msg_control : null;
+    }
+
+    struct linger
+    {
+        int l_onoff;
+        int l_linger;
+    }
+
+    enum
+    {
+        SOCK_DGRAM      = 2,
+        SOCK_RDM        = 4,
+        SOCK_SEQPACKET  = 5,
+        SOCK_STREAM     = 1
+    }
+
+    enum : uint
+    {
+        SOL_SOCKET      = 0xffff
+    }
+
+    enum : uint
+    {
+         SO_DEBUG        = 0x0001,          /* turn on debugging info recording */
+         SO_ACCEPTCONN   = 0x0002,          /* socket has had listen() */
+         SO_REUSEADDR    = 0x0004,          /* allow local address reuse */
+         SO_KEEPALIVE    = 0x0008,          /* keep connections alive */
+         SO_DONTROUTE    = 0x0010,          /* just use interface addresses */
+         SO_BROADCAST    = 0x0020,          /* permit sending of broadcast msgs */
+         SO_USELOOPBACK  = 0x0040,          /* bypass hardware when possible */
+         SO_LINGER       = 0x0080,          /* linger on close if data present */
+         SO_OOBINLINE    = 0x0100,          /* leave received OOB data in line */
+         SO_REUSEPORT    = 0x0200,          /* allow local address & port reuse */
+        /*      SO_OTIMESTAMP   0x0400          */
+         SO_NOSIGPIPE    = 0x0800,          /* no SIGPIPE from EPIPE */
+         SO_ACCEPTFILTER = 0x1000,          /* there is an accept filter */
+         SO_TIMESTAMP    = 0x2000,          /* timestamp received dgram traffic */
+
+        /*
+         * Additional options, not kept in so_options.
+         */
+         SO_SNDBUF       = 0x1001,          /* send buffer size */
+         SO_RCVBUF       = 0x1002,          /* receive buffer size */
+         SO_SNDLOWAT     = 0x1003,          /* send low-water mark */
+         SO_RCVLOWAT     = 0x1004,          /* receive low-water mark */
+        /* SO_OSNDTIMEO         0x1005 */
+        /* SO_ORCVTIMEO         0x1006 */
+         SO_ERROR        = 0x1007,          /* get error status and clear */
+         SO_TYPE         = 0x1008,          /* get socket type */
+         SO_OVERFLOWED   = 0x1009,          /* datagrams: return packets dropped */
+
+         SO_NOHEADER     = 0x100a,          /* user supplies no header to kernel;
+                                                 * kernel removes header and supplies
+                                                 * payload
+                                                 */
+         SO_SNDTIMEO     = 0x100b,          /* send timeout */
+         SO_RCVTIMEO     = 0x100c          /* receive timeout */
+
+    }
+
+    enum
+    {
+        SOMAXCONN       = 128
+    }
+
+    enum : uint
+    {
+         MSG_OOB         = 0x0001,          /* process out-of-band data */
+         MSG_PEEK        = 0x0002,          /* peek at incoming message */
+         MSG_DONTROUTE   = 0x0004,          /* send without using routing tables */
+         MSG_EOR         = 0x0008,          /* data completes record */
+         MSG_TRUNC       = 0x0010,          /* data discarded before delivery */
+         MSG_CTRUNC      = 0x0020,          /* control data lost before delivery */
+         MSG_WAITALL     = 0x0040,          /* wait for full request or error */
+         MSG_DONTWAIT    = 0x0080,          /* this message should be nonblocking */
+         MSG_BCAST       = 0x0100,          /* this message was rcvd using link-level brdcst */
+         MSG_MCAST       = 0x0200,          /* this message was rcvd using link-level mcast */
+         MSG_NOSIGNAL    = 0x0400          /* do not generate SIGPIPE on EOF */
+
+
+    }
+
+    enum
+    {
+        AF_APPLETALK    = 16,
+        AF_INET         = 2,
+        AF_IPX          = 23,
+        AF_UNIX         = 1,
+        AF_UNSPEC       = 0
+    }
+
+    enum
+    {
+        SHUT_RD = 0,
+        SHUT_WR = 1,
+        SHUT_RDWR = 2
+    }
+
+    int     accept(int, sockaddr*, socklen_t*);
+    int     bind(int, in sockaddr*, socklen_t);
+    int     connect(int, in sockaddr*, socklen_t);
+    int     getpeername(int, sockaddr*, socklen_t*);
+    int     getsockname(int, sockaddr*, socklen_t*);
+    int     getsockopt(int, int, int, void*, socklen_t*);
+    int     listen(int, int);
+    ssize_t recv(int, void*, size_t, int);
+    ssize_t recvfrom(int, void*, size_t, int, sockaddr*, socklen_t*);
+    ssize_t recvmsg(int, msghdr*, int);
+    ssize_t send(int, in void*, size_t, int);
+    ssize_t sendmsg(int, in msghdr*, int);
+    ssize_t sendto(int, in void*, size_t, int, in sockaddr*, socklen_t);
+    int     setsockopt(int, int, int, in void*, socklen_t);
+    int     shutdown(int, int);
+    int     socket(int, int, int);
+    int     sockatmark(int);
+    int     socketpair(int, int, int, ref int[2]);
+}
 else version (Solaris)
 {
     alias uint socklen_t;
@@ -1657,6 +1856,13 @@ else version( DragonFlyBSD )
         AF_INET6    = 28
     }
 }
+else version( NetBSD )
+{
+    enum
+    {
+        AF_INET6    = 24
+    }
+}
 else version (Solaris)
 {
     enum
@@ -1708,6 +1914,13 @@ else version( DragonFlyBSD )
 {
     enum
     {
+        SOCK_RAW    = 3
+    }
+}
+else version( NetBSD )
+{
+    enum
+    {
         SOCK_RAW    = 3
     }
 }
