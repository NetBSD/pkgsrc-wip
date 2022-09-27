$NetBSD: patch-src_zm__event.cpp,v 1.2 2018/07/14 15:03:57 gdt Exp $

zoneminder uses %ld for time_t, which is troublesome on NetBSD arm and
presumably i386.  (Note that there are multiple patch files for the
same issue.)

Not yet sent upstream -- needs update to latest release first, where
it might be fixed, or the patch might simply need to be rebased.
Also, this fix is expedient and probably a better fix is appropriate.

Avoid sendfile code when sendfile doesn't exist.

--- src/zm_event.cpp.orig	2018-12-08 14:22:36.000000000 +0000
+++ src/zm_event.cpp
@@ -87,10 +87,10 @@ Event::Event(
 
   char sql[ZM_SQL_MED_BUFSIZ];
   struct tm *stime = localtime(&start_time.tv_sec);
-  snprintf( sql, sizeof(sql), "INSERT INTO Events ( MonitorId, StorageId, Name, StartTime, Width, Height, Cause, Notes, StateId, Orientation, Videoed, DefaultVideo, SaveJPEGs, Scheme ) values ( %d, %d, 'New Event', from_unixtime( %ld ), %d, %d, '%s', '%s', %d, %d, %d, '', %d, '%s' )",
+  snprintf( sql, sizeof(sql), "INSERT INTO Events ( MonitorId, StorageId, Name, StartTime, Width, Height, Cause, Notes, StateId, Orientation, Videoed, DefaultVideo, SaveJPEGs, Scheme ) values ( %d, %d, 'New Event', from_unixtime( %jd ), %d, %d, '%s', '%s', %d, %d, %d, '', %d, '%s' )",
       monitor->Id(), 
       storage->Id(),
-      start_time.tv_sec,
+      (intmax_t) start_time.tv_sec,
       monitor->Width(),
       monitor->Height(),
       cause.c_str(),
@@ -247,8 +247,8 @@ Event::~Event() {
   if ( frames > last_db_frame ) {
     Debug(1, "Adding closing frame %d to DB", frames);
     snprintf(sql, sizeof(sql), 
-        "INSERT INTO Frames ( EventId, FrameId, TimeStamp, Delta ) VALUES ( %" PRIu64 ", %d, from_unixtime( %ld ), %s%ld.%02ld )",
-        id, frames, end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec);
+        "INSERT INTO Frames ( EventId, FrameId, TimeStamp, Delta ) VALUES ( %" PRIu64 ", %d, from_unixtime( %jd ), %s%jd.%02ld )",
+        id, frames, (intmax_t) end_time.tv_sec, delta_time.positive?"":"-", (intmax_t) delta_time.sec, delta_time.fsec);
     db_mutex.lock();
     if ( mysql_query(&dbconn, sql) ) {
       Error("Can't insert frame: %s", mysql_error(&dbconn));
@@ -259,8 +259,8 @@ Event::~Event() {
   }
 
   snprintf(sql, sizeof(sql), 
-      "UPDATE Events SET Name='%s %" PRIu64 "', EndTime = from_unixtime( %ld ), Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d, DefaultVideo = '%s' WHERE Id = %" PRIu64,
-      monitor->EventPrefix(), id, end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, frames, alarm_frames, tot_score, (int)(alarm_frames?(tot_score/alarm_frames):0), max_score, video_name, id );
+      "UPDATE Events SET Name='%s %" PRIu64 "', EndTime = from_unixtime( %jd ), Length = %s%jd.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d, DefaultVideo = '%s' WHERE Id = %" PRIu64,
+      monitor->EventPrefix(), id, (intmax_t) end_time.tv_sec, delta_time.positive?"":"-", (intmax_t) delta_time.sec, delta_time.fsec, frames, alarm_frames, tot_score, (int)(alarm_frames?(tot_score/alarm_frames):0), max_score, video_name, id );
   db_mutex.lock();
   while ( mysql_query(&dbconn, sql) && !zm_terminate ) {
     Error("Can't update event: %s reason: %s", sql, mysql_error(&dbconn));
@@ -479,13 +479,13 @@ void Event::AddFramesInternal( int n_fra
     DELTA_TIMEVAL( delta_time, *(timestamps[i]), start_time, DT_PREC_2 );
     // Delta is Decimal(8,2) so 6 integer digits and 2 decimal digits
     if ( delta_time.sec > 999999 ) {
-      Warning("Invalid delta_time from_unixtime(%ld), %s%ld.%02ld", 
-           timestamps[i]->tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
+      Warning("Invalid delta_time from_unixtime(%jd), %s%jd.%02ld", 
+           (intmax_t) timestamps[i]->tv_sec, delta_time.positive?"":"-", (intmax_t) delta_time.sec, delta_time.fsec );
         delta_time.sec = 0;
     }
 
     int sql_len = strlen(sql);
-    snprintf(sql+sql_len, sizeof(sql)-sql_len, "( %" PRIu64 ", %d, from_unixtime(%ld), %s%ld.%02ld ), ", id, frames, timestamps[i]->tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec);
+    snprintf(sql+sql_len, sizeof(sql)-sql_len, "( %" PRIu64 ", %d, from_unixtime(%jd), %s%jd.%02ld ), ", id, frames, (intmax_t) timestamps[i]->tv_sec, delta_time.positive?"":"-", (intmax_t) delta_time.sec, delta_time.fsec);
 
     frameCount++;
   } // end foreach frame
@@ -548,8 +548,8 @@ Debug(3, "Writing video");
     static char sql[ZM_SQL_MED_BUFSIZ];
     snprintf(sql, sizeof(sql),
         "INSERT INTO Frames ( EventId, FrameId, Type, TimeStamp, Delta, Score )"
-        " VALUES ( %" PRIu64 ", %d, '%s', from_unixtime( %ld ), %s%ld.%02ld, %d )",
-        id, frames, frame_type_names[frame_type], timestamp.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, score);
+        " VALUES ( %" PRIu64 ", %d, '%s', from_unixtime( %jd ), %s%ld.%02jd, %d )",
+        id, frames, frame_type_names[frame_type], (intmax_t) timestamp.tv_sec, delta_time.positive?"":"-", (intmax_t) delta_time.sec, delta_time.fsec, score);
     db_mutex.lock();
     if ( mysql_query(&dbconn, sql) ) {
       Error("Can't insert frame: %s", mysql_error(&dbconn));
@@ -563,9 +563,9 @@ Debug(3, "Writing video");
     // We are writing a Bulk frame
     if ( frame_type == BULK ) {
       snprintf(sql, sizeof(sql), 
-          "UPDATE Events SET Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d where Id = %" PRIu64, 
+          "UPDATE Events SET Length = %s%jd.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d where Id = %" PRIu64, 
           ( delta_time.positive?"":"-" ),
-          delta_time.sec, delta_time.fsec,
+          (intmax_t) delta_time.sec, delta_time.fsec,
           frames, 
           alarm_frames,
           tot_score,
