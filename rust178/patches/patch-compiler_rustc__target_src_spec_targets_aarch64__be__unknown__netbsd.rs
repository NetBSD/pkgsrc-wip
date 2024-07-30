$NetBSD$

NetBSD aarch64 has a bug in the thread-local storage implementation,
ref. http://gnats.netbsd.org/58154, and this is responsible for the
build misery experienced earlier, ref.
https://github.com/rust-lang/rust/issues/123551
Turn it off for now on arm64.
Ideally should check whether the specific OS version has the fix
or not, but e.g. __NetBSD_Version__ isn't easily available here
that I know, and this goes against the attitude that OS version
should matter as long as it's >= supported version.
So until the fix for NetBSD PR#58154 has propagated to releases,
this is what we do.

--- compiler/rustc_target/src/spec/targets/aarch64_be_unknown_netbsd.rs.orig	2024-07-23 19:21:34.344805113 +0000
+++ compiler/rustc_target/src/spec/targets/aarch64_be_unknown_netbsd.rs
@@ -18,6 +18,7 @@ pub fn target() -> Target {
             max_atomic_width: Some(128),
             stack_probes: StackProbeType::Inline,
             endian: Endian::Big,
+            has_thread_local: false, // ref. NetBSD PR#58154
             ..base::netbsd::opts()
         },
     }
