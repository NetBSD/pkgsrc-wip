# $NetBSD: Makefile,v 1.2 2015/08/05 21:50:06 jihbed Exp $

DISTNAME=	emcee-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=e/emcee/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dan.iel.fm/emcee/current/
COMMENT=	The Python ensemble sampling toolkit for affine-invariant MCMC
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
