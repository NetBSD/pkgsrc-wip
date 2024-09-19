$NetBSD$
Permit compile and link flags to be passed as well as install directory
--- src/makefiles/openbsd_32bit.mak.orig	2019-05-24 00:18:28.000000000 +0000
+++ src/makefiles/openbsd_32bit.mak
@@ -1,3 +1,4 @@
+
 # SoftEther VPN Source Code
 # 
 # Copyright (c) 2012-2019 SoftEther VPN Project at University of Tsukuba, Japan.
@@ -62,19 +63,28 @@
 
 #CC=gcc
 
-OPTIONS_COMPILE_DEBUG=-D_DEBUG -DDEBUG -DUNIX -DUNIX_BSD -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -I/usr/local/include -g -fsigned-char
+OPTIONS_COMPILE_DEBUG=$(CFLAGS) -D_DEBUG -DDEBUG -DUNIX -DUNIX_BSD -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -I/usr/local/include -g -fsigned-char
+
+OPTIONS_LINK_DEBUG=$(LDFLAGS)-g -fsigned-char -L/usr/local/lib -lm -lpthread -lssl -lcrypto -liconv -lreadline -lncurses -lz
 
-OPTIONS_LINK_DEBUG=-g -fsigned-char -L/usr/local/lib -lm -lpthread -lssl -lcrypto -liconv -lreadline -lncurses -lz
+OPTIONS_COMPILE_RELEASE=$(CFLAGS) -DNDEBUG -DVPN_SPEED -DUNIX -DUNIX_BSD -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -I/usr/local/include -O2 -fsigned-char
 
-OPTIONS_COMPILE_RELEASE=-DNDEBUG -DVPN_SPEED -DUNIX -DUNIX_BSD -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -I/usr/local/include -O2 -fsigned-char
+OPTIONS_LINK_RELEASE=$(LDFLAGS) -O2 -fsigned-char -L/usr/local/lib -lm -lpthread -lssl -lcrypto -liconv -lreadline -lncurses -lz
 
-OPTIONS_LINK_RELEASE=-O2 -fsigned-char -L/usr/local/lib -lm -lpthread -lssl -lcrypto -liconv -lreadline -lncurses -lz
+ifeq ($(PREFIX),)
+PREFIX=/usr/local
+endif
 
-INSTALL_BINDIR=/usr/local/bin/
-INSTALL_VPNSERVER_DIR=/usr/vpnserver/
-INSTALL_VPNBRIDGE_DIR=/usr/vpnbridge/
-INSTALL_VPNCLIENT_DIR=/usr/vpnclient/
-INSTALL_VPNCMD_DIR=/usr/vpncmd/
+BINDIR=$(PREFIX)/bin/
+INSTALL_BINDIR=$(_INSTALL_PREFIX)/$(BINDIR)
+VPNSERVER_DIR=$(PREFIX)/libexec/vpnserver/
+INSTALL_VPNSERVER_DIR=$(_INSTALL_PREFIX)/$(VPNSERVER_DIR)
+VPNBRIDGE_DIR=$(PREFIX)/libexec/vpnbridge/
+INSTALL_VPNBRIDGE_DIR=$(_INSTALL_PREFIX)/$(VPNBRIDGE_DIR)
+VPNCLIENT_DIR=$(PREFIX)/libexec/vpnclient/
+INSTALL_VPNCLIENT_DIR=$(_INSTALL_PREFIX)/$(VPNCLIENT_DIR)
+VPNCMD_DIR=$(PREFIX)/libexec/vpncmd/
+INSTALL_VPNCMD_DIR=$(_INSTALL_PREFIX)/$(VPNCMD_DIR)
 
 ifeq ($(DEBUG),YES)
 	OPTIONS_COMPILE=$(OPTIONS_COMPILE_DEBUG)
@@ -433,7 +443,7 @@ $(INSTALL_BINDIR)vpnserver: bin/vpnserve
 	cp bin/vpnserver/hamcore.se2 $(INSTALL_VPNSERVER_DIR)hamcore.se2
 	cp bin/vpnserver/vpnserver $(INSTALL_VPNSERVER_DIR)vpnserver
 	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpnserver
-	echo $(INSTALL_VPNSERVER_DIR)vpnserver '"$$@"' >> $(INSTALL_BINDIR)vpnserver
+	echo $(VPNSERVER_DIR)vpnserver '"$$@"' >> $(INSTALL_BINDIR)vpnserver
 	echo 'exit $$?' >> $(INSTALL_BINDIR)vpnserver
 	chmod 755 $(INSTALL_BINDIR)vpnserver
 
@@ -442,7 +452,7 @@ $(INSTALL_BINDIR)vpnbridge: bin/vpnbridg
 	cp bin/vpnbridge/hamcore.se2 $(INSTALL_VPNBRIDGE_DIR)hamcore.se2
 	cp bin/vpnbridge/vpnbridge $(INSTALL_VPNBRIDGE_DIR)vpnbridge
 	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpnbridge
-	echo $(INSTALL_VPNBRIDGE_DIR)vpnbridge '"$$@"' >> $(INSTALL_BINDIR)vpnbridge
+	echo $(VPNBRIDGE_DIR)vpnbridge '"$$@"' >> $(INSTALL_BINDIR)vpnbridge
 	echo 'exit $$?' >> $(INSTALL_BINDIR)vpnbridge
 	chmod 755 $(INSTALL_BINDIR)vpnbridge
 
@@ -451,7 +461,7 @@ $(INSTALL_BINDIR)vpnclient: bin/vpnclien
 	cp bin/vpnclient/hamcore.se2 $(INSTALL_VPNCLIENT_DIR)hamcore.se2
 	cp bin/vpnclient/vpnclient $(INSTALL_VPNCLIENT_DIR)vpnclient
 	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpnclient
-	echo $(INSTALL_VPNCLIENT_DIR)vpnclient '"$$@"' >> $(INSTALL_BINDIR)vpnclient
+	echo $(VPNCLIENT_DIR)vpnclient '"$$@"' >> $(INSTALL_BINDIR)vpnclient
 	echo 'exit $$?' >> $(INSTALL_BINDIR)vpnclient
 	chmod 755 $(INSTALL_BINDIR)vpnclient
 
@@ -460,7 +470,7 @@ $(INSTALL_BINDIR)vpncmd: bin/vpncmd/hamc
 	cp bin/vpncmd/hamcore.se2 $(INSTALL_VPNCMD_DIR)hamcore.se2
 	cp bin/vpncmd/vpncmd $(INSTALL_VPNCMD_DIR)vpncmd
 	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpncmd
-	echo $(INSTALL_VPNCMD_DIR)vpncmd '"$$@"' >> $(INSTALL_BINDIR)vpncmd
+	echo $(VPNCMD_DIR)vpncmd '"$$@"' >> $(INSTALL_BINDIR)vpncmd
 	echo 'exit $$?' >> $(INSTALL_BINDIR)vpncmd
 	chmod 755 $(INSTALL_BINDIR)vpncmd
 
