# $NetBSD: Makefile,v 1.6 2010/02/17 14:55:48 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.8
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
.include "../../mk/bsd.pkg.mk"
