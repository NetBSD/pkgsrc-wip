$NetBSD$

Cover the NetBSD status-line parsers.

The field offsets are the only part that can rot without any compile-time
signal, so they are parsed on every platform against status lines captured
verbatim from NetBSD, including a command name containing spaces. Two extra
tests run only on NetBSD and check the behaviour against live processes: a
real pipe reader must be detected, and a sleeping process must not be, since
a false positive would prompt the user on every long-running command.

--- crates/jcode-core/src/stdin_detect_tests.rs.orig
+++ crates/jcode-core/src/stdin_detect_tests.rs
@@ -319,3 +319,127 @@ fn direct_children_of_childless_process_does_not_scan_proc() {
         "sleep should have no children, got {children:?}"
     );
 }
+
+// ---------------------------------------------------------------------------
+// NetBSD `/proc/<pid>/status` parsing
+//
+// Fixtures are verbatim lines captured from NetBSD 11.99 (amd64). They are
+// parsed on every platform so the field offsets cannot silently rot: NetBSD's
+// status is one whitespace-separated line whose *first* field (the command
+// name) is the only one that can contain spaces, hence counting from the end.
+// ---------------------------------------------------------------------------
+
+/// `cat` blocked reading a pipe.
+const NETBSD_STATUS_PIPE_READ: &str = "cat 9290 15669 19993 19993 -1,-1 noflags 1785433833,220200 0,1004 0,1004 pipe_rd 1000 100,100,0";
+/// A runnable process (`nochan` wait channel).
+const NETBSD_STATUS_RUNNABLE: &str = "python3.14 22072 19993 19993 19993 -1,-1 noflags 1785433788,399468 0,48818 0,27896 nochan 1000 100,100,0";
+/// `cat` blocked reading a tty.
+const NETBSD_STATUS_TTY_READ: &str = "cat 27999 974 27999 27999 5,14 ctty,sldr 1785433994,550096 0,2151 0,3226 ttyraw 1000 100,100,0";
+
+#[test]
+fn netbsd_wait_channel_is_parsed_from_real_status_lines() {
+    use super::netbsd_status::parse_wait_channel;
+
+    assert_eq!(parse_wait_channel(NETBSD_STATUS_PIPE_READ), Some("pipe_rd"));
+    assert_eq!(parse_wait_channel(NETBSD_STATUS_TTY_READ), Some("ttyraw"));
+}
+
+#[test]
+fn netbsd_runnable_process_reports_no_wait_channel() {
+    assert_eq!(
+        super::netbsd_status::parse_wait_channel(NETBSD_STATUS_RUNNABLE),
+        None,
+        "`nochan` means runnable, not blocked on a channel"
+    );
+}
+
+#[test]
+fn netbsd_parent_pid_is_parsed_from_real_status_lines() {
+    use super::netbsd_status::parse_parent_pid;
+
+    assert_eq!(parse_parent_pid(NETBSD_STATUS_PIPE_READ), Some(15669));
+    assert_eq!(parse_parent_pid(NETBSD_STATUS_RUNNABLE), Some(19993));
+    assert_eq!(parse_parent_pid(NETBSD_STATUS_TTY_READ), Some(974));
+}
+
+/// The reason both parsers count fields from the end: a process can carry a
+/// command name containing spaces, which would shift every front-counted index.
+#[test]
+fn netbsd_parsers_tolerate_spaces_in_the_command_name() {
+    use super::netbsd_status::{parse_parent_pid, parse_wait_channel};
+
+    let status = "my weird proc 9290 15669 19993 19993 -1,-1 noflags 1785433833,220200 0,1004 0,1004 pipe_rd 1000 100,100,0";
+    assert_eq!(parse_wait_channel(status), Some("pipe_rd"));
+    assert_eq!(parse_parent_pid(status), Some(15669));
+}
+
+#[test]
+fn netbsd_parsers_reject_malformed_status_lines() {
+    use super::netbsd_status::{parse_parent_pid, parse_wait_channel};
+
+    assert_eq!(parse_wait_channel(""), None);
+    assert_eq!(parse_parent_pid(""), None);
+    assert_eq!(parse_parent_pid("cat 1 2"), None);
+}
+
+/// End-to-end check that the NetBSD implementation actually reports a live
+/// pipe reader as `Reading`. The parser tests above use captured fixtures, so
+/// without this a wrong wait-channel list or a broken fd-type gate would still
+/// look green.
+#[cfg(target_os = "netbsd")]
+#[test]
+fn netbsd_detects_a_live_process_blocked_reading_a_pipe() {
+    use std::process::{Command, Stdio};
+
+    // `sleep` holds the write end open without producing data, so `cat` parks
+    // in read() on the pipe for the duration of the test.
+    let mut producer = Command::new("sleep")
+        .arg("30")
+        .stdout(Stdio::piped())
+        .spawn()
+        .expect("spawn producer");
+    let pipe = producer.stdout.take().expect("producer stdout");
+    let mut reader = Command::new("cat")
+        .stdin(Stdio::from(pipe))
+        .stdout(Stdio::null())
+        .spawn()
+        .expect("spawn reader");
+
+    std::thread::sleep(std::time::Duration::from_millis(500));
+    let state = super::netbsd::check(reader.id());
+
+    let _ = reader.kill();
+    let _ = reader.wait();
+    let _ = producer.kill();
+    let _ = producer.wait();
+
+    assert_eq!(
+        state,
+        StdinState::Reading,
+        "cat blocked on an empty pipe should report Reading"
+    );
+}
+
+/// Guard against the opposite failure: a sleeping process must not be
+/// mistaken for one waiting on stdin, or the bash tool would prompt the user
+/// for input on every long-running command.
+#[cfg(target_os = "netbsd")]
+#[test]
+fn netbsd_does_not_report_a_sleeping_process_as_reading_stdin() {
+    let mut sleeper = std::process::Command::new("sleep")
+        .arg("30")
+        .spawn()
+        .expect("spawn sleeper");
+
+    std::thread::sleep(std::time::Duration::from_millis(500));
+    let state = super::netbsd::check(sleeper.id());
+
+    let _ = sleeper.kill();
+    let _ = sleeper.wait();
+
+    assert_ne!(
+        state,
+        StdinState::Reading,
+        "a sleeping process must not look like a stdin reader"
+    );
+}
