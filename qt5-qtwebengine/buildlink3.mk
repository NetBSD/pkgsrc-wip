# $NetBSD$

BUILDLINK_TREE+=	qt5-qtwebengine

.if !defined(QT5_QTWEBENGINE_BUILDLINK3_MK)
QT5_QTWEBENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebengine+=	qt5-qtwebengine>=5.15.2
BUILDLINK_PKGSRCDIR.qt5-qtwebengine?=	../../wip/qt5-qtwebengine

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../audio/alsa-lib/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libexecinfo/buildlink3.mk"
#.include "../../devel/libevent/buildlink3.mk"
#.include "../../devel/nss/buildlink3.mk"
#.include "../../devel/re2/buildlink3.mk"
#.include "../../devel/snappy/buildlink3.mk"
#.include "../../graphics/lcms2/buildlink3.mk"
#.include "../../graphics/libwebp/buildlink3.mk"
#.include "../../multimedia/ffmpeg4/buildlink3.mk"
#.include "../../multimedia/libvpx/buildlink3.mk"
#.include "../../print/libcups/buildlink3.mk"
#.include "../../print/poppler-cpp/buildlink3.mk"
#.include "../../sysutils/pciutils/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
#.include "../../textproc/jsoncpp/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
#.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
#.include "../../x11/libXcomposite/buildlink3.mk"
#.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
#.include "../../x11/qt5-qtlocation/buildlink3.mk"
#.include "../../x11/qt5-qttools/buildlink3.mk"
#.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.endif	# QT5_QTWEBENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebengine
