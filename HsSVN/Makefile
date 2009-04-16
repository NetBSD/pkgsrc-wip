# $NetBSD: Makefile,v 1.4 2009/04/16 21:42:51 thomasklausner Exp $
#

DISTNAME=	HsSVN-0.4
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsSVN.html
COMMENT=	Subversion binding for Haskell

CONFIGURE_ENV+=	EXTRA_CPPFLAGS=-I${BUILDLINK_DIR}/include/subversion-1
CONFIGURE_ENV+=	EXTRA_LDFLAGS=-L${BUILDLINK_DIR}/lib

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/stm/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
