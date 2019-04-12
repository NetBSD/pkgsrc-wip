$NetBSD$

	Tape alerts where not always gathered, add missing cases.

--- core/src/plugins/stored/scsitapealert-sd.cc.orig	2019-03-14 14:18:24.617761851 +0000
+++ core/src/plugins/stored/scsitapealert-sd.cc
@@ -191,8 +191,11 @@ static bRC handlePluginEvent(bpContext *
    case bsdEventLabelVerified:
    case bsdEventReadError:
    case bsdEventWriteError:
+   case bsdEventVolumeLoad:
    case bsdEventVolumeUnload:
+   case bsdEventDeviceRelease:
       return handle_tapealert_readout(value);
+
    default:
       Dmsg1(debuglevel, "scsitapealert-sd: Unknown event %d\n", event->eventType);
       return bRC_Error;
