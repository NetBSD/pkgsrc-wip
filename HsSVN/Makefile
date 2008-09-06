# $NetBSD: Makefile,v 1.2 2008/09/06 20:54:43 thomasklausner Exp $
#

DISTNAME=	HsSVN-0.3.3
PKGREVISION=	1
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
