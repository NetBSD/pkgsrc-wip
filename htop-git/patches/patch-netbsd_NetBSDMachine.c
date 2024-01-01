$NetBSD$

Fix build due to upstream changes.

https://github.com/htop-dev/htop/pull/1360

--- netbsd/NetBSDMachine.c.orig	2023-12-29 15:52:13.000000000 +0000
+++ netbsd/NetBSDMachine.c
@@ -81,7 +81,7 @@ static void NetBSDMachine_updateCPUcount
    }
 
    if (value != super->existingCPUs) {
-      opl->cpuData = xReallocArray(this->cpuData, value + 1, sizeof(CPUData));
+      this->cpuData = xReallocArray(this->cpuData, value + 1, sizeof(CPUData));
       super->existingCPUs = value;
       change = true;
    }
@@ -127,7 +127,7 @@ Machine* Machine_new(UsersTable* usersTa
       CRT_fatalError("kvm_openfiles() failed");
    }
 
-   return this;
+   return super;
 }
 
 void Machine_delete(Machine* super) {
@@ -268,11 +268,11 @@ static void NetBSDMachine_scanCPUFrequen
 void Machine_scan(Machine* super) {
    NetBSDMachine* this = (NetBSDMachine*) super;
 
-   NetBSDProcessTable_scanMemoryInfo(this);
-   NetBSDProcessTable_scanCPUTime(this);
+   NetBSDMachine_scanMemoryInfo(this);
+   NetBSDMachine_scanCPUTime(this);
 
    if (super->settings->showCPUFrequency) {
-      NetBSDProcessTable_scanCPUFrequency(npl);
+      NetBSDMachine_scanCPUFrequency(this);
    }
 }
 
