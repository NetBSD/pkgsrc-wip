# $NetBSD: Makefile,v 1.1.1.1 2005/04/02 19:40:34 poppnk Exp $
#

DISTNAME=		briquolo-0.5.2
CATEGORIES=		wip games
MASTER_SITES=		http://briquolo.free.fr/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://briquolo.free.fr/
COMMENT=		3D breakout based on OpenGL

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

post-install:
	${CP} -rf ${WRKSRC}/data/data ${PREFIX}/share/briquolo/

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
