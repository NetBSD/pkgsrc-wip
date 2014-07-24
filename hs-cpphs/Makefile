# $NetBSD: Makefile,v 1.17 2014/07/24 21:55:23 szptvlfn Exp $

DISTNAME=		cpphs-1.18.5
CATEGORIES=		devel

MAINTAINER=		esg@sdf.lonestar.org
COMMENT=		Re-implementation of cpp in Haskell
LICENSE=		gnu-lgpl-v2.1

INSTALLATION_DIRS+= ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/haskell.mk"
.include "../../textproc/hs-polyparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
