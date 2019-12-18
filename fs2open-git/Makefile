# $NetBSD$
#

DISTNAME=	fs2_open-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=scp-fs2open/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scp.indiegames.us/
COMMENT=	Freespace 2 source code project

GIT_REPOSITORIES=	fs2open
GIT_REPO.fs2open=	git://github.com/scp-fs2open/fs2open.github.com.git
WRKSRC=			${WRKDIR}/fs2open

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

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
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
