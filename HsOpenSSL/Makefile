# $NetBSD: Makefile,v 1.2 2008/07/30 03:59:14 phonohawk Exp $
#

DISTNAME=	HsOpenSSL-0.4.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=HsOpenSSL/0.4.2/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsOpenSSL.html
COMMENT=	OpenSSL binding for Haskell
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7l
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
