$NetBSD$

* map conflicts with map from net/if.h, use std::map explicitly

--- src/lib/dhcpsrv/host_data_source_factory.cc.orig	2022-07-26 06:08:02.000000000 +0000
+++ src/lib/dhcpsrv/host_data_source_factory.cc
@@ -36,7 +36,7 @@ using namespace std;
 namespace isc {
 namespace dhcp {
 
-map<string, HostDataSourceFactory::Factory> HostDataSourceFactory::map_;
+std::map<string, HostDataSourceFactory::Factory> HostDataSourceFactory::map_;
 
 void
 HostDataSourceFactory::add(HostDataSourceList& sources,
