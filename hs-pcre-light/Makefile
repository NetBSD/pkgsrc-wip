# $NetBSD: Makefile,v 1.1.1.1 2008/08/26 05:40:20 phonohawk Exp $
#

DISTNAME=	pcre-light-0.3.1
PKGNAME=	hs-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=pcre-light/0.3.1/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/pcre-light
COMMENT=	Haskell binding to the PCRE regex library

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
