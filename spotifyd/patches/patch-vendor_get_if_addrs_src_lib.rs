$NetBSD$

Fixed upstream in later versions

https://github.com/maidsafe/get_if_addrs/pull/56

--- ../vendor/get_if_addrs-0.5.3/src/lib.rs.orig	2018-06-21 12:35:24.000000000 +0000
+++ ../vendor/get_if_addrs-0.5.3/src/lib.rs
@@ -197,7 +197,7 @@ mod getifaddrs_posix {
     }
 
     #[cfg(
-        any(target_os = "freebsd", target_os = "ios", target_os = "macos", target_os = "openbsd")
+        any(target_os = "freebsd", target_os = "ios", target_os = "macos", target_os = "openbsd", target_os = "netbsd")
     )]
     fn do_broadcast(ifaddr: &posix_ifaddrs) -> Option<IpAddr> {
         sockaddr_to_ipaddr(ifaddr.ifa_dstaddr)

