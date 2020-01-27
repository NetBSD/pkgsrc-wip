# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:29 othyro Exp $
#

DISTNAME=		png2ico-src-2002-12-08
PKGNAME=		png2ico-20021208
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.winterdrache.de/freeware/png2ico/data/
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.winterdrache.de/freeware/png2ico/
COMMENT=		PNG to icon converter

USE_LANGUAGES=		c++

WRKSRC=			${WRKDIR}/png2ico

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/png2ico ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/png2ico.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
