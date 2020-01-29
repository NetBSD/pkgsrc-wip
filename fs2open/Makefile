# $NetBSD: Makefile,v 1.9 2015/08/18 20:48:41 yhardy Exp $
#

DISTNAME=	fs2_open_19_0_0-source-Unix
PKGNAME=	fs2_open-19.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=scp-fs2open/fs2open.github.com/releases/download/release_19_0_0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scp.indiegames.us/
COMMENT=	Freespace 2 source code project

WRKSRC=		${WRKDIR}/fs2open.github.com

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBINARY_DESTINATION=bin

LUA_VERSIONS_ACCEPTED=	51

pre-configure:
	${MKDIR} ${WRKSRC}/build

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
