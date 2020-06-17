# $NetBSD$

BUILDLINK_TREE+=	mutter

.if !defined(MUTTER_BUILDLINK3_MK)
MUTTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mutter+=	mutter>=3.36.3
BUILDLINK_PKGSRCDIR.mutter?=	../../wip/mutter

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
#.include "../../x11/libSM/buildlink3.mk"
#.include "../../wip/libinput/buildlink3.mk"
#.include "../../audio/libcanberra/buildlink3.mk"
#.include "../../x11/libICE/buildlink3.mk"
#.include "../../x11/libxkbfile/buildlink3.mk"
#.include "../../wip/gnome-desktop3/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
#.include "../../wip/gnome-settings-daemon/buildlink3.mk"
#.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/graphene/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# MUTTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mutter
