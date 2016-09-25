# $NetBSD: Makefile,v 1.11 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=	pinball-0.3.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://pinball.sourceforge.net/
COMMENT=	Pinball using the Allegro game library
LICENSE=	gnu-gpl-v1


USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake aclocal automake
GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/pinball-0.3.1

MAKE_JOBS_SAFE=                no

post-extract:
	cp ${FILESDIR}/config-rzr.h ${WRKSRC}/base/config-rzr.h

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
