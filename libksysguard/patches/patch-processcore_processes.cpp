$NetBSD: patch-libs_ksysguard_processcore_processes.cpp,v 1.1 2012/03/19 19:44:04 markd Exp $

--- processcore/processes.cpp.orig	2016-04-19 11:13:53.000000000 +0000
+++ processcore/processes.cpp
@@ -162,6 +162,7 @@ bool Processes::updateProcess( Process *
 }
 
 bool Processes::updateProcessInfo(Process *ps) {
+#ifndef Q_OS_NETBSD
     //Now we can actually get the process info
     qlonglong oldUserTime = ps->userTime();
     qlonglong oldSysTime = ps->sysTime();
@@ -181,6 +182,7 @@ bool Processes::updateProcessInfo(Proces
         oldIoCharactersActuallyRead = ps->ioCharactersActuallyRead();
         oldIoCharactersActuallyWritten = ps->ioCharactersActuallyWritten();
     }
+#endif
 
     ps->setChanges(Process::Nothing);
     bool success;
@@ -206,6 +208,7 @@ bool Processes::updateProcessInfo(Proces
         }
 #endif
         if(d->mUpdateFlags.testFlag(Processes::IOStatistics)) {
+#ifndef Q_OS_NETBSD
             if( d->mHavePreviousIoValues ) {
                 ps->setIoCharactersReadRate((ps->ioCharactersRead() - oldIoCharactersRead) * 1000.0 / elapsedTime);
                 ps->setIoCharactersWrittenRate((ps->ioCharactersWritten() - oldIoCharactersWritten) * 1000.0 / elapsedTime);
@@ -215,6 +218,7 @@ bool Processes::updateProcessInfo(Proces
                 ps->setIoCharactersActuallyWrittenRate((ps->ioCharactersActuallyWritten() - oldIoCharactersActuallyWritten) * 1000.0 / elapsedTime);
             } else
                 d->mHavePreviousIoValues = true;
+#endif
         } else if(d->mHavePreviousIoValues) {
             d->mHavePreviousIoValues = false;
             ps->setIoCharactersReadRate(0);
