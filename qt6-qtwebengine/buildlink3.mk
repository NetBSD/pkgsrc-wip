# $NetBSD$

BUILDLINK_TREE+=	qt6-qtwebengine

.if !defined(QT6_QTWEBENGINE_BUILDLINK3_MK)
QT6_QTWEBENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwebengine+=	qt6-qtwebengine>=6.8.2
BUILDLINK_PKGSRCDIR.qt6-qtwebengine?=	../../wip/qt6-qtwebengine

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../archivers/minizip/buildlink3.mk"
#.include "../../audio/alsa-lib/buildlink3.mk"
#.include "../../audio/libopus/buildlink3.mk"
#.include "../../devel/libexecinfo/buildlink3.mk"
#.include "../../devel/libepoll-shim/buildlink3.mk"
#.include "../../devel/libevent/buildlink3.mk"
#.include "../../devel/nss/buildlink3.mk"
#.include "../../devel/re2/buildlink3.mk"
#.include "../../devel/snappy/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/lcms2/buildlink3.mk"
#.include "../../graphics/libwebp/buildlink3.mk"
#.include "../../multimedia/ffmpeg7/buildlink3.mk"
#.include "../../multimedia/libvpx/buildlink3.mk"
#.include "../../print/libcups/buildlink3.mk"
#.include "../../sysutils/pciutils/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
#.include "../../textproc/jsoncpp/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
#.include "../../x11/libXcomposite/buildlink3.mk"
#.include "../../x11/libXtst/buildlink3.mk"
#.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
#.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../www/qt6-qtwebchannel/buildlink3.mk"
#.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTWEBENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwebengine
