# $NetBSD: buildlink3.mk,v 1.1 2015/01/01 07:52:39 obache Exp $

BUILDLINK_TREE+=	libindicator-gtk2

.if !defined(LIBINDICATOR_GTK2_BUILDLINK3_MK)
LIBINDICATOR_GTK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libindicator-gtk2+=	libindicator-gtk2>=12.10.1
BUILDLINK_PKGSRCDIR.libindicator-gtk2?=	../../wip/libindicator-gtk2

.include "../../x11/gtk2/buildlink3.mk"
.endif	# LIBINDICATOR_GTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libindicator-gtk2
