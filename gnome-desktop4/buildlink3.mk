# $NetBSD: buildlink3.mk,v 1.33 2020/11/04 12:12:48 nia Exp $

BUILDLINK_TREE+=	gnome-desktop4

.if !defined(GNOME_DESKTOP4_BUILDLINK3_MK)
GNOME_DESKTOP4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-desktop4+=	gnome-desktop4>=44.1
BUILDLINK_ABI_DEPENDS.gnome-desktop4+=	gnome-desktop4>=44.1
BUILDLINK_PKGSRCDIR.gnome-desktop4?=	../../wip/gnome-desktop4

.if ${OPSYS}=="Linux"
.include "../../wip/mk/libseccomp.buildlink3.mk"
.endif
BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.27.0
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gnome-desktop4
