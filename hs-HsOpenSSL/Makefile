# $NetBSD: Makefile,v 1.11 2014/05/21 21:04:43 szptvlfn Exp $
#

DISTNAME=	HsOpenSSL-0.10.1.3
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	OpenSSL binding for Haskell
LICENSE=	public-domain

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../wip/mk/haskell.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
