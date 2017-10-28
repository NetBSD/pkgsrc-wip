# $NetBSD: buildlink3.mk,v 1.25 2017/04/22 21:03:22 adam Exp $

BUILDLINK_TREE+=	qt5-qttools

.if !defined(QT5_QTTOOLS_BUILDLINK3_MK)
QT5_QTTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qttools+=	qt5-qttools>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qttools+=	qt5-qttools>=5.9.1
BUILDLINK_PKGSRCDIR.qt5-qttools?=	../../wip/qt5-qttools

BUILDLINK_INCDIRS.qt5-qttools+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/plugins

.include "../../wip/qt5-qtxmlpatterns/buildlink3.mk"
#.include "../../wip/qt5-qtwebkit/buildlink3.mk"
#instead:
.include "../../wip/qt5-qtdeclarative/buildlink3.mk"
.include "../../wip/qt5-qtlocation/buildlink3.mk"
.include "../../wip/qt5-qtmultimedia/buildlink3.mk"
.include "../../wip/qt5-qtsensors/buildlink3.mk"
.include "../../wip/qt5-qtwebchannel/buildlink3.mk"
.endif	# QT5_QTTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qttools
