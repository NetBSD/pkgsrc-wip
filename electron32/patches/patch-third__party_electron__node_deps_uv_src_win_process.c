$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/src/win/process.c.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/uv/src/win/process.c
@@ -105,6 +105,21 @@ static void uv__init_global_job_handle(v
                                &info,
                                sizeof info))
     uv_fatal_error(GetLastError(), "SetInformationJobObject");
+
+
+  if (!AssignProcessToJobObject(uv_global_job_handle_, GetCurrentProcess())) {
+    /* Make sure this handle is functional. The Windows kernel has a bug that
+     * if the first use of AssignProcessToJobObject is for a Windows Store
+     * program, subsequent attempts to use the handle with fail with
+     * INVALID_PARAMETER (87). This is possibly because all uses of the handle
+     * must be for the same Terminal Services session. We can ensure it is tied
+     * to our current session now by adding ourself to it. We could remove
+     * ourself afterwards, but there doesn't seem to be a reason to.
+     */
+    DWORD err = GetLastError();
+    if (err != ERROR_ACCESS_DENIED)
+      uv_fatal_error(err, "AssignProcessToJobObject");
+  }
 }
 
 
@@ -1102,6 +1117,7 @@ int uv_spawn(uv_loop_t* loop,
      * breakaway.
      */
     process_flags |= DETACHED_PROCESS | CREATE_NEW_PROCESS_GROUP;
+    process_flags |= CREATE_SUSPENDED;
   }
 
   if (!CreateProcessW(application_path,
@@ -1119,11 +1135,6 @@ int uv_spawn(uv_loop_t* loop,
     goto done;
   }
 
-  /* Spawn succeeded. Beyond this point, failure is reported asynchronously. */
-
-  process->process_handle = info.hProcess;
-  process->pid = info.dwProcessId;
-
   /* If the process isn't spawned as detached, assign to the global job object
    * so windows will kill it when the parent process dies. */
   if (!(options->flags & UV_PROCESS_DETACHED)) {
@@ -1146,6 +1157,19 @@ int uv_spawn(uv_loop_t* loop,
     }
   }
 
+  if (process_flags & CREATE_SUSPENDED) {
+    if (ResumeThread(info.hThread) == ((DWORD)-1)) {
+      err = GetLastError();
+      TerminateProcess(info.hProcess, 1);
+      goto done;
+    }
+  }
+
+  /* Spawn succeeded. Beyond this point, failure is reported asynchronously. */
+
+  process->process_handle = info.hProcess;
+  process->pid = info.dwProcessId;
+
   /* Set IPC pid to all IPC pipes. */
   for (i = 0; i < options->stdio_count; i++) {
     const uv_stdio_container_t* fdopt = &options->stdio[i];
