# $NetBSD$

BUILDLINK_TREE+=	muffin

.if !defined(MUFFIN_BUILDLINK3_MK)
MUFFIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.muffin+=	muffin>=4.6.2
BUILDLINK_PKGSRCDIR.muffin?=	../../wip/muffin

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"
.endif	# MUFFIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-muffin
