# $NetBSD$

PKGNAME=	speed-dreams-2.2.3
DISTNAME=	speed-dreams-src-base-${PKGVERSION_NOREV}-r7616
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=speed-dreams/}
EXTRACT_SUFX=	.tar.xz

EXTRACT_DIR=	${WRKDIR}/${DISTNAME}

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++

CMAKE_CONFIGURE_ARGS+=	-DOPTION_3RDPARTY_EXPAT:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DOPTION_3RDPARTY_SQLITE3:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DOPTION_SDL2:BOOL=ON

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
