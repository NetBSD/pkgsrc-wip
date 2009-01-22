# $NetBSD: Makefile,v 1.3 2009/01/22 06:33:43 phonohawk Exp $
#

DISTNAME=	pcre-light-0.3.1
PKGREVISION=	1
PKGNAME=	hs-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://code.haskell.org/~dons/code/pcre-light
COMMENT=	Haskell binding to the PCRE regex library

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix+=	pcre-light.cabal
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

.include "../../wip/mk/haskell.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
