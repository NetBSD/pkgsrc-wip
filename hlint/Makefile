# $NetBSD: Makefile,v 1.10 2013/05/12 23:58:21 szptvlfn Exp $
#

DISTNAME=	hlint-1.8.45
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell source code suggestions
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${PREFIX}/${PKGMANDIR}/man1
post-install:
	${INSTALL_MAN} ${WRKSRC}/data/hlint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-cpphs/buildlink3.mk"
.include "../../wip/hs-haskell-src-exts/buildlink3.mk"
.include "../../wip/hs-hscolour/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-uniplate/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
