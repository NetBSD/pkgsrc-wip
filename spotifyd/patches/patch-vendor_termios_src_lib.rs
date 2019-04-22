$NetBSD$

Upstream PR is wip: https://github.com/dcuddeback/termios-rs/pull/22

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
@@ -116,7 +120,7 @@ use libc::{c_int,pid_t};
 pub use ::os::target::{cc_t,speed_t,tcflag_t}; // types
 pub use ::os::target::{VEOF,VEOL,VERASE,VINTR,VKILL,VMIN,VQUIT,VSTART,VSTOP,VSUSP,VTIME}; // c_cc subscripts
 pub use ::os::target::{BRKINT,ICRNL,IGNBRK,IGNCR,IGNPAR,INLCR,INPCK,ISTRIP,IXANY,IXOFF,IXON,PARMRK}; // input modes
-pub use ::os::target::{OPOST,ONLCR,OCRNL,TAB3,ONOCR,ONLRET}; // output modes
+pub use ::os::target::{OPOST,ONLCR,OCRNL,ONOCR,ONLRET}; // output modes
 pub use ::os::target::{B0,B50,B75,B110,B134,B150,B200,B300,B600,B1200,B1800,B2400,B4800,B9600,B19200,B38400}; // baud rate selection
 pub use ::os::target::{CSIZE,CS5,CS6,CS7,CS8,CSTOPB,CREAD,PARENB,PARODD,HUPCL,CLOCAL}; // control modes
 pub use ::os::target::{ECHO,ECHOE,ECHOK,ECHONL,ICANON,IEXTEN,ISIG,NOFLSH,TOSTOP}; // local modes
@@ -496,3 +500,4 @@ fn io_result(result: c_int) -> io::Resul
         _ => Err(io::Error::last_os_error())
     }
 }
+
