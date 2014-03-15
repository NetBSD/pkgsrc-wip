# $NetBSD: Makefile,v 1.1 2014/03/15 17:06:55 jihbed Exp $

DISTNAME=	emcee-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/e/emcee/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dan.iel.fm/emcee/current/
COMMENT=	The Python ensemble sampling toolkit for affine-invariant MCMC
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
