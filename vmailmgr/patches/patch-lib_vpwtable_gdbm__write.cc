$NetBSD$

--- lib/vpwtable/gdbm_write.cc.orig	2024-02-20 03:22:19.220947617 +0000
+++ lib/vpwtable/gdbm_write.cc
@@ -22,8 +22,8 @@
 class gdbm_vpwtable_writer : public vpwtable_writer
 {
 private:
-  const mystring& tmpname;
-  const mystring& destname;
+  const mystring tmpname;
+  const mystring destname;
   GDBM_FILE out;
   bool opened;
 public:
@@ -60,9 +60,9 @@ bool gdbm_vpwtable_writer::operator!() c
 bool gdbm_vpwtable_writer::put(const vpwentry& vpw)
 {
   mystring name = vpw->name.lower();
-  datum key = { (char*)name.c_str(), name.length() };
+  datum key = { (char*)name.c_str(), static_cast<int>(name.length()) };
   mystring binary = vpw->to_record();
-  datum data = { (char*)binary.c_str(), binary.length() };
+  datum data = { (char*)binary.c_str(), static_cast<int>(binary.length()) };
   return gdbm_store(out, key, data, GDBM_INSERT) == 0;
 }
 
