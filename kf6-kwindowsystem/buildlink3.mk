# $NetBSD$

BUILDLINK_TREE+=	kf6-kwindowsystem

.if !defined(KF6_KWINDOWSYSTEM_BUILDLINK3_MK)
KF6_KWINDOWSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kwindowsystem+=	kf6-kwindowsystem>=6.0.0
BUILDLINK_PKGSRCDIR.kf6-kwindowsystem?=	../../wip/kf6-kwindowsystem

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.endif	# KF6_KWINDOWSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kwindowsystem
