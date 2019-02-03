$NetBSD$

--- ../vendor/termios-0.2.2/src/lib.rs.orig	2016-01-20 16:52:20.000000000 +0000
+++ ../vendor/termios-0.2.2/src/lib.rs
@@ -99,6 +99,10 @@
 //!     cfsetspeed(termios, termios::os::openbsd::B921600)
 //! }
 //!
+//! #[cfg(target_os = "netbsd")]
+//! fn set_fastest_speed(termios: &mut Termios) -> io::Result<()> {
+//!     cfsetspeed(termios, termios::os::openbsd::B921600)
+//! }
 //! # let fd = 1;
 //! let mut termios = Termios::from_fd(fd).unwrap();
 //! set_fastest_speed(&mut termios).unwrap();
@@ -496,3 +500,4 @@ fn io_result(result: c_int) -> io::Resul
         _ => Err(io::Error::last_os_error())
     }
 }
+
