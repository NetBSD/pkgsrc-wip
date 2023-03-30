$NetBSD$

--- ../rustc-1.54.0-src/library/std/src/sys/unix/thread.rs.orig	2021-07-26 14:43:02.000000000 +0000
+++ ../rustc-1.54.0-src/library/std/src/sys/unix/thread.rs
@@ -357,6 +357,21 @@ pub mod guard {
             const GUARD_PAGES: usize = 1;
             let guard = guardaddr..guardaddr + GUARD_PAGES * page_size;
             Some(guard)
+        } else if cfg!(target_os = "netbsd") {
+            // [The following should be reviewed/confirmed, -DLB]:
+            // Using the default else clause below, sporadic guard page
+            // errors were occurring during builds of rustc & cargo with
+            // mrustc on NetBSD; however, NetBSD has a kernel-based
+            // guard area mechanism too.  Therefore, try relying on that
+            // instead of the default mmap/mprotect solution; but note:
+            // if userland code changes the stack address, the NetBSD
+            // kernel-based guard mechanism is deactivated (see
+            // pthread_attr_getstack(3)) and the userland code must
+            // manage a guard area itself.  Fortunately, the stack
+            // appears to be unchanged by this version of thread.rs
+            let stackaddr = get_stack_start_aligned()?;
+            let stackaddr = stackaddr as usize;
+            Some(stackaddr - page_size..stackaddr)
         } else {
             // Reallocate the last page of the stack.
             // This ensures SIGBUS will be raised on
@@ -376,11 +391,16 @@ pub mod guard {
                 0,
             );
             if result != stackaddr || result == MAP_FAILED {
+                println!( "stackaddr = {}", stackaddr as u64 );
+                println!( "mmap() -> result {}", result as u64 );
+                println!( "mmap() -> ERRNO {}", os::errno() as u64 );
                 panic!("failed to allocate a guard page: {}", io::Error::last_os_error());
             }
 
             let result = mprotect(stackaddr, page_size, PROT_NONE);
             if result != 0 {
+                println!( "stackaddr = {}", stackaddr as u64 );
+                println!( "mprotect() -> ERRNO {}", os::errno() as u64 );
                 panic!("failed to protect the guard page: {}", io::Error::last_os_error());
             }
 
