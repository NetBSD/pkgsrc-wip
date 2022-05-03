--- ../vendor/battery-0.7.8/src/platform/freebsd/iterator.rs.orig	2022-05-03 23:18:05.176446147 +0200
+++ ../vendor/battery-0.7.8/src/platform/freebsd/iterator.rs	2022-05-03 23:18:47.016514365 +0200
@@ -5,6 +5,7 @@
 use super::{IoCtlDevice, IoCtlManager};
 use crate::platform::traits::BatteryIterator;
 use crate::Result;
+use libc;
 
 pub struct IoCtlIterator {
     manager: Rc<IoCtlManager>,
