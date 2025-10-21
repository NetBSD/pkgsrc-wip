--- lib/shmem.cpp.orig	2021-12-28 18:31:58.000000000 +0900
+++ lib/shmem.cpp	2025-10-21 12:05:31.817683726 +0900
@@ -11,7 +11,11 @@ extern "C"
 {
   bool shmem_create (int nsize) {return shmem.create(nsize);}
   void shmem_setkey (char * const mykey) {shmem.setKey(QLatin1String{mykey});}
-  bool shmem_attach () {return shmem.attach();}
+  bool shmem_attach() {
+   bool rc = shmem.attach();
+   if (!rc) puts(shmem.errorString().toStdString().c_str());
+   return rc;
+   }
   int shmem_size () {return static_cast<int> (shmem.size());}
   struct jt9com * shmem_address () {return reinterpret_cast<struct jt9com *>(shmem.data());}
   bool shmem_lock () {return shmem.lock();}
