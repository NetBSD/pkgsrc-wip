# $NetBSD: Makefile,v 1.4 2009/02/02 13:19:32 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.5.1
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsOpenSSL.html
COMMENT=	OpenSSL binding for Haskell
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
