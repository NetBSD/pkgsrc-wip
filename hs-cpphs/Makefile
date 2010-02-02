# $NetBSD: Makefile,v 1.3 2010/02/02 05:56:04 phonohawk Exp $
#

DISTNAME=		cpphs-1.10
CATEGORIES=		lang

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://haskell.org/cpphs/
COMMENT=		Re-implementation of cpp in Haskell
LICENSE=		gnu-lgpl-v2.1

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
