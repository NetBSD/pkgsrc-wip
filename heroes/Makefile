# $NetBSD: Makefile,v 1.6 2005/04/11 21:13:01 tvierling Exp $
#

DISTNAME=		heroes-0.21
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heroes/}
DISTFILES=		heroes-0.21.tar.bz2 heroes-data-1.5.tar.bz2 \
			heroes-sound-tracks-1.0.tar.bz2 \
			heroes-hq-sound-tracks-1.0.tar.bz2  \
			heroes-sound-effects-1.0.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://heroes.sourceforge.net/
COMMENT=		Feature-packed game, like Nibbles or Tron clone

BUILDLINK_DEPENDS.gettext+=	gettext-lib>=0.10.36

WRKSRC=			${WRKDIR}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

HEROES_DIRS=		heroes-0.21 heroes-data-1.5 \
			heroes-hq-sound-tracks-1.0 \
			heroes-sound-effects-1.0 \
			heroes-sound-tracks-1.0

CONFIGURE_ARGS+=	--with-sdl-mixer --enable-sound

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
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
