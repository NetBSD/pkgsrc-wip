# $NetBSD: buildlink3.mk,v 1.13 2016/12/04 05:17:15 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtdeclarative

.if !defined(QT5_QTDECLARATIVE_BUILDLINK3_MK)
QT5_QTDECLARATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtdeclarative+=	qt5-qtdeclarative>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-qtdeclarative+=	qt5-qtdeclarative>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-qtdeclarative?=	../../wip/qt5-qtdeclarative58

BUILDLINK_INCDIRS.qt5-qtdeclarative+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtdeclarative+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtdeclarative+=	qt5/plugins

.include "../../wip/qt5-qtxmlpatterns58/buildlink3.mk"
.endif	# QT5_QTDECLARATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtdeclarative
