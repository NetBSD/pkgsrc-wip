$NetBSD: patch-kio_kio_scheduler.cpp,v 1.1 2012/01/16 22:23:51 absd Exp $
Work around https://bugs.kde.org/show_bug.cgi?id=275584
adjusted from http://old.nabble.com/attachment/31751497/0/kio_scheduler.patch

--- kio/kio/scheduler.cpp.orig	2011-06-30 21:34:17.000000000 +0000
+++ kio/kio/scheduler.cpp
@@ -882,6 +882,41 @@ void Scheduler::emitReparseSlaveConfigur
     emit self()->reparseSlaveConfiguration( QString() );
 }
 
+void Scheduler::slotSlaveDied(Slave* slave)
+{
+    schedulerPrivate->slotSlaveDied(slave);
+}
+
+void Scheduler::slotSlaveStatus(pid_t pid, const QByteArray& protocol, const QString& host, bool connected)
+{
+    schedulerPrivate->slotSlaveStatus(pid, protocol, host, connected);
+}
+
+void Scheduler::slotReparseSlaveConfiguration(const QString& prot, const QDBusMessage& msg)
+{
+    schedulerPrivate->slotReparseSlaveConfiguration(prot, msg);
+}
+
+void Scheduler::slotSlaveOnHoldListChanged()
+{
+    schedulerPrivate->slotSlaveOnHoldListChanged();
+}
+
+void Scheduler::slotSlaveConnected()
+{
+    schedulerPrivate->slotSlaveConnected();
+}
+
+void Scheduler::slotSlaveError(int error, const QString& errorMsg)
+{
+    schedulerPrivate->slotSlaveError(error, errorMsg);
+}
+
+void Scheduler::slotUnregisterWindow(QObject* obj)
+{
+    schedulerPrivate->slotUnregisterWindow(obj);
+}
+
 
 void SchedulerPrivate::slotReparseSlaveConfiguration(const QString &proto, const QDBusMessage&)
 {
