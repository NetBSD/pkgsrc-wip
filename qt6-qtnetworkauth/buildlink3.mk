# $NetBSD$

BUILDLINK_TREE+=	qt6-qtnetworkauth

.if !defined(QT6_QTNETWORKAUTH_BUILDLINK3_MK)
QT6_QTNETWORKAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtnetworkauth+=	qt6-qtnetworkauth>=6.0.1
BUILDLINK_PKGSRCDIR.qt6-qtnetworkauth?=		../../wip/qt6-qtnetworkauth

.include "../../wip/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTNETWORKAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtnetworkauth
