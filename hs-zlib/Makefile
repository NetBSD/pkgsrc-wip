# $NetBSD: Makefile,v 1.1.1.1 2008/07/20 07:11:57 phonohawk Exp $
#

DISTNAME=	zlib-0.4.0.4
PKGNAME=	hs-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=zlib/0.4.0.4/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/zlib
COMMENT=	Zlib binding for Haskell

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
