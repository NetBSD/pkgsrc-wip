$NetBSD$

--- engine/source/network/serverQuery.cc.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/network/serverQuery.cc
@@ -1459,7 +1459,7 @@ static void handleGameMasterInfoRequest(
       temp32 = getVersionNumber();
       out->write( temp32 );
       temp8 = 0;
-#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD)
+#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
       temp8 |= ServerInfo::Status_Linux;
 #endif
       if ( Con::getBoolVariable( "Server::Dedicated" ) )
@@ -1717,7 +1717,7 @@ static void handleGameInfoRequest( const
       }
 
       U8 status = 0;
-#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD)
+#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
       status |= ServerInfo::Status_Linux;
 #endif
       if ( Con::getBoolVariable( "Server::Dedicated" ) )
