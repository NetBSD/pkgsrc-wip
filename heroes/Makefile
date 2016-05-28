# $NetBSD: Makefile,v 1.12 2012/09/29 17:05:55 asau Exp $
#

DISTNAME=		heroes-0.21
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heroes/}
DISTFILES=		${HEROES_DIRS:=.tar.bz2}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://heroes.sourceforge.net/
COMMENT=		Feature-packed game, like Nibbles or Tron clone


BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.10.36

WRKSRC=			${WRKDIR}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-sdl-mixer --enable-sound

HEROES_DIRS=		heroes-0.21 heroes-data-1.5 \
			heroes-hq-sound-tracks-1.0 \
			heroes-sound-effects-1.0 \
			heroes-sound-tracks-1.0
HEROES_WORKDIRS=	${HEROES_DIRS:C,^,${WRKSRC}/,}

CONFIGURE_DIRS=		${HEROES_WORKDIRS}
BUILD_DIRS=		${HEROES_WORKDIRS}

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
