# $NetBSD: Makefile,v 1.1.1.1 2008/07/20 07:49:50 phonohawk Exp $
#

DISTNAME=	Lucu-0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=Lucu/0.1/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/Lucu.html
COMMENT=	HTTP daemonic library for Haskell

USE_LANGUAGES=	# none

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../wip/HsOpenSSL/buildlink3.mk"
.include "../../wip/hs-dataenc/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../wip/hxt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
