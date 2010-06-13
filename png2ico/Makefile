# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:13 thomasklausner Exp $
#

DISTNAME=		png2ico-src-2002-12-08
PKGNAME=		png2ico-20021208
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.winterdrache.de/freeware/png2ico/data/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.winterdrache.de/freeware/png2ico/
COMMENT=		PNG to icon converter

USE_LANGUAGES=		c++

WRKSRC=			${WRKDIR}/png2ico

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/png2ico ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/png2ico.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
