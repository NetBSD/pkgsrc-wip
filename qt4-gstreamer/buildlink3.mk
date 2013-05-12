# $NetBSD: buildlink3.mk,v 1.1 2013/05/12 01:12:32 othyro Exp $

BUILDLINK_TREE+=	qt4-gstreamer

.if !defined(QT4_GSTREAMER_BUILDLINK3_MK)
QT4_GSTREAMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt4-gstreamer+=	qt4-gstreamer>=0.10.2
BUILDLINK_PKGSRCDIR.qt4-gstreamer?=	../../wip/qt4-gstreamer

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# QT4_GSTREAMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt4-gstreamer
