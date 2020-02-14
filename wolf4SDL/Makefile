# $NetBSD: Makefile,v 1.1 2015/08/17 20:10:44 yhardy Exp $
#

GITHUB_PROJECT=	wolf4sdl
GITHUB_TAG=	5387b99d32fc5bac39c87defcb0abbf1018d8083
DISTNAME=	${GITHUB_TAG}
PKGNAME=	Wolf4SDL-1.7
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozzwald/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozzwald/wolf4sdl
COMMENT=	Wolfenstein 3D ported to SDL
LICENSE=	xdoom-license AND mame-license

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

WOLF4SDLBIN+=	wolf4sdl-11
WOLF4SDLBIN+=	wolf4sdl-14
WOLF4SDLBIN+=	wolf4sdl-14gt
WOLF4SDLBIN+=	wolf4sdl-10sw
WOLF4SDLBIN+=	wolf4sdl-11sw
WOLF4SDLBIN+=	wolf4sdl-12sw
WOLF4SDLBIN+=	wolf4sdl-14sw
WOLF4SDLBIN+=	wolf4sdl-sod
WOLF4SDLBIN+=	wolf4sdl-soddemo
WOLF4SDLBIN+=	wolf4sdl

CFLAGS.wolf4sdl=		-DCARMACIZED
CFLAGS.wolf4sdl-11=		-DCARMACIZED -DAPOGEE_1_1
CFLAGS.wolf4sdl-14=		-DCARMACIZED
CFLAGS.wolf4sdl-14gt=		-DCARMACIZED -DGOODTIMES
CFLAGS.wolf4sdl-10sw=		-DUPLOAD -DAPOGEE_1_0
CFLAGS.wolf4sdl-11sw=		-DCARMACIZED -DUPLOAD -DAPOGEE_1_1
CFLAGS.wolf4sdl-12sw=		-DCARMACIZED -DUPLOAD -DAPOGEE_1_2
CFLAGS.wolf4sdl-14sw=		-DCARMACIZED -DUPLOAD
CFLAGS.wolf4sdl-sod=		-DCARMACIZED -DSPEAR
CFLAGS.wolf4sdl-soddemo=	-DCARMACIZED -DSPEAR -DSPEARDEMO

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	share/games/wolf3d

BUILD_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
BUILD_MAKE_FLAGS+=	MANPREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	BINARY=wolf4sdl
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANPREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing absolute paths.
SUBST_FILES.man=	man6/wolf4sdl.6
SUBST_SED.man=		-e 's,@PREFIX@,${PREFIX},g'

do-build:
.for bin in ${WOLF4SDLBIN}
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		BINARY=${bin} \
		CFLAGS='-DDATADIR=\"${PREFIX}/share/games/wolf3d/\" ${CFLAGS.${bin}}' \
		-f ${MAKE_FILE} clean ${BUILD_TARGET}
.endfor

post-install:
.for bin in ${WOLF4SDLBIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
