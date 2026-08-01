$NetBSD$

Detect a process blocked reading stdin on NetBSD.

The Linux implementation reads /proc/<pid>/syscall and /proc/<pid>/wchan,
neither of which exists on NetBSD, and resolves /proc/<pid>/fd/0 with
readlink(), which fails with EINVAL here because the entry is a real node
rather than a symlink.

NetBSD instead exposes the wait-channel name as a field of the single-line
/proc/<pid>/status, and the fd entries can be classified with stat(). Use
those, so an interactive command that prompts for input is noticed rather
than hanging until it times out.

The status-line field offsets are counted from the end of the line, because
the command name is the first field and may itself contain spaces.

--- crates/jcode-core/src/stdin_detect.rs.orig
+++ crates/jcode-core/src/stdin_detect.rs
@@ -9,16 +9,180 @@ pub fn is_waiting_for_stdin(pid: u32) -> StdinState {
     #[cfg(target_os = "linux")]
     return linux::check(pid);
 
+    #[cfg(target_os = "netbsd")]
+    return netbsd::check(pid);
+
     #[cfg(target_os = "macos")]
     return macos::check(pid);
 
     #[cfg(target_os = "windows")]
     return windows::check(pid);
 
-    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
+    #[cfg(not(any(
+        target_os = "linux",
+        target_os = "netbsd",
+        target_os = "macos",
+        target_os = "windows"
+    )))]
     return StdinState::Unknown;
 }
 
+/// Like [`is_waiting_for_stdin`], but also walks descendants so wrapper chains
+/// (`sh -> wrapper -> reader`) are detected. Platforms without a tree walker
+/// fall back to checking the process itself.
+pub fn is_waiting_for_stdin_in_tree(pid: u32) -> StdinState {
+    #[cfg(target_os = "linux")]
+    return linux::check_process_tree(pid);
+
+    #[cfg(target_os = "netbsd")]
+    return netbsd::check_process_tree(pid);
+
+    #[cfg(not(any(target_os = "linux", target_os = "netbsd")))]
+    return is_waiting_for_stdin(pid);
+}
+
+/// Pure parsers for NetBSD's single-line `/proc/<pid>/status` format.
+///
+/// Kept outside the `netbsd` module (and always compiled) so the field-offset
+/// logic, which is the only part that can silently rot, is unit-tested on
+/// every platform rather than only in a NetBSD CI job.
+pub mod netbsd_status {
+    /// Wait-channel name (field 11), or `None` when the process is runnable
+    /// (`nochan`) or the line is malformed.
+    ///
+    /// The command name is field 1 and may itself contain spaces, but every
+    /// field after it is space-free and the line has a fixed field count, so
+    /// fields are counted from the end: `... wchan euid groups`.
+    pub fn parse_wait_channel(status: &str) -> Option<&str> {
+        let fields: Vec<&str> = status.split_whitespace().collect();
+        let wchan = *fields.get(fields.len().checked_sub(3)?)?;
+        (wchan != "nochan").then_some(wchan)
+    }
+
+    /// Parent pid (field 3), counted from the end so a command name containing
+    /// spaces cannot shift the index. Trailing fields after ppid are: pgid,
+    /// sid, tdev, flags, start, utime, stime, wchan, euid, groups.
+    pub fn parse_parent_pid(status: &str) -> Option<u32> {
+        let fields: Vec<&str> = status.split_whitespace().collect();
+        match fields.get(fields.len().checked_sub(11)?)?.parse::<u32>() {
+            Ok(ppid) => Some(ppid),
+            // A malformed status line means "cannot determine", not pid 0.
+            Err(_) => None,
+        }
+    }
+}
+
+/// NetBSD's procfs is not Linux's: there is no `syscall` or `wchan` file, and
+/// `/proc/<pid>/fd/0` is a real node rather than a symlink. What it does
+/// provide is the wait-channel *name* as field 11 of the single-line
+/// `/proc/<pid>/status`, plus `stat()`-able fd entries. Combining "blocked on
+/// a read-ish wait channel" with "fd 0 is a pipe or tty" gives the same signal
+/// the Linux path derives from `wchan` + the fd 0 link.
+#[cfg(target_os = "netbsd")]
+pub mod netbsd {
+    use super::*;
+    use std::os::unix::fs::FileTypeExt;
+
+    /// Wait channels NetBSD parks a process on while it blocks in `read()`.
+    /// `ttyraw`/`ttyin` cover terminal reads, `pipe_rd` pipes, and `netio`
+    /// socket reads (used when stdin is a socketpair).
+    const READ_WAIT_CHANNELS: &[&str] = &["ttyraw", "ttyin", "ttyout", "pipe_rd", "netio"];
+
+    pub fn check(pid: u32) -> StdinState {
+        check_inner(pid, false)
+    }
+
+    fn check_inner(pid: u32, strict: bool) -> StdinState {
+        let Ok(status) = std::fs::read_to_string(format!("/proc/{}/status", pid)) else {
+            return if strict {
+                StdinState::NotReading
+            } else {
+                StdinState::Unknown
+            };
+        };
+
+        match super::netbsd_status::parse_wait_channel(&status) {
+            Some(wchan) if READ_WAIT_CHANNELS.contains(&wchan) && stdin_is_pipe_or_pty(pid) => {
+                StdinState::Reading
+            }
+            Some(_) => StdinState::NotReading,
+            None => {
+                if strict {
+                    StdinState::NotReading
+                } else {
+                    StdinState::Unknown
+                }
+            }
+        }
+    }
+
+    fn stdin_is_pipe_or_pty(pid: u32) -> bool {
+        let Ok(meta) = std::fs::metadata(format!("/proc/{}/fd/0", pid)) else {
+            return false;
+        };
+        let file_type = meta.file_type();
+        file_type.is_fifo() || file_type.is_char_device() || file_type.is_socket()
+    }
+
+    /// Walk descendants like the Linux path so wrapper chains
+    /// (`sh -> wrapper -> reader`) are detected.
+    pub fn check_process_tree(pid: u32) -> StdinState {
+        let result = check(pid);
+        if result == StdinState::Reading {
+            return result;
+        }
+
+        const MAX_DEPTH: usize = 32;
+        const MAX_VISITED: usize = 512;
+        let mut visited: std::collections::HashSet<u32> = std::collections::HashSet::new();
+        visited.insert(pid);
+        let mut queue: std::collections::VecDeque<(u32, usize)> = direct_children(pid)
+            .into_iter()
+            .map(|child| (child, 1usize))
+            .collect();
+
+        while let Some((child_pid, depth)) = queue.pop_front() {
+            if !visited.insert(child_pid) || visited.len() > MAX_VISITED {
+                continue;
+            }
+            if check_inner(child_pid, true) == StdinState::Reading {
+                return StdinState::Reading;
+            }
+            if depth < MAX_DEPTH {
+                for grandchild in direct_children(child_pid) {
+                    queue.push_back((grandchild, depth + 1));
+                }
+            }
+        }
+
+        result
+    }
+
+    /// NetBSD has no `task/<tid>/children` interface, so derive children from
+    /// the parent pid (field 3) of each process's status line.
+    fn direct_children(pid: u32) -> Vec<u32> {
+        let mut children = Vec::new();
+        let Ok(entries) = std::fs::read_dir("/proc") else {
+            return children;
+        };
+        for entry in entries.flatten() {
+            let Ok(name) = entry.file_name().into_string() else {
+                continue;
+            };
+            let Ok(candidate) = name.parse::<u32>() else {
+                continue;
+            };
+            let Ok(status) = std::fs::read_to_string(format!("/proc/{}/status", candidate)) else {
+                continue;
+            };
+            if super::netbsd_status::parse_parent_pid(&status) == Some(pid) {
+                children.push(candidate);
+            }
+        }
+        children
+    }
+}
+
 #[cfg(target_os = "linux")]
 pub mod linux {
     use super::*;
