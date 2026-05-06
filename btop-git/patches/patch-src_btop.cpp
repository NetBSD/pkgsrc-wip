$NetBSD$

Attempt to fix UI hangs when running for long periods

https://github.com/aristocratos/btop/pull/1647

--- src/btop.cpp.orig	2026-05-06 15:50:33.000000000 +0000
+++ src/btop.cpp
@@ -127,6 +127,7 @@ namespace Global {
 
 namespace Runner {
 	static pthread_t runner_id;
+	void safe_thread_trigger();
 } // namespace Runner
 
 //* Handler for SIGWINCH and general resizing events, does nothing if terminal hasn't been resized unless force=true
@@ -215,6 +216,12 @@ void clean_quit(int sig) {
 	Runner::stop();
 	if (Global::_runner_started) {
 	#if defined __APPLE__ || defined __OpenBSD__ || defined __NetBSD__
+		// binary_semaphore::acquire() is not a POSIX cancellation point on macOS;
+		// pthread_join() would hang if the thread is parked in thread_wait(). Post
+		// a token so it wakes, sees Global::quitting==true, and exits the loop.
+		// safe_thread_trigger() drains any pre-existing token to avoid undefined behavior on the
+		// max-1 semaphore.
+		Runner::safe_thread_trigger();
 		if (pthread_join(Runner::runner_id, nullptr) != 0) {
 			Logger::warning("Failed to join _runner thread on exit!");
 			pthread_cancel(Runner::runner_id);
@@ -374,6 +381,9 @@ namespace Runner {
 	std::binary_semaphore do_work { 0 };
 	inline void thread_wait() { do_work.acquire(); }
 	inline void thread_trigger() { do_work.release(); }
+	// Guarantees exactly one token is posted: drains any pre-existing token
+	// before release() to avoid undefined behavior on the max-1 binary_semaphore.
+	inline void safe_thread_trigger() { do_work.try_acquire(); do_work.release(); }
 
 	//* Wrapper for raising privileges when using SUID bit
 	class gain_priv {
@@ -742,7 +752,13 @@ namespace Runner {
 			Logger::error("Stall in Runner thread, restarting!");
 			set_active(false);
 			// exit(1);
+			// pthread_cancel() marks cancellation pending before thread_trigger() wakes
+			// the thread. binary_semaphore::acquire() is not a POSIX cancellation point
+			// on macOS; sleep_ms(1) is. With cancellation already pending when the
+			// thread reaches sleep_ms(), delivery is guaranteed regardless of scheduling.
+			stopping = true;
 			pthread_cancel(Runner::runner_id);
+			thread_trigger();
 
 			// Wait for the thread to actually terminate before creating a new one
 			void* thread_result;
@@ -750,6 +766,21 @@ namespace Runner {
 			if (join_result != 0) {
 				Logger::warning("Failed to join cancelled thread: {}", strerror(join_result));
 			}
+			// pthread_cancel does not reliably invoke C++ destructors on macOS,
+			// so the cancelled thread's lock_guard on mtx may not have fired.
+			// The thread is gone (joined above); unlock the orphaned mutex so
+			// the replacement thread can acquire it. Technically undefined
+			// behavior per [thread.mutex.requirements.mutex] (calling unlock
+			// from a non-owning thread), but the mutex would otherwise remain
+			// permanently locked.
+			if (join_result == 0) {
+				mtx.unlock();
+			}
+			// A thread cancelled mid-work never calls do_work.acquire(), leaving the
+			// counter at 1. Drain it so the new thread blocks on its first thread_wait()
+			// rather than racing on current_conf.
+			do_work.try_acquire();
+			stopping = false;
 
 			if (pthread_create(&Runner::runner_id, nullptr, &Runner::_runner, nullptr) != 0) {
 				Global::exit_error_msg = "Failed to re-create _runner thread!";
