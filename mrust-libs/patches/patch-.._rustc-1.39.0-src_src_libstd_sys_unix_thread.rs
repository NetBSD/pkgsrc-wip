$NetBSD$

--- ../rustc-1.39.0-src/src/libstd/sys/unix/thread.rs.orig	2019-11-04 15:45:21.000000000 +0000
+++ ../rustc-1.39.0-src/src/libstd/sys/unix/thread.rs
@@ -321,6 +321,20 @@ pub mod guard {
             // trust that the kernel's own stack guard will work.
             let stackaddr = stackaddr as usize;
             Some(stackaddr - PAGE_SIZE..stackaddr)
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
+            let stackaddr = stackaddr as usize;
+            Some(stackaddr - PAGE_SIZE..stackaddr)
         } else {
             // Reallocate the last page of the stack.
             // This ensures SIGBUS will be raised on
@@ -333,11 +347,16 @@ pub mod guard {
             let result = mmap(stackaddr, PAGE_SIZE, PROT_READ | PROT_WRITE,
                               MAP_PRIVATE | MAP_ANON | MAP_FIXED, -1, 0);
             if result != stackaddr || result == MAP_FAILED {
+                println!( "stackaddr = {}", stackaddr as u64 );
+                println!( "mmap() -> result {}", result as u64 );
+                println!( "mmap() -> ERRNO {}", os::errno() as u64 );
                 panic!("failed to allocate a guard page");
             }
 
             let result = mprotect(stackaddr, PAGE_SIZE, PROT_NONE);
             if result != 0 {
+                println!( "stackaddr = {}", stackaddr as u64 );
+                println!( "mprotect() -> ERRNO {}", os::errno() as u64 );
                 panic!("failed to protect the guard page");
             }
 
