# $NetBSD: Makefile,v 1.8 2011/10/05 07:13:45 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.10.1.1
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	OpenSSL binding for Haskell
LICENSE=	public-domain

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../wip/mk/haskell.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
