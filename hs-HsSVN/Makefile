# $NetBSD: Makefile,v 1.8 2014/05/25 21:59:28 szptvlfn Exp $
#

DISTNAME=	HsSVN-0.4.3.3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Subversion binding for Haskell
LICENSE=	public-domain

CONFIGURE_ARGS+= \
	--configure-option=--with-subversion-prefix=${PREFIX}

.include "../../wip/mk/haskell.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-stm/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
