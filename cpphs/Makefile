# $NetBSD: Makefile,v 1.4 2006/08/28 10:00:33 emil_s Exp $
#

DISTNAME=		cpphs-1.2
CATEGORIES=		devel
MASTER_SITES=		http://www.cs.york.ac.uk/fp/cpphs/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.cs.york.ac.uk/fp/cpphs/
COMMENT=		Re-implementation of cpp in Haskell


do-build:
	cd ${WRKSRC} && ghc -o cpphs --make cpphs

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cpphs ${PREFIX}/bin/cpphs
	@${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${PREFIX}/${PKGMANDIR}/man1


.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
