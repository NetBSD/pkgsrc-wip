# $NetBSD: buildlink3.mk,v 1.33 2020/11/04 12:12:48 nia Exp $

BUILDLINK_TREE+=	gnome-desktop40

.if !defined(GNOME_DESKTOP40_BUILDLINK3_MK)
GNOME_DESKTOP40_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-desktop40+=	gnome-desktop40>=3.4.2
BUILDLINK_ABI_DEPENDS.gnome-desktop40+=	gnome-desktop40>=3.36
BUILDLINK_PKGSRCDIR.gnome-desktop40?=	../../wip/gnome-desktop40

BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.27.0
.include "../../wip/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-gnome-desktop40
