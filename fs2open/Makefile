# $NetBSD: Makefile,v 1.9 2015/08/18 20:48:41 yhardy Exp $
#

DISTNAME=	release_26_2_0
PKGNAME=	fs2_open-26.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=scp-fs2open/fs2open.github.com/archive/}
DIST_SUBDIR=	fs2_open
DISTFILES+=	${DEFAULT_DISTFILES}
DISTFILES+=	${GIT_LIBROCKET}.tar.gz

GIT_LIBROCKET=	b0c18e17d257a46db8395485895185915f483ede

SITES.${GIT_LIBROCKET}.tar.gz= \
		${MASTER_SITE_GITHUB:=scp-fs2open/}libRocket/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scp.indiegames.us/
COMMENT=	Freespace 2 source code project

WRKSRC=		${WRKDIR}/fs2open.github.com-${DISTNAME}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_CONFIGURE_ARGS+=	-DBINARY_DESTINATION=bin
CMAKE_CONFIGURE_ARGS+=	-DENABLE_COTIRE=OFF
CMAKE_CONFIGURE_ARGS+=	-DFSO_BUILD_INCLUDED_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=	-DFSO_BUILD_QTFRED=OFF
CMAKE_CONFIGURE_ARGS+=	-DFSO_BUILD_WITH_OPENXR=OFF
CMAKE_CONFIGURE_ARGS+=	-DFSO_BUILD_WITH_VULKAN=OFF

LUA_VERSIONS_ACCEPTED=	51

pre-configure:
	${MKDIR} ${WRKSRC}/build
	${CP} -R ${WRKDIR}/libRocket-${GIT_LIBROCKET}/* ${WRKSRC}/lib/libRocket/

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL3/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/ffmpeg9/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
