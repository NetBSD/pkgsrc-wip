# $NetBSD$

BUILDLINK_TREE+=	kwindowsystem

.if !defined(KWINDOWSYSTEM_BUILDLINK3_MK)
KWINDOWSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwindowsystem+=	kwindowsystem>=5.18.0
BUILDLINK_PKGSRCDIR.kwindowsystem?=	../../wip/kwindowsystem

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KWINDOWSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwindowsystem
