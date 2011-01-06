# $NetBSD: Makefile,v 1.4 2011/01/06 15:47:29 phonohawk Exp $
#

DISTNAME=	pcre-light-0.4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell bindings to the PCRE regex library
LICENSE=	modified-bsd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix+=	pcre-light.cabal
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

.include "../../wip/mk/haskell.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
