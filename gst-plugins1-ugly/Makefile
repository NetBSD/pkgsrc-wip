# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

DISTNAME=	gst-plugins-ugly-1.18.5
PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-plugins-ugly/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework - ugly plugins
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config xgettext

PYTHON_FOR_BUILD_ONLY=		tool

# generated with:
# find work/gst-*/ -name *.so | sed -e "s,/[^/]*$,:," -e 's,work/[^/]*/,${WRKSRC}/,' | tr -d \\n
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst/asfdemux:${WRKSRC}/output/gst/dvdlpcmdec:${WRKSRC}/output/gst/dvdsub:${WRKSRC}/output/gst/realmedia:${WRKSRC}/output/gst/xingmux:${WRKSRC}/output/ext/x264

# test status as of 1.18.5
#Ok:                 2
#Expected Fail:      0
#Fail:               1
#Unexpected Pass:    0
#Skipped:            0
#Timeout:            0

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libsidplay/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../wip/gst-plugins1-base/buildlink3.mk"
.include "../../wip/gstreamer1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
