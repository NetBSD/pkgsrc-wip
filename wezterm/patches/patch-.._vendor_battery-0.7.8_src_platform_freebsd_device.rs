--- ../vendor/battery-0.7.8/src/platform/freebsd/device.rs.orig	2022-05-03 23:17:58.214050268 +0200
+++ ../vendor/battery-0.7.8/src/platform/freebsd/device.rs	2022-05-03 23:18:32.888859036 +0200
@@ -5,6 +5,7 @@
 use crate::platform::traits::BatteryDevice;
 use crate::units::{ElectricPotential, Energy, Power, ThermodynamicTemperature};
 use crate::{Result, State, Technology};
+use libc;
 
 #[derive(Default)]
 pub struct IoCtlDevice {
