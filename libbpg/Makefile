# $NetBSD: Makefile,v 1.2 2015/02/02 13:13:26 thomasklausner Exp $

DISTNAME=	libbpg-0.9.5
CATEGORIES=	graphics
MASTER_SITES=	https://bellard.org/bpg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bellard.org/bpg/
COMMENT=	Library for BGP (Better Portable Graphics)
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FLAGS+=		prefix=${PREFIX}
MAKE_FLAGS+=		DESTDIR=${DESTDIR}
INSTALLATION_DIRS=	bin

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpgview ${DESTDIR}${PREFIX}/bin/

.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
