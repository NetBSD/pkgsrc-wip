$NetBSD$

--- ../rustc-1.39.0-src/src/libstd/sys/unix/thread.rs.orig	2019-11-04 15:45:21.000000000 +0000
+++ ../rustc-1.39.0-src/src/libstd/sys/unix/thread.rs
@@ -330,14 +330,19 @@ pub mod guard {
             // than the initial mmap() used, so we mmap() here with
             // read/write permissions and only then mprotect() it to
             // no permissions at all. See issue #50313.
-            let result = mmap(stackaddr, PAGE_SIZE, PROT_READ | PROT_WRITE,
-                              MAP_PRIVATE | MAP_ANON | MAP_FIXED, -1, 0);
-            if result != stackaddr || result == MAP_FAILED {
-                panic!("failed to allocate a guard page");
-            }
+//          let result = mmap(stackaddr, PAGE_SIZE, PROT_READ | PROT_WRITE,
+//                            MAP_PRIVATE | MAP_ANON | MAP_FIXED, -1, 0);
+//          if result != stackaddr || result == MAP_FAILED {
+//              println!( "stackaddr = {}", stackaddr as u64 );
+//              println!( "mmap() -> result {}", result as u64 );
+//              println!( "mmap() -> ERRNO {}", os::errno() as u64 );
+//              panic!("failed to allocate a guard page");
+//          }
 
             let result = mprotect(stackaddr, PAGE_SIZE, PROT_NONE);
             if result != 0 {
+                println!( "stackaddr = {}", stackaddr as u64 );
+                println!( "mprotect() -> ERRNO {}", os::errno() as u64 );
                 panic!("failed to protect the guard page");
             }
 
