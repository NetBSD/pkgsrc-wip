# $NetBSD: Makefile,v 1.5 2006/07/02 19:04:33 shattered Exp $
#

DISTNAME=		briquolo-0.5.2
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://briquolo.free.fr/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://briquolo.free.fr/en/
COMMENT=		3D breakout based on OpenGL

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

post-install:
	${CP} -rf ${WRKSRC}/data/data ${PREFIX}/share/briquolo/

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
