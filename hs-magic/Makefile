# $NetBSD: Makefile,v 1.1.1.1 2008/07/20 08:08:08 phonohawk Exp $
#

DISTNAME=	magic-1.0.7
PKGNAME=	hs-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=magic/1.0.7/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/magic
COMMENT=	Haskell interface to the C libmagic library

USE_LANGUAGES=	# none

.include "../../sysutils/file/buildlink3.mk"
.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
