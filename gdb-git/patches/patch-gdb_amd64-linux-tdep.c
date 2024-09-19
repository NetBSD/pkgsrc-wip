$NetBSD$

--- gdb/amd64-linux-tdep.c.orig	2017-09-11 11:24:04.000000000 +0000
+++ gdb/amd64-linux-tdep.c
@@ -363,7 +363,7 @@ amd64_all_but_ip_registers_record (struc
 static enum gdb_syscall
 amd64_canonicalize_syscall (enum amd64_syscall syscall_number)
 {
-  switch (syscall_number) {
+  switch ((uint64_t)syscall_number) {
   case amd64_sys_read:
   case amd64_x32_sys_read:
     return gdb_sys_read;
