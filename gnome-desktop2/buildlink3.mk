# $NetBSD: buildlink3.mk,v 1.63 2020/08/17 20:17:49 leot Exp $

BUILDLINK_TREE+=	gnome-desktop2

.if !defined(GNOME_DESKTOP2_BUILDLINK3_MK)
GNOME_DESKTOP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-desktop2+=	gnome-desktop2>=2.30.0
BUILDLINK_ABI_DEPENDS.gnome-desktop2+=	gnome-desktop2>=2.32.1nb41
BUILDLINK_PKGSRCDIR.gnome-desktop2?=	../../wip/gnome-desktop

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # GNOME_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-desktop2
