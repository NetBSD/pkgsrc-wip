# $NetBSD: Makefile,v 1.1.1.1 2008/07/20 06:51:10 phonohawk Exp $
#

DISTNAME=	curl-1.3.2.1
PKGNAME=	hs-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=curl/1.3.2.1/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/curl
COMMENT=	Haskell binding to libcurl

USE_LANGUAGES=	# none

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
