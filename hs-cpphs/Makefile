# $NetBSD: Makefile,v 1.5 2011/01/17 10:48:03 emil_s Exp $
#

DISTNAME=		cpphs-1.11
CATEGORIES=		lang

MAINTAINER=		esg@sdf.lonestar.org
HOMEPAGE=		http://haskell.org/cpphs/
COMMENT=		Re-implementation of cpp in Haskell
LICENSE=		gnu-lgpl-v2.1

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
