# $NetBSD$

BUILDLINK_TREE+=	kcalcore

.if !defined(KCALCORE_BUILDLINK3_MK)
KCALCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcalcore+=	kcalcore>=17.12.1
BUILDLINK_PKGSRCDIR.kcalcore?=	../../wip/kcalcore

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCALCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcalcore
