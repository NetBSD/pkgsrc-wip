# $NetBSD: Makefile,v 1.2 2014/08/22 21:12:24 jihbed Exp $

DISTNAME=	cma-1.1.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S/1.1.01/1.1.1/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cma/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.lri.fr/~hansen/cmaes_inmatlab.html#python
COMMENT=	Covariance Matrix Adaptation Evolution Strategy for non-linear
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
