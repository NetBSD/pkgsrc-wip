# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:26 thomasklausner Exp $
#

DISTNAME=	HsSVN-0.4.1
PKGREVISION=	1
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
