# $NetBSD: Makefile,v 1.1.1.1 2008/07/20 05:58:41 phonohawk Exp $
#

DISTNAME=	HsSVN-0.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=HsSVN/0.3.3/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cielonegro.org/HsSVN.html
COMMENT=	Subversion binding for Haskell

CONFIGURE_ENV+=	EXTRA_CPPFLAGS=-I${BUILDLINK_DIR}/include/subversion-1
CONFIGURE_ENV+=	EXTRA_LDFLAGS=-L${BUILDLINK_DIR}/lib

.include "../../wip/mk/haskell.mk" # This should be "../../mk/haskell.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
