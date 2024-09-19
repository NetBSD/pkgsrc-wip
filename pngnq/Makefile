# $NetBSD: Makefile,v 1.6 2012/10/05 11:31:08 asau Exp $
#

DISTNAME=		pngnq-0.3-src
PKGNAME=		pngnq-0.3
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.cybertherial.com/pngnq/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cybertherial.com/pngnq/pngnq.html
COMMENT=		Tool for quantizing PNG images in RGBA format

WRKSRC=		${WRKDIR}/pngnq

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngnq ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pngnq
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/pngnq
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pngnq

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
