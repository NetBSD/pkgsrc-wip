# $NetBSD: Makefile,v 1.3 2010/02/04 06:58:22 phonohawk Exp $
#

DISTNAME=	HsHyperEstraier-0.3.2
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsHyperEstraier.html
COMMENT=	HyperEstraier binding for Haskell
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=   user-destdir

.include "../../textproc/hyperestraier/buildlink3.mk"
CONFIGURE_ARGS=	# none

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
