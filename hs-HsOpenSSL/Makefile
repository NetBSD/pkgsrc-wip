# $NetBSD: Makefile,v 1.2 2009/07/26 23:12:54 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.6.4
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsOpenSSL.html
COMMENT=	OpenSSL binding for Haskell
LICENSE=	public-domain

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
