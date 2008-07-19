# $NetBSD: Makefile,v 1.1.1.1 2008/07/19 08:55:46 phonohawk Exp $
#

DISTNAME=	HsHyperEstraier-0.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=HsHyperEstraier/0.2.1/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsHyperEstraier.html
COMMENT=	HyperEstraier binding for Haskell

USE_LANGUAGES=	# none

.include "../../textproc/hyperestraier/buildlink3.mk"
CONFIGURE_ARGS=	# none

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
