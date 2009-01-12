# $NetBSD: Makefile,v 1.9 2009/01/12 02:20:36 phonohawk Exp $
#

DISTNAME=		cpphs-1.6
CATEGORIES=		devel

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://haskell.org/cpphs/
COMMENT=		Re-implementation of cpp in Haskell


post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${PREFIX}/${PKGMANDIR}/man1


.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
