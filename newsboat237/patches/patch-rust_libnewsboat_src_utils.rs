$NetBSD$

Use GNU iconv symbols explicitly, since Rust doesn't consult the C
header file.

--- rust/libnewsboat/src/utils.rs.orig	2024-09-22 15:05:50.000000000 +0000
+++ rust/libnewsboat/src/utils.rs
@@ -815,12 +815,15 @@ type iconv_t = *mut c_void;
 // On FreeBSD, link with GNU libiconv; the iconv implementation in libc doesn't support //TRANSLIT
 // and WCHAR_T. This is also why we change the symbol names from "iconv" to "libiconv" below.
 #[cfg_attr(target_os = "freebsd", link(name = "iconv"))]
+#[cfg_attr(target_os = "netbsd", link(name = "iconv"))]
 #[cfg_attr(target_os = "openbsd", link(name = "iconv"))]
 extern "C" {
     #[cfg_attr(target_os = "freebsd", link_name = "libiconv_open")]
+    #[cfg_attr(target_os = "netbsd", link_name = "libiconv_open")]
     #[cfg_attr(target_os = "openbsd", link_name = "libiconv_open")]
     pub fn iconv_open(tocode: *const c_char, fromcode: *const c_char) -> iconv_t;
     #[cfg_attr(target_os = "freebsd", link_name = "libiconv")]
+    #[cfg_attr(target_os = "netbsd", link_name = "libiconv")]
     #[cfg_attr(target_os = "openbsd", link_name = "libiconv")]
     pub fn iconv(
         cd: iconv_t,
@@ -830,6 +833,7 @@ extern "C" {
         outbytesleft: *mut size_t,
     ) -> size_t;
     #[cfg_attr(target_os = "freebsd", link_name = "libiconv_close")]
+    #[cfg_attr(target_os = "netbsd", link_name = "libiconv_close")]
     #[cfg_attr(target_os = "openbsd", link_name = "libiconv_close")]
     pub fn iconv_close(cd: iconv_t) -> c_int;
 }
