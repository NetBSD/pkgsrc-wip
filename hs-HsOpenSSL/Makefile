# $NetBSD: Makefile,v 1.3 2009/10/02 07:40:28 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.6.5
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsOpenSSL.html
COMMENT=	OpenSSL binding for Haskell
LICENSE=	public-domain

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../wip/mk/haskell.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
