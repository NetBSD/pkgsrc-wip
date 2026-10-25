$NetBSD$

* Add support to NetBSD and FreeBSD

--- os-proxy-resolver/src/platform/linux.rs.orig	2026-10-24 15:44:13.935143969 +0000
+++ os-proxy-resolver/src/platform/linux.rs
@@ -216,9 +216,23 @@ fn configure_watcher_command(command: &m
     // operations only invoke async-signal-safe Linux system calls.
     unsafe {
         command.pre_exec(move || {
+            #[cfg(target_os = "linux")]
             if libc::prctl(libc::PR_SET_PDEATHSIG, libc::SIGKILL) == -1 {
                 return Err(std::io::Error::last_os_error());
             }
+            #[cfg(target_os = "freebsd")]
+            {
+                let mut sig = libc::SIGKILL;
+                let ret = libc::procctl(
+                    libc::P_PID,
+                    0,
+                    libc::PROC_PDEATHSIG_CTL,
+                    &mut sig as *mut libc::c_int as *mut libc::c_void,
+                );
+                if ret == -1 {
+                    return Err(std::io::Error::last_os_error());
+                }
+            }
             // The parent may have exited between fork and PR_SET_PDEATHSIG.
             if libc::getppid() != expected_parent {
                 libc::_exit(1);
@@ -247,13 +261,23 @@ fn mark_file_descriptors_close_on_exec(
     // succeeds while preventing every non-stdio descriptor from reaching the
     // watcher program.
     // SAFETY: close_range operates on the calling process's descriptor table.
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     loop {
+       #[cfg(target_os = "linux")]
         let result = unsafe {
             libc::syscall(
                 libc::SYS_close_range,
                 3 as libc::c_uint,
                 libc::c_uint::MAX,
                 libc::CLOSE_RANGE_CLOEXEC,
+            ) as libc::c_int
+        };
+        #[cfg(target_os = "freebsd")]
+        let result = unsafe {
+            libc::close_range(
+                3 as libc::c_uint,
+                libc::c_uint::MAX,
+                libc::CLOSE_RANGE_CLOEXEC as libc::c_int,
             )
         };
         if result == 0 {
@@ -266,7 +290,19 @@ fn mark_file_descriptors_close_on_exec(
 
     // Older kernels and restricted seccomp profiles may not support
     // close_range. fcntl is slower but provides equivalent behavior.
+    #[cfg(target_os = "netbsd")]
+    let file_descriptor_limit = {
+        // SAFETY: F_MAXFD only queries the descriptor table.
+        let max_fd = unsafe { libc::fcntl(0, libc::F_MAXFD) };
+        if max_fd >= 0 {
+            max_fd + 1
+        } else {
+            file_descriptor_limit.map_err(io::Error::from_raw_os_error)?
+        }
+    };
+    #[cfg(not(target_os = "netbsd"))]
     let file_descriptor_limit = file_descriptor_limit.map_err(io::Error::from_raw_os_error)?;
+
     for fd in 3..file_descriptor_limit {
         let flags = loop {
             // SAFETY: fcntl accepts any integer descriptor and reports EBADF
