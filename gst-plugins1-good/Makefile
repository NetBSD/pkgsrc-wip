# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

DISTNAME=	gst-plugins-good-1.18.5
PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-plugins-good/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework - good plugins
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config perl:run xgettext

CONFLICTS+=	gst-plugins1-cairo-[0-9]*
SUPERSEDES+=	gst-plugins1-cairo-[0-9]*
CONFLICTS+=	gst-plugins1-flac-[0-9]*
SUPERSEDES+=	gst-plugins1-flac-[0-9]*
CONFLICTS+=	gst-plugins1-gdk_pixbuf-[0-9]*
SUPERSEDES+=	gst-plugins1-flac-[0-9]*
CONFLICTS+=	gst-plugins1-jpeg-[0-9]*
SUPERSEDES+=	gst-plugins1-jpeg-[0-9]*
CONFLICTS+=	gst-plugins1-lame-[0-9]*
SUPERSEDES+=	gst-plugins1-lame-[0-9]*
CONFLICTS+=	gst-plugins1-mpg123-[0-9]*
SUPERSEDES+=	gst-plugins1-mpg123-[0-9]*
CONFLICTS+=	gst-plugins1-png-[0-9]*
SUPERSEDES+=	gst-plugins1-png-[0-9]*
CONFLICTS+=	gst-plugins1-speex-[0-9]*
SUPERSEDES+=	gst-plugins1-speex-[0-9]*
CONFLICTS+=	gst-plugins1-twolame-[0-9]*
SUPERSEDES+=	gst-plugins1-twolame-[0-9]*
CONFLICTS+=	gst-plugins1-v4l2-[0-9]*
SUPERSEDES+=	gst-plugins1-v4l2-[0-9]*
CONFLICTS+=	gst-plugins1-vpx-[0-9]*
SUPERSEDES+=	gst-plugins1-vpx-[0-9]*
CONFLICTS+=	gst-plugins1-wavpack-[0-9]*
SUPERSEDES+=	gst-plugins1-wavpack-[0-9]*

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=	oss
.if ${OSS_TYPE} != "none"
CONFLICTS+=	gst-plugins1-oss-[0-9]*
SUPERSEDES+=	gst-plugins1-oss-[0-9]*
PLIST.oss=	yes
LDFLAGS+=	${LIBOSSAUDIO}
.endif

# prefer libcaca to aalib
MESON_ARGS+=	-D aalib=disabled
# requires nasm, but seems to not work on NetBSD/amd64
MESON_ARGS+=	-D asm=disabled
MESON_ARGS+=	-D examples=disabled
# problematic on NetBSD at least
MESON_ARGS+=	-D oss4=disabled
MESON_ARGS+=	-D qt5=disabled

TOOL_DEPENDS+=	orc-[0-9]*:../../devel/orc

PKGCONFIG_OVERRIDE=		output/pkgconfig/*.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

PYTHON_FOR_BUILD_ONLY=		tool

LDFLAGS+=	${LIBOSSAUDIO}

# test status as of 1.18.5
#Ok:                 104
#Expected Fail:      0
#Fail:               1
#Unexpected Pass:    0
#Skipped:            0
#Timeout:            0
#
#105/105 generic_states                         FAIL            40.92s   exit status 2

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/twolame/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/libcaca/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../wip/gst-plugins1-base/buildlink3.mk"
.include "../../wip/gstreamer1/buildlink3.mk"
# probably needs adjustments in PLIST
#.if ${OPSYS} == "Linux"
#.include "../../wip/libavc1394/buildlink3.mk"
#.include "../../wip/libraw1394/buildlink3.mk"
#.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
