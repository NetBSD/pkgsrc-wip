# $NetBSD: Makefile,v 1.2 2004/03/08 05:31:20 mpasternak Exp $
#

DISTNAME=		heroes-0.21
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heroes/}
DISTFILES=		heroes-0.21.tar.bz2 heroes-data-1.5.tar.bz2 \
			heroes-sound-tracks-1.0.tar.bz2 \
			heroes-hq-sound-tracks-1.0.tar.bz2  \
			heroes-sound-effects-1.0.tar.bz2  

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://heroes.sourceforge.net/
COMMENT=		Feature-packed game, like Nibbles or Tron clone

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

HEROES_DIRS=		heroes-0.21 heroes-data-1.5 \
			heroes-hq-sound-tracks-1.0 \
       			heroes-sound-effects-1.0 \
			heroes-sound-tracks-1.0

CONFIGURE_ARGS+=	--with-sdl-mixer

do-configure:
	@for dir in ${HEROES_DIRS}; do \
		cd ${WRKSRC}/$$dir && ${SETENV} ${CONFIGURE_ENV} ./configure \
			${CONFIGURE_ARGS}; done

do-build:
	@for dir in ${HEROES_DIRS}; do \
		cd ${WRKSRC}/$$dir && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}; \
	done

do-install:
	@for dir in ${HEROES_DIRS}; do \
		cd ${WRKSRC}/$$dir && ${SETENV} ${MAKE_ENV} ${MAKE} \
			${MAKE_FLAGS} install; done

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
