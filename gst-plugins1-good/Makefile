# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

DISTNAME=	gst-plugins-good-1.18.4
PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-plugins-good/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework - good plugins
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=		pkg-config perl:run

PKGCONFIG_OVERRIDE=		output/pkgconfig/*.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

PYTHON_FOR_BUILD_ONLY=		tool

# for tests
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst-libs/gst/audio:${WRKSRC}/output/gst-libs/gst/video:${WRKSRC}/output/gst-libs/gst/tag:${WRKSRC}/output/gst-libs/gst/rtp:${WRKSRC}/output/gst-libs/gst/allocators:${WRKSRC}/output/gst-libs/gst/app:${WRKSRC}/output/gst-libs/gst/pbutils:${WRKSRC}/output/gst-libs/gst/gl:${WRKSRC}/output/gst-libs/ext/ogg:${WRKSRC}/output/gst-libs/ext/opus:${WRKSRC}/output/gst-libs/ext/theora:${WRKSRC}/output/gst-libs/ext/vorbis:${WRKSRC}/output/gst-libs/gst/riff:${WRKSRC}/output/gst-libs/gst/sdp:${WRKSRC}/output/gst-libs/gst/fft:${WRKSRC}/output/gst-libs/gst/rtsp

# test status as of 1.18.4
#Ok:                 68
#Expected Fail:      0
#Fail:               34
#Unexpected Pass:    0
#Skipped:            14
#Timeout:            0

#.include "../../audio/cdparanoia/buildlink3.mk"
#.include "../../audio/libopus/buildlink3.mk"
#.include "../../audio/libvisual/buildlink3.mk"
#.include "../../audio/libvorbis/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
#.include "../../devel/orc/buildlink3.mk"
#.include "../../devel/pango/buildlink3.mk"
#.include "../../lang/python/tool.mk"
#.include "../../mk/jpeg.buildlink3.mk"
#.include "../../multimedia/libogg/buildlink3.mk"
#.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../wip/gstreamer1/buildlink3.mk"
.include "../../wip/gst-plugins1-base/buildlink3.mk"
#.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
