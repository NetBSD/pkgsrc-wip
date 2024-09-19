$NetBSD: patch-lib_pib.scm,v 1.2 2015/05/28 05:38:12 phonohawk Exp $

Fix a race-condition on the send queue:
https://github.com/ayamada/copy-of-svn.tir.jp/pull/1

--- lib/pib.scm.orig	2009-09-28 16:03:37.000000000 +0000
+++ lib/pib.scm
@@ -461,10 +461,6 @@
      :accessor irc-recv-cv-of)
    (irc-send-cv
      :accessor irc-send-cv-of)
-   (irc-recv-cv-mutex
-     :accessor irc-recv-cv-mutex-of)
-   (irc-send-cv-mutex
-     :accessor irc-send-cv-mutex-of)
    (irc-send-laststatus
      :accessor irc-send-laststatus-of)
    (irc-send-last-microsec
@@ -509,23 +505,23 @@
 (define-method %irc-recv-event! ((self <pib>) . opts)
   (let-optionals* opts ((timeout 0))
     (let loop ()
-      (mutex-lock! (irc-recv-cv-mutex-of self))
+      (mutex-lock! (irc-recv-queue-mutex-of self))
       (let1 event (irc-recv-dequeue! self)
         (if (or event (equal? timeout 0))
           ;; ���塼���ͤ����äƤ��� or timeout��0���ä���
           ;; �����������̤˥����å����ƽ�λ
           (begin
-            (mutex-unlock! (irc-recv-cv-mutex-of self))
+            (mutex-unlock! (irc-recv-queue-mutex-of self))
             event)
           ;; event��#f���ä����Ĥޤꡢ���塼�϶����ä�
           (let1 start-usec (gettimeofday-usec)
             ;; ��������åɤ�����eof�������äƽ�λ���Ƥ����ʤ顢
             ;; �����ǥ��顼�㳰���ꤲ��ɬ�פ�����
             (when (irc-finished?-of self)
-              (mutex-unlock! (irc-recv-cv-mutex-of self))
+              (mutex-unlock! (irc-recv-queue-mutex-of self))
               (error "irc socket already closed"))
             ;; ���塼�����ʤΤǡ������ॢ����ͭ���cv�����ʥ���Ԥ�
-            (if (not (mutex-unlock! (irc-recv-cv-mutex-of self)
+            (if (not (mutex-unlock! (irc-recv-queue-mutex-of self)
                                     (irc-recv-cv-of self)
                                     timeout))
               ;; �����ॢ���Ȥ���
@@ -750,19 +746,19 @@
 
 ;; ���塼�����λ���#f���֤�(���塼��#f�����äƤ������̵����ΤȤ���)
 (define-method irc-send-dequeue! ((self <pib>))
-  (with-locking-mutex
-    (irc-send-queue-mutex-of self)
-    (lambda ()
-      (if (queue-empty? (irc-send-queue-of self))
+  (let1 state (mutex-state (irc-send-queue-mutex-of self))
+    (unless (eq? state (current-thread))
+      (error "assertion failed: irc-send-queue-mutex is not locked by the caller:" state))
+    (if (queue-empty? (irc-send-queue-of self))
         #f
-        (dequeue! (irc-send-queue-of self))))))
+        (dequeue! (irc-send-queue-of self)))))
 (define-method irc-recv-dequeue! ((self <pib>))
-  (with-locking-mutex
-    (irc-recv-queue-mutex-of self)
-    (lambda ()
-      (if (queue-empty? (irc-recv-queue-of self))
+  (let1 state (mutex-state (irc-recv-queue-mutex-of self))
+    (unless (eq? state (current-thread))
+      (error "assertion failed: irc-recv-queue-mutex is not locked by the caller:" state))
+    (if (queue-empty? (irc-recv-queue-of self))
         #f
-        (dequeue! (irc-recv-queue-of self))))))
+        (dequeue! (irc-recv-queue-of self)))))
 
 (define-method irc-send-enqueue! ((self <pib>) event)
   ;; �������塼�ϡ����λ����ǰ�ö�Ѵ���Ԥ������顼���Фʤ������ǧ����
@@ -855,7 +851,7 @@
 
 (define-method %irc-send-thread ((self <pib>))
   (let loop ()
-    (mutex-lock! (irc-send-cv-mutex-of self))
+    (mutex-lock! (irc-send-queue-mutex-of self))
     (let* ((event (and-let* ((e (irc-send-dequeue! self)))
                     (send-event-split-last-param e)))
            (message (and
@@ -868,7 +864,7 @@
       (cond
         ;((eq? message 'shutdown) #f) ; ��λ(�쥳����)
         ((not message) ; ���塼�������ä�(cv�����ʥ���Ԥ�)
-         (mutex-unlock! (irc-send-cv-mutex-of self) (irc-send-cv-of self))
+         (mutex-unlock! (irc-send-queue-mutex-of self) (irc-send-cv-of self))
          (loop)) ; cv�����ʥ���������塼�����å����ʳ�����Ƽ¹Ԥ���
         (else ; �̾�message���ä�
           ;; �ޤ���(irc-send-last-microsec-of self)������å�����
@@ -883,7 +879,7 @@
                 (dynamic-wind
                   (lambda ()
                     ;; ��ö�����å�����
-                    (mutex-unlock! (irc-send-cv-mutex-of self)))
+                    (mutex-unlock! (irc-send-queue-mutex-of self)))
                   (lambda ()
                     ;; �Ԥ�
                     ;; TODO: �����Ͼ��衢cthreads���б������ݤˡ�
@@ -892,7 +888,7 @@
                     (selector-select (make <selector>) remain))
                   (lambda ()
                     ;; ���٥�å�����
-                    (mutex-lock! (irc-send-cv-mutex-of self)))))))
+                    (mutex-lock! (irc-send-queue-mutex-of self)))))))
           ;; ��������
           (guard (e (else
                       (set! (irc-send-laststatus-of self) 'error)
@@ -919,7 +915,7 @@
                                   (cdddr event))
             (logging self sent-event))
           ;; �����å�����
-          (mutex-unlock! (irc-send-cv-mutex-of self))
+          (mutex-unlock! (irc-send-queue-mutex-of self))
           (loop))))))
 
 (define-method %irc-pong-thread ((self <pib>))
@@ -1100,10 +1096,6 @@
                 (make-condition-variable "recv"))
               (set! (irc-send-cv-of pib)
                 (make-condition-variable "send"))
-              (set! (irc-recv-cv-mutex-of pib)
-                (make-mutex "recv-cv"))
-              (set! (irc-send-cv-mutex-of pib)
-                (make-mutex "send-cv"))
               (set! (irc-send-laststatus-of pib) 'ok)
               (set! (irc-send-last-microsec-of pib) 0)
               (set! (irc-logger-mutex-of pib)
@@ -1177,8 +1169,6 @@
               (set! (irc-send-queue-mutex-of pib) #f)
               (set! (irc-recv-cv-of pib) #f)
               (set! (irc-send-cv-of pib) #f)
-              (set! (irc-recv-cv-mutex-of pib) #f)
-              (set! (irc-send-cv-mutex-of pib) #f)
               (set! (irc-send-laststatus-of pib) #f)
               (set! (irc-send-last-microsec-of pib) #f)
               (set! (irc-logger-mutex-of pib) #f)
