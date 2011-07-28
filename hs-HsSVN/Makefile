# $NetBSD: Makefile,v 1.5 2011/07/28 09:40:07 phonohawk Exp $
#

DISTNAME=	HsSVN-0.4.3.2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Subversion binding for Haskell
LICENSE=	public-domain

CONFIGURE_ENV+=	EXTRA_CPPFLAGS=-I${BUILDLINK_DIR}/include/subversion-1
CONFIGURE_ENV+=	EXTRA_LDFLAGS=-L${BUILDLINK_DIR}/lib

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-stm/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
