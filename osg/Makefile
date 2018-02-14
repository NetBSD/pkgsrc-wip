# $NetBSD: Makefile,v 1.55 2015/06/30 09:57:36 ryoon Exp $

DISTNAME=	osg-3.4.1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=openscenegraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openscenegraph.org/
COMMENT=	High performance 3D graphics toolkit
LICENSE=	gnu-lgpl-v2.1

GITHUB_PROJECT=		OpenSceneGraph
GITHUB_TAG=		OpenSceneGraph-${PKGVERSION_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	packaging/pkgconfig/openscenegraph.pc.in
PKGCONFIG_OVERRIDE+=	packaging/pkgconfig/openthreads.pc.in

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Xine=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_CURL=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_GDAL=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_RSVG=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Poppler-glib=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Jasper=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_OpenEXR=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibVNCServer=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_SDL=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_SDL2=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_GStreamer=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_GLIB=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibXml2=TRUE
CMAKE_ARGS+=	-DOSG_USE_QT:BOOL=OFF

CXXFLAGS+=	-D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS

PLIST_VARS+=	quartz x11

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.quartz=	yes
.else
PLIST.x11=	yes
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
