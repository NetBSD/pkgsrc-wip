$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/unittest/TestValueAccessor.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/unittest/TestValueAccessor.cc
@@ -378,22 +378,21 @@ TEST_F(TestValueAccessor, testMultithrea
     //using AccessorT = openvdb::tree::ValueAccessor<Tree4Type>;
 
     // Task to perform multiple reads through a shared accessor
-    struct ReadTask: public tbb::task {
+    struct ReadTask {
         AccessorT& acc;
         ReadTask(AccessorT& c): acc(c) {}
-        tbb::task* execute()
+        void execute()
         {
             for (int i = -MAX_COORD; i < MAX_COORD; ++i) {
                 ASSERT_DOUBLES_EXACTLY_EQUAL(double(i), acc.getValue(openvdb::Coord(i)));
             }
-            return nullptr;
         }
     };
     // Task to perform multiple writes through a shared accessor
-    struct WriteTask: public tbb::task {
+    struct WriteTask {
         AccessorT& acc;
         WriteTask(AccessorT& c): acc(c) {}
-        tbb::task* execute()
+        void execute()
         {
             for (int i = -MAX_COORD; i < MAX_COORD; ++i) {
                 float f = acc.getValue(openvdb::Coord(i));
@@ -401,26 +400,20 @@ TEST_F(TestValueAccessor, testMultithrea
                 acc.setValue(openvdb::Coord(i), float(i));
                 ASSERT_DOUBLES_EXACTLY_EQUAL(float(i), acc.getValue(openvdb::Coord(i)));
             }
-            return nullptr;
         }
     };
     // Parent task to spawn multiple parallel read and write tasks
-    struct RootTask: public tbb::task {
+    struct RootTask {
         AccessorT& acc;
         RootTask(AccessorT& c): acc(c) {}
-        tbb::task* execute()
+        void execute()
         {
-            ReadTask* r[3]; WriteTask* w[3];
+            tbb::task_group tasks;
             for (int i = 0; i < 3; ++i) {
-                r[i] = new(allocate_child()) ReadTask(acc);
-                w[i] = new(allocate_child()) WriteTask(acc);
+                tasks.run([&] { ReadTask r(acc); r.execute(); });
+                tasks.run([&] { WriteTask w(acc); w.execute(); });
             }
-            set_ref_count(6 /*children*/ + 1 /*wait*/);
-            for (int i = 0; i < 3; ++i) {
-                spawn(*r[i]); spawn(*w[i]);
-            }
-            wait_for_all();
-            return nullptr;
+            tasks.wait();
         }
     };
 
@@ -432,8 +425,8 @@ TEST_F(TestValueAccessor, testMultithrea
     }
 
     // Run multiple read and write tasks in parallel.
-    RootTask& root = *new(tbb::task::allocate_root()) RootTask(acc);
-    tbb::task::spawn_root_and_wait(root);
+    RootTask root(acc);
+    root.execute();
 
 #undef MAX_COORD
 }
