# $NetBSD: buildlink3.mk,v 1.1 2014/10/15 17:56:40 nros Exp $
#

BUILDLINK_TREE+=	qt5-libqtlua

.if !defined(QT5_LIBQTLUA_BUILDLINK3_MK)
QT5_LIBQTLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-libqtlua+=	qt5-libqtlua>=2.0
BUILDLINK_PKGSRCDIR.qt5-libqtlua?=	../../wip/qt5-libqtlua

.include "../../lang/lua51/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_LIBQTLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-libqtlua
