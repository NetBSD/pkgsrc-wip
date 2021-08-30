$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/slic3r/GUI/BackgroundSlicingProcess.hpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/slic3r/GUI/BackgroundSlicingProcess.hpp
@@ -213,7 +213,7 @@ private:
 	State 						m_state = STATE_INITIAL;
 
     PrintState<BackgroundSlicingProcessStep, bspsCount>   	m_step_state;
-    mutable tbb::mutex                      				m_step_state_mutex;
+    mutable std::mutex                      				m_step_state_mutex;
 	bool                set_step_started(BackgroundSlicingProcessStep step);
 	void                set_step_done(BackgroundSlicingProcessStep step);
 	bool 				is_step_done(BackgroundSlicingProcessStep step) const;
