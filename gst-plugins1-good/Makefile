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

LDFLAGS+=	${LIBOSSAUDIO}

# not packaged
#Run-time dependency libiec61883 found: NO (tried pkgconfig and cmake)
# dependency too big
#Run-time dependency qt5 (modules: Core, Gui, Qml, Quick) found: NO (tried pkgconfig and config-tool)
# not packaged
#Run-time dependency gudev-1.0 found: NO (tried pkgconfig and cmake)

# test status as of 1.18.4
#Ok:                 104
#Fail:               1
#
#105/105 elements_videoflip            FAIL            20.26s   exit status 1

.include "../../devel/meson/build.mk"
.include "../../audio/flac/buildlink3.mk"
#Dependency jack found: NO found 0.125.0 but need: '>= 1.9.7'
#.include "../../audio/jack/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
# prefer mpg123 to mp3lame, twolame
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
# prefer libcaca to aalib
.include "../../graphics/libcaca/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
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
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
