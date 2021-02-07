# $NetBSD$

BUILDLINK_TREE+=	qt6-qtimageformats

.if !defined(QT6_QTIMAGEFORMATS_BUILDLINK3_MK)
QT6_QTIMAGEFORMATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtimageformats+=	qt6-qtimageformats>=6.0.1
BUILDLINK_PKGSRCDIR.qt6-qtimageformats?=	../../wip/qt6-qtimageformats

.include "../../wip/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTIMAGEFORMATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtimageformats
