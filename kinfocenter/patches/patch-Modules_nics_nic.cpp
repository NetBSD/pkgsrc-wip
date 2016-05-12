$NetBSD: patch-kinfocenter_Modules_nics_nic.cpp,v 1.1 2013/06/22 22:39:10 jperkin Exp $

SunOS SIOCGIFHWADDR doesn't do what you think it does.

--- Modules/nics/nic.cpp.orig	2016-04-19 11:09:20.000000000 +0000
+++ Modules/nics/nic.cpp
@@ -213,7 +213,7 @@ QList<MyNIC*> findNICs() {
 
 			ifcopy=*ifr;
 			result=-1; // if none of the two #ifs below matches, ensure that result!=0 so that "Unknown" is returned as result
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 			result=ioctl(sockfd, SIOCGIFHWADDR, &ifcopy);
 			if (result==0) {
 				char *n = &ifcopy.ifr_ifru.ifru_hwaddr.sa_data[0];
