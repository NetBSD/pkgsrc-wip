# $NetBSD: Makefile,v 1.1.1.1 2008/07/20 07:01:06 phonohawk Exp $
#

DISTNAME=	hxt-8.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=hxt/8.1.0/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.fh-wedel.de/~si/HXmlToolbox/index.html
COMMENT=	Collection of tools for processing XML with Haskell

USE_LANGUAGES=	# none

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../wip/hs-curl/buildlink3.mk"
.include "../../wip/tagsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
