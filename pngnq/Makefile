# $NetBSD: Makefile,v 1.1.1.1 2004/09/15 08:20:33 thomasklausner Exp $
#

DISTNAME=		${PKGNAME}-src
PKGNAME=		pngnq-0.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.cybertherial.com/pngnq/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cybertherial.com/pngnq/pngnq.html
COMMENT=		Tool for quantizing PNG images in RGBA format

WRKSRC=		${WRKDIR}/pngnq
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngnq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pngnq
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/pngnq
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pngnq

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
