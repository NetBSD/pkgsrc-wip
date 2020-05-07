$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/net/if_.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/net/if_.d
@@ -82,6 +82,21 @@ else version( FreeBSD )
     if_nameindex_t* if_nameindex();
     void            if_freenameindex(if_nameindex_t*);
 }
+else version( NetBSD )
+{
+    struct if_nameindex_t
+    {
+        uint    if_index;
+        char*   if_name;
+    }
+
+    enum IF_NAMESIZE = 16;
+
+    uint            if_nametoindex(in char*);
+    char*           if_indextoname(uint, char*);
+    if_nameindex_t* if_nameindex();
+    void            if_freenameindex(if_nameindex_t*);
+}
 else version( CRuntime_Bionic )
 {
     enum IF_NAMESIZE = 16;
