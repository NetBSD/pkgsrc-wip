$NetBSD$

From FreeBSD ports devel/dbus.

Added Mon May 10 21:19:08 2010 UTC

Presenting GNOME 2.30.1 for FreeBSD.

--- dbus/dbus-connection.c.orig	2018-02-08 14:07:21.000000000 +0000
+++ dbus/dbus-connection.c
@@ -2385,7 +2385,11 @@ _dbus_connection_block_pending_call (DBu
   DBusConnection *connection;
   dbus_uint32_t client_serial;
   DBusTimeout *timeout;
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+  int timeout_milliseconds, elapsed_milliseconds, remain_milliseconds;
+#else
   int timeout_milliseconds, elapsed_milliseconds;
+#endif
 
   _dbus_assert (pending != NULL);
 
@@ -2467,6 +2471,12 @@ _dbus_connection_block_pending_call (DBu
   elapsed_milliseconds = (tv_sec - start_tv_sec) * 1000 +
 	  (tv_usec - start_tv_usec) / 1000;
   
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+  if (timeout_milliseconds != -1)
+    remain_milliseconds = timeout_milliseconds - elapsed_milliseconds;
+  else
+    remain_milliseconds = -1;
+#endif
   if (!_dbus_connection_get_is_connected_unlocked (connection))
     {
       DBusMessage *error_msg;
@@ -2494,7 +2504,11 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
+#else
           _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+#endif
         }
       else
         {          
@@ -2503,7 +2517,11 @@ _dbus_connection_block_pending_call (DBu
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+                                                  remain_milliseconds);
+#else
                                                   timeout_milliseconds - elapsed_milliseconds);
+#endif
         }
 
       goto recheck_status;
@@ -2512,7 +2530,11 @@ _dbus_connection_block_pending_call (DBu
     _dbus_verbose ("dbus_connection_send_with_reply_and_block(): clock set backward\n");
   else if (elapsed_milliseconds < timeout_milliseconds)
     {
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+      _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", remain_milliseconds);
+#else
       _dbus_verbose ("dbus_connection_send_with_reply_and_block(): %d milliseconds remain\n", timeout_milliseconds - elapsed_milliseconds);
+#endif
       
       if (status == DBUS_DISPATCH_NEED_MEMORY)
         {
@@ -2522,7 +2544,11 @@ _dbus_connection_block_pending_call (DBu
            */
           _dbus_verbose ("dbus_connection_send_with_reply_and_block() waiting for more memory\n");
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+          _dbus_memory_pause_based_on_timeout (remain_milliseconds);
+#else
           _dbus_memory_pause_based_on_timeout (timeout_milliseconds - elapsed_milliseconds);
+#endif
         }
       else
         {          
@@ -2531,7 +2557,11 @@ _dbus_connection_block_pending_call (DBu
                                                   pending,
                                                   DBUS_ITERATION_DO_READING |
                                                   DBUS_ITERATION_BLOCK,
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+                                                  remain_milliseconds);
+#else
                                                   timeout_milliseconds - elapsed_milliseconds);
+#endif
         }
 
       goto recheck_status;
