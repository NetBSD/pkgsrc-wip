# $NetBSD: Makefile,v 1.4 2010/05/10 02:13:00 phonohawk Exp $
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
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
