# $NetBSD: Makefile,v 1.7 2011/07/25 16:31:36 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.10
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	OpenSSL binding for Haskell
LICENSE=	public-domain

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../wip/mk/haskell.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
