# $NetBSD: Makefile,v 1.10 2012/03/04 09:47:49 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.10.1.3
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	OpenSSL binding for Haskell
LICENSE=	public-domain

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../wip/mk/haskell.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
