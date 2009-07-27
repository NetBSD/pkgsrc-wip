# $NetBSD: Makefile,v 1.1.1.1 2009/07/27 04:08:29 phonohawk Exp $
#

DISTNAME=	HsSVN-0.4.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsSVN.html
COMMENT=	Subversion binding for Haskell
LICENSE=	public-domain

CONFIGURE_ENV+=	EXTRA_CPPFLAGS=-I${BUILDLINK_DIR}/include/subversion-1
CONFIGURE_ENV+=	EXTRA_LDFLAGS=-L${BUILDLINK_DIR}/lib

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-stm/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
