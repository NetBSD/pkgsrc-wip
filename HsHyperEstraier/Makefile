# $NetBSD: Makefile,v 1.2 2009/01/16 13:11:32 phonohawk Exp $
#

DISTNAME=	HsHyperEstraier-0.3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsHyperEstraier.html
COMMENT=	HyperEstraier binding for Haskell


.include "../../textproc/hyperestraier/buildlink3.mk"
CONFIGURE_ARGS=	# none

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
