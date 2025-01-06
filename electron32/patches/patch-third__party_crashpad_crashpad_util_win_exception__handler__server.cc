$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/crashpad/crashpad/util/win/exception_handler_server.cc.orig	2024-10-18 12:35:04.359648700 +0000
+++ third_party/crashpad/crashpad/util/win/exception_handler_server.cc
@@ -448,9 +448,16 @@ bool ExceptionHandlerServer::ServiceClie
     DWORD real_pid = 0;
     if (get_named_pipe_client_process_id(service_context.pipe(), &real_pid) &&
         message.registration.client_process_id != real_pid) {
+      // Electron: When both browser process and renderer process are connecting
+      // to the pipe, the API may return the PID of browser process as real_pid,
+      // which is different from the PID of renderer process.
+      //
+      // I don't understand why Chromium does not have this issue.
+#if 0
       LOG(ERROR) << "forged client pid, real pid: " << real_pid
                  << ", got: " << message.registration.client_process_id;
       return false;
+#endif
     }
   }
 
