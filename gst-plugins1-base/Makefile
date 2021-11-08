# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

DISTNAME=	gst-plugins-base-1.18.5
PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-plugins-base/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework - base plugins
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=		pkg-config perl:run

PKGCONFIG_OVERRIDE=		output/pkgconfig/*.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

PYTHON_FOR_BUILD_ONLY=		tool

MESON_ARGS+=	-D gl_winsys=x11

.include "options.mk"

# for tests
# generate with:
# find work/gst-*/ -name *.so | sed -e "s,/[^/]*$,:," -e 's,work/[^/]*/,${WRKSRC}/,' | tr -d \\n
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst-libs/gst/tag:${WRKSRC}/output/gst-libs/gst/fft:${WRKSRC}/output/gst-libs/gst/video:${WRKSRC}/output/gst-libs/gst/audio:${WRKSRC}/output/gst-libs/gst/rtp:${WRKSRC}/output/gst-libs/gst/sdp:${WRKSRC}/output/gst-libs/gst/rtsp:${WRKSRC}/output/gst-libs/gst/pbutils:${WRKSRC}/output/gst-libs/gst/riff:${WRKSRC}/output/gst-libs/gst/app:${WRKSRC}/output/gst-libs/gst/allocators:${WRKSRC}/output/gst-libs/gst/gl:${WRKSRC}/output/gst/adder:${WRKSRC}/output/gst/app:${WRKSRC}/output/gst/audioconvert:${WRKSRC}/output/gst/audiomixer:${WRKSRC}/output/gst/audiorate:${WRKSRC}/output/gst/audioresample:${WRKSRC}/output/gst/audiotestsrc:${WRKSRC}/output/gst/compositor:${WRKSRC}/output/gst/encoding:${WRKSRC}/output/gst/gio:${WRKSRC}/output/gst/overlaycomposition:${WRKSRC}/output/gst/pbtypes:${WRKSRC}/output/gst/playback:${WRKSRC}/output/gst/rawparse:${WRKSRC}/output/gst/subparse:${WRKSRC}/output/gst/tcp:${WRKSRC}/output/gst/typefind:${WRKSRC}/output/gst/videoconvert:${WRKSRC}/output/gst/videorate:${WRKSRC}/output/gst/videoscale:${WRKSRC}/output/gst/videotestsrc:${WRKSRC}/output/gst/volume:${WRKSRC}/output/ext/cdparanoia:${WRKSRC}/output/ext/gl:${WRKSRC}/output/ext/libvisual:${WRKSRC}/output/ext/ogg:${WRKSRC}/output/ext/opus:${WRKSRC}/output/ext/pango:${WRKSRC}/output/ext/theora:${WRKSRC}/output/ext/vorbis:${WRKSRC}/output/sys/ximage:${WRKSRC}/output/sys/xvimage:${WRKSRC}/output/tests/examples/device-provider

# test status as of 1.18.5
#Ok:                 88
#Expected Fail:      0
#Fail:               14
#Unexpected Pass:    0
#Skipped:            14
#Timeout:            0

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../wip/gstreamer1/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
