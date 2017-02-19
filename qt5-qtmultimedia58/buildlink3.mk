# $NetBSD: buildlink3.mk,v 1.19 2017/01/21 20:06:45 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtmultimedia

.if !defined(QT5_QTMULTIMEDIA_BUILDLINK3_MK)
QT5_QTMULTIMEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtmultimedia+=	qt5-qtmultimedia>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-qtmultimedia+=	qt5-qtmultimedia>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-qtmultimedia?=	../../wip/qt5-qtmultimedia58

BUILDLINK_INCDIRS.qt5-qtmultimedia+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtmultimedia+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtmultimedia+=	qt5/plugins

.if ${OPSYS} != "Darwin"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.endif	# QT5_QTMULTIMEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtmultimedia
