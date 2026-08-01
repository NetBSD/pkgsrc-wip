$NetBSD$

Record why NetBSD keeps the conservative answer here.

NetBSD provides a Linux-compatible /proc/self/stat, so this check looks
portable, but measurement on NetBSD 11.99 shows tty_nr keeps its device
number after the pty master is closed. The "reset to 0" signal the check
relies on therefore never fires, and enabling it would be a silent false
negative rather than a useful reading.

--- crates/jcode-tui/src/tui/app/terminal_liveness.rs.orig
+++ crates/jcode-tui/src/tui/app/terminal_liveness.rs
@@ -15,6 +15,12 @@
 //! the stale fd 0 still reports `isatty=true`, so this is a strictly stronger
 //! signal than `IsTerminal`. On other platforms it conservatively reports
 //! `false` and orphan exit relies on SIGHUP alone.
+//!
+//! NetBSD deliberately stays on the conservative path even though its procfs
+//! exposes a Linux-compatible `/proc/self/stat`: measured on NetBSD 11.99,
+//! `tty_nr` keeps its original device number after the pty master is closed,
+//! so the "reset to 0" signal this check relies on never fires there and the
+//! reading would be a silent false negative rather than a useful one.
 
 use std::sync::OnceLock;
 
