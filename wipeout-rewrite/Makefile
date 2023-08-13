# $NetBSD$

DISTNAME=	wipeout-rewrite-20230811
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=phoboslab/}
GITHUB_TAG=	f0fdfa2aabe07cd0e760c8aa1d9b1c5562b64670

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://phoboslab.org/wipegame/
COMMENT=	Reimplementation of the 1995 PSX game

# XXX From the README re: the license: "There is none" (uh-huh, okay) BUT
# ALSO "you may NOT use this source code in a commercial release." And it's
# all despite the fact this is mostly original code... the upstream author
# is most likely confused about how copyright works.
LICENSE=	XXX

NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	C_FLAGS="${CFLAGS} -DRENDERER_GL"
MAKE_FLAGS+=	L_FLAGS="${LDFLAGS} -lGLEW -lGL -lSDL2"
MAKE_FLAGS+=	UNAME_S=Linux
BUILD_TARGET=	sdl

INSTALLATION_DIRS+=	bin libexec

pre-build:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/wipegame.template > ${WRKDIR}/wipegame

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/wipegame ${DESTDIR}${PREFIX}/bin/wipegame
	${INSTALL_PROGRAM} ${WRKSRC}/wipegame ${DESTDIR}${PREFIX}/libexec/wipegame

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
