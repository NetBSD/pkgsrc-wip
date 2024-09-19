$NetBSD: patch-owamp_endpoint.c,v 1.1 2015/06/03 00:38:05 mbowie Exp $
Massage macros for time offsets

--- owamp/endpoint.c.orig	2015-06-02 17:00:07.000000000 -0700
+++ owamp/endpoint.c	2015-06-02 17:25:49.000000000 -0700
@@ -1320,7 +1320,11 @@
                 OWPScheduleContextGenerateNextDelta(
                     ep->tsession->sctx));
         OWPNum64ToTimespec(&nexttime,nextoffset);
+#ifndef __NetBSD__
         timespecadd(&nexttime,&ep->start);
+#else
+	timespecadd(&nexttime,&ep->start,&nexttime);
+#endif
         *seq = htonl(i);
 
         /*
@@ -1371,7 +1375,11 @@
              * send time, then skip actually sending.
              */
             latetime = timeout;
+#ifndef __NetBSD__
             timespecadd(&latetime,&nexttime);
+#else
+            timespecadd(&latetime,&nexttime,&latetime);
+#endif
             if(timespeccmp(&currtime,&latetime,>)){
                 skip(ep,i);
                 goto SKIP_SEND;
@@ -1469,7 +1477,11 @@
              */
 
             sleeptime = nexttime;
+#ifndef __NetBSD__
             timespecsub(&sleeptime,&currtime);
+#else
+            timespecsub(&sleeptime,&currtime,&sleeptime);
+#endif
             if((nanosleep(&sleeptime,NULL) == 0) || (errno == EINTR)){
                 goto AGAIN;
             }
@@ -1492,8 +1504,13 @@
             ep->tsession->test_spec.loss_timeout)+1;
 #endif
     latetime = timeout;
+#ifndef __NetBSD__
     timespecadd(&latetime,&nexttime);
     timespecadd(&latetime,&ep->enddelay);
+#else
+    timespecadd(&latetime,&nexttime,&latetime);
+    timespecadd(&latetime,&ep->enddelay,&latetime);
+#endif
 
     while(!owp_usr2 && !owp_int){
         if(!_OWPGetTimespec(ep->cntrl->ctx,&currtime,&esterror,&sync)){
@@ -1506,7 +1523,11 @@
             break;
 
         sleeptime = latetime;
+#ifndef __NetBSD__
         timespecsub(&sleeptime,&currtime);
+#else
+	timespecsub(&sleeptime,&currtime,&sleeptime);
+#endif
 #if NOT
 OWPError(ep->cntrl->ctx,OWPErrFATAL,OWPErrUNKNOWN,
                     "run_sender: end nanosleep(%lu.%lu,nil)",
@@ -1885,8 +1906,13 @@
      * in the missing packet queue should be declared lost.
      */
     timespecclear(&expectspec);
+#ifndef __NetBSD__
     timespecadd(&expectspec,&ep->begin->absolute);
     timespecadd(&expectspec,&lostspec);
+#else
+    timespecadd(&expectspec,&ep->begin->absolute,&expectspec);
+    timespecadd(&expectspec,&lostspec,&expectspec);
+#endif
 
     /*
      * If owp_usr2, then StopSessions has been received. We
@@ -1905,8 +1931,13 @@
      */
     if(owp_usr2){
         timespecclear(&currtime);
+#ifndef __NetBSD__
         timespecadd(&currtime,&expectspec);
         timespecadd(&currtime,&lostspec);
+#else
+        timespecadd(&currtime,&expectspec,&currtime);
+        timespecadd(&currtime,&lostspec,&currtime);
+#endif
     }
 
     /*
@@ -1977,16 +2008,26 @@
         free_node(ep,node);
 
         timespecclear(&expectspec);
+#ifndef __NetBSD__
         timespecadd(&expectspec,&ep->begin->absolute);
         timespecadd(&expectspec,&lostspec);
+#else
+        timespecadd(&expectspec,&ep->begin->absolute,&expectspec);
+        timespecadd(&expectspec,&lostspec,&expectspec);
+#endif
 
         /*
          * StopSessions received: fast-forward currtime
          */
         if(owp_usr2){
             timespecclear(&currtime);
+#ifndef __NetBSD__
             timespecadd(&currtime,&expectspec);
             timespecadd(&currtime,&lostspec);
+#else
+            timespecadd(&currtime,&expectspec,&currtime);
+            timespecadd(&currtime,&lostspec,&currtime);
+#endif
         }
     }
 
@@ -2181,11 +2222,22 @@
          * and not the timer.)
          */
         tvalclear(&wake.it_value);
+#ifndef __NetBSD__
         timespecadd((struct timespec*)&wake.it_value,
                 &ep->end->absolute);
         timespecadd((struct timespec*)&wake.it_value,&lostspec);
         timespecadd((struct timespec*)&wake.it_value,&fudgespec);
         timespecsub((struct timespec*)&wake.it_value,&currtime);
+#else
+        timespecadd((struct timespec*)&wake.it_value,
+                &ep->end->absolute,(struct timespec*)&wake.it_value);
+        timespecadd((struct timespec*)&wake.it_value,&lostspec,
+                (struct timespec*)&wake.it_value);
+        timespecadd((struct timespec*)&wake.it_value,&fudgespec,
+                (struct timespec*)&wake.it_value);
+        timespecsub((struct timespec*)&wake.it_value,&currtime,
+                (struct timespec*)&wake.it_value);
+#endif
 
         wake.it_value.tv_usec /= 1000;        /* convert nsec to usec        */
         tvalclear(&wake.it_interval);
