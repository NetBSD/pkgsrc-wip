# $NetBSD: Makefile,v 1.4 2006/05/19 16:51:29 ykomatsu Exp $
#

DISTNAME=		pngnq-0.3-src
PKGNAME=		pngnq-0.3
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
