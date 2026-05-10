$NetBSD$

Fix pthread_cancel deadlocks on NetBSD:
1. Use POSIX sem_t instead of std::binary_semaphore (C++ semaphore internal
   waiter pool is not cancellation-safe)
2. Add pthread_cleanup_push/pop for Runner::mtx to ensure it's released
   when thread is cancelled
3. Wake thread after pthread_cancel by posting to semaphore, since NetBSD's
   sem_wait doesn't automatically wake on cancellation
4. Check for cancellation in semaphore acquire loop

--- src/btop.cpp.orig	2026-05-06 15:50:33.000000000 +0000
+++ src/btop.cpp
@@ -44,6 +44,8 @@ tab-size = 4
 #include <chrono>
 #include <utility>
 #include <semaphore>
+#include <semaphore.h>  // POSIX semaphore - cancellation-safe unlike std::binary_semaphore
+#include <cerrno>
 
 #ifdef __APPLE__
 	#include <CoreFoundation/CoreFoundation.h>
@@ -370,8 +372,21 @@ namespace Runner {
 	}
 
 	//* Setup semaphore for triggering thread to do work
-	// TODO: This can be made a local without too much effort.
-	std::binary_semaphore do_work { 0 };
+	//* Using POSIX sem_t instead of std::binary_semaphore because the C++ semaphore
+	//* is NOT cancellation-safe - pthread_cancel can corrupt its internal waiter pool
+	struct posix_semaphore {
+		sem_t sem;
+		posix_semaphore() { sem_init(&sem, 0, 0); }
+		~posix_semaphore() { sem_destroy(&sem); }
+		void acquire() {
+			while (sem_wait(&sem) == -1 && errno == EINTR) {
+				pthread_testcancel();  // Check for pending cancellation
+			}
+			pthread_testcancel();  // Check after successful acquire too
+		}
+		void release() { sem_post(&sem); }
+	};
+	posix_semaphore do_work;
 	inline void thread_wait() { do_work.acquire(); }
 	inline void thread_trigger() { do_work.release(); }
 
@@ -458,6 +473,12 @@ namespace Runner {
 		}
 	}
 
+	//? Cleanup handler to release mutex when thread is cancelled via pthread_cancel
+	static void cleanup_mutex(void* arg) {
+		std::mutex* m = static_cast<std::mutex*>(arg);
+		m->unlock();
+	}
+
 	//? ------------------------------- Secondary thread: async launcher and drawing ----------------------------------
 	static void * _runner(void *) {
 		//? Block some signals in this thread to avoid deadlock from any signal handlers trying to stop this thread
@@ -468,8 +489,10 @@ namespace Runner {
 		sigaddset(&mask, SIGTERM);
 		pthread_sigmask(SIG_BLOCK, &mask, nullptr);
 
-		// TODO: On first glance it looks redudant with `Runner::active`.
-		std::lock_guard lock {mtx};
+		//? Lock mutex and register cleanup handler to release it on thread cancellation
+		//? This prevents deadlock when pthread_cancel is called on a stalled thread
+		mtx.lock();
+		pthread_cleanup_push(cleanup_mutex, &mtx);
 
 		//* ----------------------------------------------- THREAD LOOP -----------------------------------------------
 		while (not Global::quitting) {
@@ -725,12 +748,22 @@ namespace Runner {
 
 			//? If overlay isn't empty, print output without color and then print overlay on top
 			const bool term_sync = Config::getB("terminal_sync");
+			// Disable cancellation so pthread_cancel() cannot interrupt between
+			// sync_start and sync_end — an incomplete synchronized frame leaves
+			// the terminal holding a stale
+			// image indefinitely (observed on macOS Terminal.app).
+			int old_cancel_state = PTHREAD_CANCEL_ENABLE;
+			pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);
 			cout << (term_sync ? Term::sync_start : "") << (conf.overlay.empty()
 					? output
 					: (output.empty() ? "" : Fx::ub + Theme::c("inactive_fg") + Fx::uncolor(output)) + conf.overlay)
 				<< (term_sync ? Term::sync_end : "") << flush;
+			pthread_setcancelstate(old_cancel_state, nullptr);
 		}
 		//* ----------------------------------------------- THREAD LOOP -----------------------------------------------
+
+		//? Pop cleanup handler and execute it (unlocks the mutex)
+		pthread_cleanup_pop(1);
 		return {};
 	}
 	//? ------------------------------------------ Secondary thread end -----------------------------------------------
@@ -744,6 +777,9 @@ namespace Runner {
 			// exit(1);
 			pthread_cancel(Runner::runner_id);
 
+			//? Wake thread from sem_wait so it can process the cancellation
+			thread_trigger();
+
 			// Wait for the thread to actually terminate before creating a new one
 			void* thread_result;
 			int join_result = pthread_join(Runner::runner_id, &thread_result);
