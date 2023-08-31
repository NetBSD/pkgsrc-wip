$NetBSD$

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./sasl-scram.el	2005-07-06 11:09:05.000000000 +0900
+++ ././sasl-scram.el	2020-09-05 16:02:39.901895077 +0900
@@ -1,4 +1,4 @@
-;;; sasl-scram.el --- Compute SCRAM-MD5.
+;;; sasl-scram.el --- Compute SCRAM-MD5.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1999 Shuhei KOBAYASHI
 
@@ -204,7 +204,7 @@
       (fillarray server-salt 0)
       (fillarray buff 0))))
 
-(defun sasl-scram-md5-response-1 (client step)
+(defun sasl-scram-md5-response-1 (client _step)
   (sasl-client-set-property
    client 'client-msg-1
    (sasl-scram-md5-make-client-msg-1
