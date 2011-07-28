# $NetBSD: Makefile,v 1.5 2011/07/28 10:20:19 phonohawk Exp $
#

DISTNAME=	HsHyperEstraier-0.4
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	HyperEstraier binding for Haskell
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../textproc/hyperestraier/buildlink3.mk"
CONFIGURE_ARGS=

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
