# $NetBSD: Makefile,v 1.1.1.1 2009/07/27 03:57:38 phonohawk Exp $
#

DISTNAME=	HsHyperEstraier-0.3.1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsHyperEstraier.html
COMMENT=	HyperEstraier binding for Haskell
LICENSE=	public-domain

.include "../../textproc/hyperestraier/buildlink3.mk"
CONFIGURE_ARGS=	# none

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
