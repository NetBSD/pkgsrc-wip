--- ../vendor/battery-0.7.8/src/platform/freebsd/acpi.rs.orig	2022-05-03 23:17:48.208460903 +0200
+++ ../vendor/battery-0.7.8/src/platform/freebsd/acpi.rs	2022-05-03 23:18:16.618049883 +0200
@@ -7,6 +7,10 @@
 use std::mem;
 use std::os::unix::io::{AsRawFd, FromRawFd, IntoRawFd, RawFd};
 use std::str::FromStr;
+use libc;
+use nix;
+use nix::ioctl_read;
+use nix::ioctl_readwrite;
 
 use crate::{Result, State, Technology};
 
