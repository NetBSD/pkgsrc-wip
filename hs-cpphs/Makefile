# $NetBSD: Makefile,v 1.1.1.1 2009/06/03 07:23:50 phonohawk Exp $
#

DISTNAME=		cpphs-1.6
CATEGORIES=		lang

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://haskell.org/cpphs/
COMMENT=		Re-implementation of cpp in Haskell

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
