$NetBSD$

* map conflicts with map from net/if.h, use std::map explicitly

--- src/lib/dhcpsrv/host_data_source_factory.cc.orig	2019-11-19 14:50:43.000000000 +0000
+++ src/lib/dhcpsrv/host_data_source_factory.cc
@@ -40,7 +40,7 @@ using namespace std;
 namespace isc {
 namespace dhcp {
 
-map<string, HostDataSourceFactory::Factory> HostDataSourceFactory::map_;
+std::map<string, HostDataSourceFactory::Factory> HostDataSourceFactory::map_;
 
 void
 HostDataSourceFactory::add(HostDataSourceList& sources,
