$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/netinet/in_.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/netinet/in_.d
@@ -245,6 +245,42 @@ else version( DragonFlyBSD )
 
     //enum INET_ADDRSTRLEN       = 16;
 }
+else version( NetBSD )
+{
+
+    struct sockaddr_in
+    {
+        ubyte       sin_len;
+        sa_family_t sin_family;
+        in_port_t   sin_port;
+        in_addr     sin_addr;
+        ubyte[8]    sin_zero;
+    }
+
+    enum
+    {
+        IPPROTO_IP   = 0,
+        IPPROTO_ICMP = 1,
+        IPPROTO_IGMP = 2,
+        IPPROTO_GGP  = 3,
+        IPPROTO_TCP  = 6,
+        IPPROTO_PUP  = 12,
+        IPPROTO_UDP  = 17,
+        IPPROTO_IDP  = 22,
+        IPPROTO_ND   = 77,
+        IPPROTO_MAX  = 256
+    }
+
+    enum : uint
+    {
+        INADDR_ANY       = 0x00000000,
+        INADDR_BROADCAST = 0xffffffff,
+        INADDR_LOOPBACK  = 0x7f000001,
+        INADDR_NONE      = 0xffffffff
+    }
+
+    //enum INET_ADDRSTRLEN       = 16;
+}
 else version( Solaris )
 {
     struct sockaddr_in
@@ -895,6 +931,145 @@ else version( DragonFlyBSD )
                __IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_GLOBAL;
     }
 }
+else version( NetBSD )
+{
+    struct in6_addr
+    {
+        union
+        {
+            uint8_t[16] s6_addr;
+            uint16_t[8] s6_addr16;
+            uint32_t[4] s6_addr32;
+        }
+    }
+
+    struct sockaddr_in6
+    {
+        uint8_t     sin6_len;
+        sa_family_t sin6_family;
+        in_port_t   sin6_port;
+        uint32_t    sin6_flowinfo;
+        in6_addr    sin6_addr;
+        uint32_t    sin6_scope_id;
+    }
+
+    extern __gshared immutable in6_addr in6addr_any;
+    extern __gshared immutable in6_addr in6addr_loopback;
+
+    struct ipv6_mreq
+    {
+        in6_addr    ipv6mr_multiaddr;
+        uint        ipv6mr_interface;
+    }
+
+    enum : uint
+    {
+        IPPROTO_IPV6        = 41,
+
+        //INET6_ADDRSTRLEN    = 46,
+
+        IPV6_JOIN_GROUP     = 12,
+        IPV6_LEAVE_GROUP    = 13,
+        IPV6_MULTICAST_HOPS = 10,
+        IPV6_MULTICAST_IF   = 9,
+        IPV6_MULTICAST_LOOP = 11,
+        IPV6_UNICAST_HOPS   = 4,
+        IPV6_V6ONLY         = 27,
+    }
+
+    private enum
+    {
+        __IPV6_ADDR_SCOPE_NODELOCAL     = 0x01,
+        __IPV6_ADDR_SCOPE_INTFACELOCAL  = 0x01,
+        __IPV6_ADDR_SCOPE_LINKLOCAL     = 0x02,
+        __IPV6_ADDR_SCOPE_SITELOCAL     = 0x05,
+        __IPV6_ADDR_SCOPE_ORGLOCAL      = 0x08,
+        __IPV6_ADDR_SCOPE_GLOBAL        = 0x0e,
+    }
+
+    // macros
+    extern (D) int IN6_IS_ADDR_UNSPECIFIED( in in6_addr* a ) pure
+    {
+        return (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[0]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[4]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[8]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[12]) == 0);
+    }
+
+    extern (D) int IN6_IS_ADDR_LOOPBACK( in in6_addr* a ) pure
+    {
+        return (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[0]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[4]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[8]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[12]) == ntohl(1));
+    }
+
+    extern (D) int IN6_IS_ADDR_V4COMPAT( in in6_addr* a ) pure
+    {
+        return (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[0]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[4]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[8]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[12]) != 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[12]) != ntohl(1));
+    }
+
+    extern (D) int IN6_IS_ADDR_V4MAPPED( in in6_addr* a ) pure
+    {
+        return (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[0]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[4]) == 0) &&
+               (*cast(const uint32_t*) cast(const void*) (&a.s6_addr[8]) == ntohl(0x0000ffff));
+    }
+
+    extern (D) int IN6_IS_ADDR_LINKLOCAL( in in6_addr* a ) pure
+    {
+        return a.s6_addr[0] == 0xfe && (a.s6_addr[1] & 0xc0) == 0x80;
+    }
+
+    extern (D) int IN6_IS_ADDR_SITELOCAL( in in6_addr* a ) pure
+    {
+        return a.s6_addr[0] == 0xfe && (a.s6_addr[1] & 0xc0) == 0xc0;
+    }
+
+    extern (D) int IN6_IS_ADDR_MULTICAST( in in6_addr* a ) pure
+    {
+        return a.s6_addr[0] == 0xff;
+    }
+
+    extern (D) uint8_t __IPV6_ADDR_MC_SCOPE( in in6_addr* a ) pure
+    {
+        return a.s6_addr[1] & 0x0f;
+    }
+
+    extern (D) int IN6_IS_ADDR_MC_NODELOCAL( in in6_addr* a ) pure
+    {
+        return IN6_IS_ADDR_MULTICAST(a) &&
+               __IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_NODELOCAL;
+    }
+
+    extern (D) int IN6_IS_ADDR_MC_LINKLOCAL( in in6_addr* a ) pure
+    {
+        return IN6_IS_ADDR_MULTICAST(a) &&
+               __IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_LINKLOCAL;
+    }
+
+    extern (D) int IN6_IS_ADDR_MC_SITELOCAL( in in6_addr* a ) pure
+    {
+        return IN6_IS_ADDR_MULTICAST(a) &&
+               __IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_SITELOCAL;
+    }
+
+    extern (D) int IN6_IS_ADDR_MC_ORGLOCAL( in in6_addr* a ) pure
+    {
+        return IN6_IS_ADDR_MULTICAST(a) &&
+               __IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_ORGLOCAL;
+    }
+
+    extern (D) int IN6_IS_ADDR_MC_GLOBAL( in in6_addr* a ) pure
+    {
+        return IN6_IS_ADDR_MULTICAST(a) &&
+               __IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_GLOBAL;
+    }
+}
 else version( Solaris )
 {
     struct in6_addr
@@ -1175,6 +1350,10 @@ else version( DragonFlyBSD )
 {
     enum uint IPPROTO_RAW = 255;
 }
+else version ( NetBSD )
+{
+    enum uint IPPROTO_RAW = 255;
+}
 else version( Solaris )
 {
     enum uint IPPROTO_RAW = 255;
