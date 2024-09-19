$NetBSD$

Unnecessary and breaks NetBSD which doesnt have x86_64
or 32 in uname.

--- resources/install/generic/run.sh.orig	2013-11-01 15:37:21.000000000 +0000
+++ resources/install/generic/run.sh
@@ -1,15 +1,4 @@
 mkdir -p $HOME/.sip-communicator/log
 
-# Get architecture
-ARCH=`uname -m | sed -e s/x86_64/64/ -e s/i.86/32/`
-
-# Additionnal JVM arguments
-CLIENTARGS=""
-
-if [ $ARCH -eq 32 ]
-then
-    CLIENTARGS="-client -Xmx256m"
-fi
-
 export PATH=$PATH:native
 java $CLIENTARGS -classpath "lib/felix.jar:sc-bundles/sc-launcher.jar:sc-bundles/util.jar:lib/" -Djava.library.path=native -Dfelix.config.properties=file:./lib/felix.client.run.properties -Djava.util.logging.config.file=lib/logging.properties net.java.sip.communicator.launcher.SIPCommunicator
