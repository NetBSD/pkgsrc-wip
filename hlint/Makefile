# $NetBSD: Makefile,v 1.20 2014/06/27 21:28:54 szptvlfn Exp $

DISTNAME=	hlint-1.8.61
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell source code suggestions
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	${PREFIX}/${PKGMANDIR}/man1
post-install:
	${INSTALL_MAN} ${WRKSRC}/data/hlint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/haskell.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../wip/hs-cpphs/buildlink3.mk"
.include "../../wip/hs-haskell-src-exts/buildlink3.mk"
.include "../../wip/hs-hscolour/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../wip/hs-uniplate/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
