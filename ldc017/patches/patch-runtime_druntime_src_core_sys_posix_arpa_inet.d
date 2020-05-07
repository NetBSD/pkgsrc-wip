$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/arpa/inet.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/arpa/inet.d
@@ -173,6 +173,32 @@ else version( Solaris )
     const(char)*    inet_ntop(int, in void*, char*, socklen_t);
     int             inet_pton(int, in char*, void*);
 }
+else version( NetBSD )
+{
+    alias uint16_t in_port_t;
+    alias uint32_t in_addr_t;
+
+    struct in_addr
+    {
+        in_addr_t s_addr;
+    }
+
+    enum INET_ADDRSTRLEN = 16;
+
+    @trusted pure
+    {
+    uint32_t htonl(uint32_t);
+    uint16_t htons(uint16_t);
+    uint32_t ntohl(uint32_t);
+    uint16_t ntohs(uint16_t);
+    }
+
+    in_addr_t       inet_addr(in char*);
+    char*           inet_ntoa(in_addr);
+    const(char)*    inet_ntop(int, in void*, char*, socklen_t);
+    int             inet_pton(int, in char*, void*);
+}
+
 else version( Solaris )
 {
     alias uint16_t in_port_t;
@@ -264,6 +290,10 @@ else version( DragonFlyBSD )
 {
     enum INET6_ADDRSTRLEN = 46;
 }
+else version ( NetBSD ) 
+{
+    enum INET6_ADDRSTRLEN = 46;
+}
 else version( Solaris )
 {
     enum INET6_ADDRSTRLEN = 46;
