# $NetBSD: buildlink3.mk,v 1.3 2015/04/09 02:50:51 krytarowski Exp $
#

BUILDLINK_TREE+=	mate-settings-daemon

.if !defined(MATE_SETTINGS_DAEMON_BUILDLINK3_MK)
MATE_SETTINGS_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-settings-daemon+=	mate-settings-daemon>=1.8.1
BUILDLINK_PKGSRCDIR.mate-settings-daemon?=	../../wip/mate-settings-daemon

#.include "../../wip/libmatekbd/buildlink3.mk"
#.include "../../wip/mate-desktop/buildlink3.mk"
#.include "../../audio/libcanberra/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/dconf/buildlink3.mk"
#.include "../../fonts/fontconfig/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../sysutils/libnotify/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
#.include "../../x11/libXext/buildlink3.mk"
#.include "../../x11/libXi/buildlink3.mk"
#.include "../../x11/libXxf86misc/buildlink3.mk"
#.include "../../x11/kbproto/buildlink3.mk"
#.include "../../x11/libxklavier/buildlink3.mk"
.endif	# MATE_SETTINGS_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-settings-daemon
