# $NetBSD: buildlink3.mk,v 1.1 2015/04/11 14:44:40 krytarowski Exp $

BUILDLINK_TREE+=	kguiaddons

.if !defined(KGUIADDONS_BUILDLINK3_MK)
KGUIADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kguiaddons+=	kguiaddons>=5.9.0
BUILDLINK_PKGSRCDIR.kguiaddons?=	../../wip/kguiaddons

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KGUIADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kguiaddons
