# $NetBSD$

BUILDLINK_TREE+=	qt6-qtlanguageserver

.if !defined(QT6_QTLANGUAGESERVER_BUILDLINK3_MK)
QT6_QTLANGUAGESERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtlanguageserver+=	qt6-qtlanguageserver>=6.4.0
BUILDLINK_PKGSRCDIR.qt6-qtlanguageserver?=	../../wip/qt6-qtlanguageserver

.include "../../wip/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTLANGUAGESERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtlanguageserver
