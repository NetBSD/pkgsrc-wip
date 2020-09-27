$NetBSD$

Fix for #725: luakit get stuck and start using all the CPU when closing the last
tab when window.close_with_last_tab setting is false.

From:

 <https://github.com/luakit/luakit/pull/862>

--- common/ipc.c.orig	2020-07-21 22:24:57.000000000 +0000
+++ common/ipc.c
@@ -21,6 +21,7 @@
 #include "common/lualib.h"
 #include "common/luaserialize.h"
 #include "common/ipc.h"
+#include "log.h"
 
 /* Prototypes for ipc_recv_... functions */
 #define X(name) void ipc_recv_##name(ipc_endpoint_t *ipc, const void *msg, guint length);
@@ -138,6 +139,8 @@ ipc_recv_and_dispatch_or_enqueue(ipc_end
         case G_IO_STATUS_AGAIN:
             return;
         case G_IO_STATUS_EOF:
+            verbose("g_io_channel_read_chars(): End Of File received");
+            g_atomic_int_dec_and_test(&ipc->refcount);
             return;
         case G_IO_STATUS_ERROR:
             if (!g_str_equal(ipc->name, "UI"))
