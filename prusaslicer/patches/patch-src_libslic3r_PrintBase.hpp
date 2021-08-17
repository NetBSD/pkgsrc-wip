$NetBSD$

Migrate from deprecated tbb::mutex to std::mutex.
Migrate from deprecated tbb::atomic to std::atomic.

--- src/libslic3r/PrintBase.hpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/PrintBase.hpp
@@ -2,17 +2,13 @@
 #define slic3r_PrintBase_hpp_
 
 #include "libslic3r.h"
+#include <atomic>
 #include <set>
 #include <vector>
+#include <mutex>
 #include <string>
 #include <functional>
 
-// tbb/mutex.h includes Windows, which in turn defines min/max macros. Convince Windows.h to not define these min/max macros.
-#ifndef NOMINMAX
-    #define NOMINMAX
-#endif
-#include "tbb/mutex.h"
-
 #include "ObjectID.hpp"
 #include "Model.hpp"
 #include "PlaceholderParser.hpp"
@@ -84,23 +80,23 @@ class PrintState : public PrintStateBase
 public:
     PrintState() {}
 
-    StateWithTimeStamp state_with_timestamp(StepType step, tbb::mutex &mtx) const {
-        tbb::mutex::scoped_lock lock(mtx);
+    StateWithTimeStamp state_with_timestamp(StepType step, std::mutex &mtx) const {
+        std::lock_guard<std::mutex> lock(mtx);
         StateWithTimeStamp state = m_state[step];
         return state;
     }
 
-    StateWithWarnings state_with_warnings(StepType step, tbb::mutex &mtx) const {
-        tbb::mutex::scoped_lock lock(mtx);
+    StateWithWarnings state_with_warnings(StepType step, std::mutex &mtx) const {
+        std::lock_guard<std::mutex> lock(mtx);
         StateWithWarnings state = m_state[step];
         return state;
     }
 
-    bool is_started(StepType step, tbb::mutex &mtx) const {
+    bool is_started(StepType step, std::mutex &mtx) const {
         return this->state_with_timestamp(step, mtx).state == STARTED;
     }
 
-    bool is_done(StepType step, tbb::mutex &mtx) const {
+    bool is_done(StepType step, std::mutex &mtx) const {
         return this->state_with_timestamp(step, mtx).state == DONE;
     }
 
@@ -121,8 +117,8 @@ public:
     // This is necessary to block until the Print::apply() updates its state, which may
     // influence the processing step being entered.
     template<typename ThrowIfCanceled>
-    bool set_started(StepType step, tbb::mutex &mtx, ThrowIfCanceled throw_if_canceled) {
-        tbb::mutex::scoped_lock lock(mtx);
+    bool set_started(StepType step, std::mutex &mtx, ThrowIfCanceled throw_if_canceled) {
+        std::lock_guard<std::mutex> lock(mtx);
         // If canceled, throw before changing the step state.
         throw_if_canceled();
 #ifndef NDEBUG
@@ -154,8 +150,8 @@ public:
     // 		Timestamp when this stepentered the DONE state.
     // 		bool indicates whether the UI has to update the slicing warnings of this step or not.
 	template<typename ThrowIfCanceled>
-	std::pair<TimeStamp, bool> set_done(StepType step, tbb::mutex &mtx, ThrowIfCanceled throw_if_canceled) {
-        tbb::mutex::scoped_lock lock(mtx);
+	std::pair<TimeStamp, bool> set_done(StepType step, std::mutex &mtx, ThrowIfCanceled throw_if_canceled) {
+        std::lock_guard<std::mutex> lock(mtx);
         // If canceled, throw before changing the step state.
         throw_if_canceled();
         assert(m_state[step].state == STARTED);
@@ -266,9 +262,9 @@ public:
     // Return value:
     // 		Current milestone (StepType).
     // 		bool indicates whether the UI has to be updated or not.
-    std::pair<StepType, bool> active_step_add_warning(PrintStateBase::WarningLevel warning_level, const std::string &message, int message_id, tbb::mutex &mtx)
+    std::pair<StepType, bool> active_step_add_warning(PrintStateBase::WarningLevel warning_level, const std::string &message, int message_id, std::mutex &mtx)
     {
-        tbb::mutex::scoped_lock lock(mtx);
+	std::lock_guard<std::mutex> lock(mtx);
         assert(m_step_active != -1);
         StateWithWarnings &state = m_state[m_step_active];
         assert(state.state == STARTED);
@@ -314,7 +310,7 @@ protected:
     PrintObjectBase(ModelObject *model_object) : m_model_object(model_object) {}
     virtual ~PrintObjectBase() {}
     // Declared here to allow access from PrintBase through friendship.
-	static tbb::mutex&                  state_mutex(PrintBase *print);
+	static std::mutex&                  state_mutex(PrintBase *print);
 	static std::function<void()>        cancel_callback(PrintBase *print);
 	// Notify UI about a new warning of a milestone "step" on this PrintObjectBase.
 	// The UI will be notified by calling a status callback registered on print.
@@ -436,16 +432,16 @@ public:
 		// Canceled by user from the user interface (user pressed the "Cancel" button or user closed the application).
 		CANCELED_BY_USER = 1,
 		// Canceled internally from Print::apply() through the Print/PrintObject::invalidate_step() or ::invalidate_all_steps().
-		CANCELED_INTERNAL = 2
+		CANCELED_INTERNAL = 2,
 	};
     CancelStatus               cancel_status() const { return m_cancel_status; }
     // Has the calculation been canceled?
-	bool                       canceled() const { return m_cancel_status != NOT_CANCELED; }
+	bool                       canceled() const { return m_cancel_status != CancelStatus::NOT_CANCELED; }
     // Cancel the running computation. Stop execution of all the background threads.
-	void                       cancel() { m_cancel_status = CANCELED_BY_USER; }
-	void                       cancel_internal() { m_cancel_status = CANCELED_INTERNAL; }
+	void                       cancel() { m_cancel_status = CancelStatus::CANCELED_BY_USER; }
+	void                       cancel_internal() { m_cancel_status = CancelStatus::CANCELED_INTERNAL; }
     // Cancel the running computation. Stop execution of all the background threads.
-	void                       restart() { m_cancel_status = NOT_CANCELED; }
+	void                       restart() { m_cancel_status = CancelStatus::NOT_CANCELED; }
     // Returns true if the last step was finished with success.
     virtual bool               finished() const = 0;
 
@@ -461,7 +457,7 @@ protected:
 	friend class PrintObjectBase;
     friend class BackgroundSlicingProcess;
 
-    tbb::mutex&            state_mutex() const { return m_state_mutex; }
+    std::mutex&            state_mutex() const { return m_state_mutex; }
     std::function<void()>  cancel_callback() { return m_cancel_callback; }
 	void				   call_cancel_callback() { m_cancel_callback(); }
 	// Notify UI about a new warning of a milestone "step" on this PrintBase.
@@ -471,7 +467,7 @@ protected:
 
     // If the background processing stop was requested, throw CanceledException.
     // To be called by the worker thread and its sub-threads (mostly launched on the TBB thread pool) regularly.
-    void                   throw_if_canceled() const { if (m_cancel_status) throw CanceledException(); }
+    void                   throw_if_canceled() const { if (canceled()) throw CanceledException(); }
 
     // To be called by this->output_filename() with the format string pulled from the configuration layer.
     std::string            output_filename(const std::string &format, const std::string &default_ext, const std::string &filename_base, const DynamicConfig *config_override = nullptr) const;
@@ -486,7 +482,7 @@ protected:
     status_callback_type                    m_status_callback;
 
 private:
-    tbb::atomic<CancelStatus>               m_cancel_status;
+    std::atomic<Slic3r::PrintBase::CancelStatus>               m_cancel_status {CancelStatus::NOT_CANCELED};
 
     // Callback to be evoked to stop the background processing before a state is updated.
     cancel_callback_type                    m_cancel_callback = [](){};
@@ -494,7 +490,7 @@ private:
     // Mutex used for synchronization of the worker thread with the UI thread:
     // The mutex will be used to guard the worker thread against entering a stage
     // while the data influencing the stage is modified.
-    mutable tbb::mutex                      m_state_mutex;
+    mutable std::mutex                      m_state_mutex;
 };
 
 template<typename PrintStepEnum, const size_t COUNT>
