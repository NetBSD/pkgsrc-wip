$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/socket.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/socket.d
@@ -927,6 +927,126 @@ else version( FreeBSD )
     int     sockatmark(int);
     int     socketpair(int, int, int, ref int[2]);
 }
+else version( NetBSD )
+{
+    alias uint socklen_t;
+    alias ubyte sa_family_t;
+
+    struct sockaddr {
+     	ubyte	        sa_len;		/* total length */
+     	sa_family_t	sa_family;	/* address family */
+     	char[14]	sa_data;	/* actually longer; address value */
+    }
+    enum
+    {
+        _SS_MAXSIZE   = 128,
+        _SS_ALIGNSIZE = long.sizeof,
+        _SS_PAD1SIZE  = _SS_ALIGNSIZE - 2,
+        _SS_PAD2SIZE  = _SS_MAXSIZE - 2 - _SS_PAD1SIZE - _SS_ALIGNSIZE,
+    }
+    struct sockaddr_storage {
+ 	ubyte	        ss_len;		/* address length */
+ 	sa_family_t	ss_family;	/* address family */
+ 	char[_SS_PAD1SIZE]	__ss_pad1;
+ 	long            __ss_align;/* force desired structure storage alignment */
+ 	char[_SS_PAD2SIZE]	__ss_pad2;
+    }
+
+    struct msghdr {
+ 	void*		msg_name;	/* optional address */
+ 	socklen_t	msg_namelen;	/* size of address */
+ 	iovec*	        msg_iov;	/* scatter/gather array */
+ 	int		msg_iovlen;	/* # elements in msg_iov */
+ 	void*		msg_control;	/* ancillary data, see below */
+ 	socklen_t	msg_controllen;	/* ancillary data buffer len */
+ 	int		msg_flags;	/* flags on received message */
+    }
+
+    struct cmsghdr {
+ 	socklen_t	cmsg_len;	/* data byte count, including hdr */
+ 	int		cmsg_level;	/* originating protocol */
+ 	int		cmsg_type;	/* protocol-specific type */
+ /* followed by	u_char  cmsg_data[]; */
+    }
+    //
+// Required
+//
+/*
+struct iovec {} // from core.sys.posix.sys.uio
+
+SCM_RIGHTS
+
+CMSG_DATA(cmsg)
+CMSG_NXTHDR(mhdr,cmsg)
+CMSG_FIRSTHDR(mhdr)
+
+struct linger
+{
+    int l_onoff;
+    int l_linger;
+}
+
+SOCK_DGRAM
+SOCK_SEQPACKET
+SOCK_STREAM
+
+SOL_SOCKET
+
+SO_ACCEPTCONN
+SO_BROADCAST
+SO_DEBUG
+SO_DONTROUTE
+SO_ERROR
+SO_KEEPALIVE
+SO_LINGER
+SO_OOBINLINE
+SO_RCVBUF
+SO_RCVLOWAT
+SO_RCVTIMEO
+SO_REUSEADDR
+SO_SNDBUF
+SO_SNDLOWAT
+SO_SNDTIMEO
+SO_TYPE
+
+SOMAXCONN
+
+MSG_CTRUNC
+MSG_DONTROUTE
+MSG_EOR
+MSG_OOB
+MSG_PEEK
+MSG_TRUNC
+MSG_WAITALL
+
+AF_INET
+AF_UNIX
+AF_UNSPEC
+
+SHUT_RD
+SHUT_RDWR
+SHUT_WR
+
+int     accept(int, sockaddr*, socklen_t*);
+int     bind(int, in sockaddr*, socklen_t);
+int     connect(int, in sockaddr*, socklen_t);
+int     getpeername(int, sockaddr*, socklen_t*);
+int     getsockname(int, sockaddr*, socklen_t*);
+int     getsockopt(int, int, int, void*, socklen_t*);
+int     listen(int, int);
+ssize_t recv(int, void*, size_t, int);
+ssize_t recvfrom(int, void*, size_t, int, sockaddr*, socklen_t*);
+ssize_t recvmsg(int, msghdr*, int);
+ssize_t send(int, in void*, size_t, int);
+ssize_t sendmsg(int, in msghdr*, int);
+ssize_t sendto(int, in void*, size_t, int, in sockaddr*, socklen_t);
+int     setsockopt(int, int, int, in void*, socklen_t);
+int     shutdown(int, int);
+int     socket(int, int, int);
+int     sockatmark(int);
+int     socketpair(int, int, int, ref int[2]);
+*/
+}
 else version (Solaris)
 {
     alias uint socklen_t;
@@ -1311,6 +1431,13 @@ else version( FreeBSD )
         AF_INET6    = 28
     }
 }
+else version( NetBSD )
+{
+    enum
+    {
+        AF_INET6 = 24,
+    }
+}
 else version (Solaris)
 {
     enum
@@ -1358,6 +1485,13 @@ else version( FreeBSD )
         SOCK_RAW    = 3
     }
 }
+else version( NetBSD )
+{
+    enum
+    {
+        SOCK_RAW = 3
+    }
+}
 else version (Solaris)
 {
     enum
