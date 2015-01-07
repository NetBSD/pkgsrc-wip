# $NetBSD: Makefile,v 1.17 2015/01/07 13:20:55 szptvlfn Exp $

DISTNAME=	happy-1.19.5
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	LALR(1) parser generator for the functional language Haskell
LICENSE=	modified-bsd

USE_TOOLS+=	autoconf

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC}/doc ; autoconf ; ./configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/happy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/haskell.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
