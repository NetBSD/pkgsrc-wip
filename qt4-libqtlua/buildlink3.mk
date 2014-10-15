# $NetBSD: buildlink3.mk,v 1.1 2014/10/15 17:53:35 nros Exp $
#

BUILDLINK_TREE+=	qt4-libqtlua

.if !defined(QT4_LIBQTLUA_BUILDLINK3_MK)
QT4_LIBQTLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt4-libqtlua+=	qt4-libqtlua>=2.0
BUILDLINK_PKGSRCDIR.qt4-libqtlua?=	../../wip/qt4-libqtlua

.include "../../lang/lua51/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QT4_LIBQTLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt4-libqtlua
