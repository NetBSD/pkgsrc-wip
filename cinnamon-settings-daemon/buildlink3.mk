# $NetBSD$

BUILDLINK_TREE+=	cinnamon-settings-daemon

.if !defined(CINNAMON_SETTINGS_DAEMON_BUILDLINK3_MK)
CINNAMON_SETTINGS_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-settings-daemon+=	cinnamon-settings-daemon>=3.0.1
BUILDLINK_PKGSRCDIR.cinnamon-settings-daemon?=		../../wip/cinnamon-settings-daemon

.include "../../print/cups-base/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../wip/libgnomekbd/buildlink3.mk"
.include "../../wip/colord/buildlink3.mk"
.endif	# CINNAMON_SETTINGS_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-settings-daemon
