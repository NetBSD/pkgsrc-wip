$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/io/Queue.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/io/Queue.cc
@@ -5,20 +5,22 @@
 /// @author Peter Cucka
 
 #include "Queue.h"
-
 #include "File.h"
 #include "Stream.h"
-#include <openvdb/Exceptions.h>
-#include <openvdb/util/logging.h>
+#include "openvdb/Exceptions.h"
+#include "openvdb/util/logging.h"
+
 #include <tbb/concurrent_hash_map.h>
-#include <tbb/task.h>
-#include <tbb/tbb_thread.h> // for tbb::this_tbb_thread::sleep()
-#include <tbb/tick_count.h>
+#include <tbb/task_arena.h>
+
+#include <thread>
 #include <algorithm> // for std::max()
 #include <atomic>
 #include <iostream>
 #include <map>
 #include <mutex>
+#include <chrono>
+
 
 namespace openvdb {
 OPENVDB_USE_VERSION_NAMESPACE
@@ -28,18 +30,19 @@ namespace io {
 namespace {
 
 // Abstract base class for queuable TBB tasks that adds a task completion callback
-class Task: public tbb::task
+class Task
 {
 public:
     Task(Queue::Id id): mId(id) {}
-    ~Task() override {}
+    virtual ~Task() {}
 
     Queue::Id id() const { return mId; }
 
     void setNotifier(Queue::Notifier& notifier) { mNotify = notifier; }
+    virtual void execute() const = 0;
 
 protected:
-    void notify(Queue::Status status) { if (mNotify) mNotify(this->id(), status); }
+    void notify(Queue::Status status) const { if (mNotify) mNotify(this->id(), status); }
 
 private:
     Queue::Id mId;
@@ -48,7 +51,7 @@ private:
 
 
 // Queuable TBB task that writes one or more grids to a .vdb file or an output stream
-class OutputTask: public Task
+class OutputTask : public Task
 {
 public:
     OutputTask(Queue::Id id, const GridCPtrVec& grids, const Archive& archive,
@@ -56,10 +59,10 @@ public:
         : Task(id)
         , mGrids(grids)
         , mArchive(archive.copy())
-        , mMetadata(metadata)
-    {}
+        , mMetadata(metadata) {}
+    ~OutputTask() override {}
 
-    tbb::task* execute() override
+    void execute() const override
     {
         Queue::Status status = Queue::FAILED;
         try {
@@ -69,10 +72,8 @@ public:
             if (const char* msg = e.what()) {
                 OPENVDB_LOG_ERROR(msg);
             }
-        } catch (...) {
-        }
+        } catch (...) {}
         this->notify(status);
-        return nullptr; // no successor to this task
     }
 
 private:
@@ -94,7 +95,6 @@ struct Queue::Impl
     /// @todo Provide more information than just "succeeded" or "failed"?
     using StatusMap = tbb::concurrent_hash_map<Queue::Id, Queue::Status>;
 
-
     Impl()
         : mTimeout(Queue::DEFAULT_TIMEOUT)
         , mCapacity(Queue::DEFAULT_CAPACITY)
@@ -159,12 +159,15 @@ struct Queue::Impl
 
     bool canEnqueue() const { return mNumTasks < Int64(mCapacity); }
 
-    void enqueue(Task& task)
+    void enqueue(OutputTask& task)
     {
-        tbb::tick_count start = tbb::tick_count::now();
+        auto start = std::chrono::steady_clock::now();
         while (!canEnqueue()) {
-            tbb::this_tbb_thread::sleep(tbb::tick_count::interval_t(0.5/*sec*/));
-            if ((tbb::tick_count::now() - start).seconds() > double(mTimeout)) {
+            std::this_thread::sleep_for(/*0.5s*/std::chrono::milliseconds(500));
+            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
+                std::chrono::steady_clock::now() - start);
+            const double seconds = double(duration.count()) / 1000.0;
+            if (seconds > double(mTimeout)) {
                 OPENVDB_THROW(RuntimeError,
                     "unable to queue I/O task; " << mTimeout << "-second time limit expired");
             }
@@ -173,7 +176,10 @@ struct Queue::Impl
             std::placeholders::_1, std::placeholders::_2);
         task.setNotifier(notify);
         this->setStatus(task.id(), Queue::PENDING);
-        tbb::task::enqueue(task);
+
+        // get the global task arena
+        tbb::task_arena arena(tbb::task_arena::attach{});
+        arena.enqueue([task = std::move(task)] { task.execute(); });
         ++mNumTasks;
     }
 
@@ -204,7 +210,7 @@ Queue::~Queue()
     /// (e.g., by keeping a static registry of queues that also dispatches
     /// or blocks notifications)?
     while (mImpl->mNumTasks > 0) {
-        tbb::this_tbb_thread::sleep(tbb::tick_count::interval_t(0.5/*sec*/));
+        std::this_thread::sleep_for(/*0.5s*/std::chrono::milliseconds(500));
     }
 }
 
@@ -290,16 +296,8 @@ Queue::Id
 Queue::writeGridVec(const GridCPtrVec& grids, const Archive& archive, const MetaMap& metadata)
 {
     const Queue::Id taskId = mImpl->mNextId++;
-    // From the "GUI Thread" chapter in the TBB Design Patterns guide
-    OutputTask* task =
-        new(tbb::task::allocate_root()) OutputTask(taskId, grids, archive, metadata);
-    try {
-        mImpl->enqueue(*task);
-    } catch (openvdb::RuntimeError&) {
-        // Destroy the task if it could not be enqueued, then rethrow the exception.
-        tbb::task::destroy(*task);
-        throw;
-    }
+    OutputTask task(taskId, grids, archive, metadata);
+    mImpl->enqueue(task);
     return taskId;
 }
 
