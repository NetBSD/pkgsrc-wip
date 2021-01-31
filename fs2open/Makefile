# $NetBSD: Makefile,v 1.9 2015/08/18 20:48:41 yhardy Exp $
#

DISTNAME=	release_21_0_0
PKGNAME=	fs2_open-21.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=scp-fs2open/fs2open.github.com/archive/}
DIST_SUBDIR=	fs2_open
DISTFILES+=	${DEFAULT_DISTFILES}
DISTFILES+=	${GIT_CMAKE_MOD}.tar.gz
DISTFILES+=	${GIT_LIBROCKET}.tar.gz

GIT_CMAKE_MOD=	0875d124fd6f0a7b775227e1790f17dcf45a7ec6 #asarium
GIT_CMAKE_MOD=	6a748896188fdf3f885820ccd686393ea5215dbf #rpavlik
GIT_LIBROCKET=	ecd648a43aff8a9f3daf064d75ca5725237d5b38

SITES.${GIT_CMAKE_MOD}.tar.gz= \
		${MASTER_SITE_GITHUB:=rpavlik/}cmake-modules/archive/
SITES.${GIT_LIBROCKET}.tar.gz= \
		${MASTER_SITE_GITHUB:=asarium/}libRocket/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scp.indiegames.us/
COMMENT=	Freespace 2 source code project

WRKSRC=		${WRKDIR}/fs2open.github.com-release_21_0_0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBINARY_DESTINATION=bin
CMAKE_ARGS+=	-DENABLE_COTIRE=OFF
CMAKE_ARGS+=	-DFSO_BUILD_INCLUDED_LIBS=OFF
CMAKE_ARGS+=	-DFSO_BUILD_WITH_VULKAN=OFF

LUA_VERSIONS_ACCEPTED=	51

pre-configure:
	${MKDIR} ${WRKSRC}/build
	${CP} -R ${WRKDIR}/cmake-modules-${GIT_CMAKE_MOD}/* ${WRKSRC}/cmake/external/rpavlik-cmake-modules/
	${CP} -R ${WRKDIR}/libRocket-${GIT_LIBROCKET}/* ${WRKSRC}/lib/libRocket/

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
