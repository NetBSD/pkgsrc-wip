$NetBSD$

--- src/VBox/Main/src-server/ApplianceImpl.cpp.orig	2016-03-04 19:29:39.000000000 +0000
+++ src/VBox/Main/src-server/ApplianceImpl.cpp
@@ -138,6 +138,7 @@ g_osTypes[] =
     { ovf::CIMOSType_CIMOS_MicrosoftWindowsServer2008,           VBOXOSTYPE_Win2k8 },
     { ovf::CIMOSType_CIMOS_MicrosoftWindowsServer2008_64,        VBOXOSTYPE_Win2k8_x64 },
     { ovf::CIMOSType_CIMOS_FreeBSD_64,                           VBOXOSTYPE_FreeBSD_x64 },
+    { ovf::CIMOSType_CIMOS_NetBSD_64,                            VBOXOSTYPE_NetBSD_x64 },
     { ovf::CIMOSType_CIMOS_MACOS,                                VBOXOSTYPE_MacOS },
     { ovf::CIMOSType_CIMOS_MACOS,                                VBOXOSTYPE_MacOS_x64 }, // there is no CIM 64-bit type for this
     { ovf::CIMOSType_CIMOS_MACOS,                                VBOXOSTYPE_MacOS106 },
@@ -263,6 +264,7 @@ static const osTypePattern g_osTypesPatt
     {"OpenSolaris",   VBOXOSTYPE_OpenSolaris_x64},
     {"Solaris",       VBOXOSTYPE_OpenSolaris_x64},
     {"FreeBSD",       VBOXOSTYPE_FreeBSD_x64},
+    {"NetBSD",        VBOXOSTYPE_NetBSD_x64},
 };
 
 /**
@@ -1695,4 +1697,3 @@ const settings::MachineConfigFile* Virtu
 {
     return m->pConfig;
 }
-
