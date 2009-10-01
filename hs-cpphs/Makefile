# $NetBSD: Makefile,v 1.2 2009/10/01 05:27:57 phonohawk Exp $
#

DISTNAME=		cpphs-1.9
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
