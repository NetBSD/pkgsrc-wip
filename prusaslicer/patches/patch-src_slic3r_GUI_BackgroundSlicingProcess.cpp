$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/slic3r/GUI/BackgroundSlicingProcess.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/slic3r/GUI/BackgroundSlicingProcess.cpp
@@ -465,7 +465,7 @@ void BackgroundSlicingProcess::schedule_
 		return;
 
 	// Guard against entering the export step before changing the export path.
-	tbb::mutex::scoped_lock lock(m_print->state_mutex());
+	std::scoped_lock<std::mutex> lock(m_print->state_mutex());
 	this->invalidate_step(bspsGCodeFinalize);
 	m_export_path = path;
 	m_export_path_on_removable_media = export_path_on_removable_media;
@@ -478,7 +478,7 @@ void BackgroundSlicingProcess::schedule_
 		return;
 
 	// Guard against entering the export step before changing the export path.
-	tbb::mutex::scoped_lock lock(m_print->state_mutex());
+	std::scoped_lock<std::mutex> lock(m_print->state_mutex());
 	this->invalidate_step(bspsGCodeFinalize);
 	m_export_path.clear();
 	m_upload_job = std::move(upload_job);
@@ -491,7 +491,7 @@ void BackgroundSlicingProcess::reset_exp
 		m_export_path.clear();
 		m_export_path_on_removable_media = false;
 		// invalidate_step expects the mutex to be locked.
-		tbb::mutex::scoped_lock lock(m_print->state_mutex());
+		std::scoped_lock<std::mutex> lock(m_print->state_mutex());
 		this->invalidate_step(bspsGCodeFinalize);
 	}
 }
