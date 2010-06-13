# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:13 thomasklausner Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngnq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pngnq
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/pngnq
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pngnq

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
