# $NetBSD: buildlink3.mk,v 1.1 2015/04/11 11:18:17 krytarowski Exp $

BUILDLINK_TREE+=	libqtxdg

.if !defined(LIBQTXDG_BUILDLINK3_MK)
LIBQTXDG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libqtxdg+=	libqtxdg>=1.2.0
BUILDLINK_PKGSRCDIR.libqtxdg?=		../../wip/libqtxdg

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBQTXDG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libqtxdg
