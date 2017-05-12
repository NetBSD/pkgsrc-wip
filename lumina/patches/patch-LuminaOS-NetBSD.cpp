$NetBSD$
--- src-qt5/core/libLumina/LuminaOS-NetBSD.cpp.orig	2017-01-06 14:07:19.000000000 +0000
+++ src-qt5/core/libLumina/LuminaOS-NetBSD.cpp	2017-05-12 22:27:09.606898568 +0000
@@ -11,6 +11,8 @@
 
 QString LOS::OSName(){ return "NetBSD"; }
 
+static int screenbrightness=-1;
+
 //OS-specific prefix(s)
 // NOTE: PREFIX, L_ETCDIR, L_SHAREDIR are defined in the OS-detect.pri project file and passed in
 QString LOS::LuminaShare(){ return (L_SHAREDIR+"/lumina-desktop/"); } //Install dir for Lumina share files
@@ -31,36 +33,117 @@
 QStringList LOS::ExternalDevicePaths(){
     //Returns: QStringList[<type>::::<filesystem>::::<path>]
       //Note: <type> = [USB, HDRIVE, DVD, SDCARD, UNKNOWN]
-	
-  //Not implemented yet
-  return QStringList();
+  QStringList devs = LUtils::getCmdOutput("mount");
+  //Now check the output
+  for(int i=0; i<devs.length(); i++){
+      QString type = devs[i].section(" ",0,0);
+      type.remove("/dev/");
+      //Determine the type of hardware device based on the dev node
+      if(type.startsWith("sd")||type.startsWith("wd")){ type = "HDRIVE"; }
+      else if(type.startsWith("cd")){ type="DVD"; }
+      else{ type = "UNKNOWN"; }
+      //Now put the device in the proper output format
+      QString fs = devs[i].section(" ", 4, 4);
+      QString path = devs[i].section(" ",2, 2);
+      if (!fs.isEmpty() ) {   //we not found a filesystem, most probably this is an invalid row
+          devs[i] = type+"::::"+fs+"::::"+path;
+      }
+      else {
+          devs.removeAt(i);
+          i--; 
+      }
+  }
+  return devs;
 }
 
 //Read screen brightness information
 int LOS::ScreenBrightness(){
-  //Returns: Screen Brightness as a percentage (0-100, with -1 for errors)
-  return -1;  //not implemented yet
+ //Returns: Screen Brightness as a percentage (0-100, with -1 for errors)
+  //Make sure we are not running in a VM (does not work)
+  QStringList info = LUtils::getCmdOutput("sysctl -n machdep.dmi.system-product");
+  if( !info.filter(QRegExp("VirtualBox|KVM")).isEmpty() ){ return -1; }
+  //Now perform the standard brightness checks
+  if(screenbrightness==-1){
+    if(QFile::exists(QString(getenv("XDG_CONFIG_HOME"))+"/lumina-desktop/.currentxbrightness")){
+      int val = LUtils::readFile(QString(getenv("XDG_CONFIG_HOME"))+"/lumina-desktop/.currentxbrightness").join("").simplified().toInt();
+      screenbrightness = val;
+    }
+  }
+  return screenbrightness;	
 }
 
 //Set screen brightness
 void LOS::setScreenBrightness(int percent){
-  //not implemented yet
+  //ensure bounds
+  if(percent<0){percent=0;}
+  else if(percent>100){ percent=100; }
+  //Run the command
+  QString cmd = "xbacklight -time 0 -steps 1 -set %1";
+  cmd = cmd.arg( QString::number(percent) );
+  int ret = LUtils::runCmd(cmd);
+  //Save the result for later
+  if(ret!=0){ screenbrightness = -1; }
+  else{ screenbrightness = percent; }
+  LUtils::writeFile(QString(getenv("XDG_CONFIG_HOME"))+"/lumina-desktop/.currentxbrightness", QStringList() << QString::number(screenbrightness), true);
 }
 
 //Read the current volume
 int LOS::audioVolume(){ 
   //Returns: audio volume as a percentage (0-100, with -1 for errors)
-  return -1; //Not implemented yet
+  QString info = LUtils::getCmdOutput("mixerctl -n outputs.master").join(",").simplified(); //ignores any other lines
+  int out = -1;
+  if(!info.isEmpty()){
+    int L = info.section(",",0,0).toInt();
+    int R = info.section(",",1,1).toInt();
+    L = (L*100)/255; //percent
+    R = (R*100)/255; //percent
+    if(L>R){ out = L; }
+    else{ out = R; }
+  }
+  return out;
 }
 
 //Set the current volume
 void LOS::setAudioVolume(int percent){
-  //not implemented yet
+ if(percent<0){percent=0;}
+  else if(percent>100){percent=100;}
+  QString info = LUtils::getCmdOutput("mixerctl -n outputs.master").join(",").simplified(); //ignores any other lines
+  if(!info.isEmpty()){
+    int L = info.section(",",0,0).toInt();
+    int R = info.section(",",1,1).toInt();
+    L = (L*100)/255; //percent
+    R = (R*100)/255; //percent
+    int diff = L-R;
+    if(diff<0){ R=percent; L=percent+diff; } //R Greater
+    else{ L=percent; R=percent-diff; } //L Greater or equal
+    //Check bounds
+    if(L<0){L=0;}else if(L>100){L=100;}
+    if(R<0){R=0;}else if(R>100){R=100;}
+    //Run Command
+    L = (L*255)/100; //0-255
+    R = (R*255)/100; //0-255
+    LUtils::runCmd("mixerctl -q outputs.master="+QString::number(L)+","+QString::number(R));
+  }    
 }
 
 //Change the current volume a set amount (+ or -)
 void LOS::changeAudioVolume(int percentdiff){
-  //not implemented yet
+  QString info = LUtils::getCmdOutput("mixerctl -n outputs.master").join(",").simplified(); //ignores any other lines
+  if(!info.isEmpty()){
+    int L = info.section(",",0,0).toInt();
+    int R = info.section(",",1,1).toInt();
+    L = (L*100)/255; //percent
+    R = (R*100)/255; //percent
+    L = L + percentdiff;
+    R = R + percentdiff;
+    //Check bounds
+    if(L<0){L=0;}else if(L>100){L=100;}
+    if(R<0){R=0;}else if(R>100){R=100;}
+    //Run Command
+    L = (L*255)/100; //0-255
+    R = (R*255)/100; //0-255
+    LUtils::runCmd("mixerctl -q outputs.master="+QString::number(L)+","+QString::number(R));
+  }
 }
 
 //Check if a graphical audio mixer is installed
@@ -102,32 +185,32 @@
 
 //Check for suspend support
 bool LOS::systemCanSuspend(){
-  return false;
+  return false;//if exist s3, s4 or s5 in sysctl hc.acpi.sleep.states
 }
 
 //Put the system into the suspend state
 void LOS::systemSuspend(){
-
+//use sysctl -w hw.acpi.sleep.states=3
 }
 
 //Battery Availability
 bool LOS::hasBattery(){
-  return false; //not implemented yet
+  return false; //not implemented yet, use envsys framework
 }
 
 //Battery Charge Level
 int LOS::batteryCharge(){ //Returns: percent charge (0-100), anything outside that range is counted as an error
-  return -1;  //not implemented yet
+  return -1;  //not implemented yet, use envsys framework
 }
 
 //Battery Charging State
 bool LOS::batteryIsCharging(){
-  return false; //not implemented yet
+  return false; //not implemented yet, use envsys framework
 }
 
 //Battery Time Remaining
 int LOS::batterySecondsLeft(){ //Returns: estimated number of seconds remaining
-  return 0; //not implemented yet
+  return 0; //not implemented yet, use envsys framework
 }
 
 //File Checksums
@@ -163,7 +246,7 @@
 }
 
 QStringList LOS::CPUTemperatures(){ //Returns: List containing the temperature of any CPU's ("50C" for example)
-  return QStringList(); //not implemented yet
+  return QStringList(); //not implemented yet, use envsys framework
 }
 
 int LOS::CPUUsagePercent(){ //Returns: Overall percentage of the amount of CPU cycles in use (-1 for errors)
