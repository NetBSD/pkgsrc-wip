$NetBSD$

--- gdb/gdbsupport/agent.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/gdbsupport/agent.c
@@ -155,6 +155,7 @@ gdb_connect_sync_socket (int pid)
       return -1;
     }
 
+  memset(&addr, 0, sizeof(addr));
   addr.sun_family = AF_UNIX;
 
   res = xsnprintf (addr.sun_path, UNIX_PATH_MAX, "%s", path);
