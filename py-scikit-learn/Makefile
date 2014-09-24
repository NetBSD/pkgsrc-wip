# $NetBSD: Makefile,v 1.1 2014/09/24 15:01:41 fhajny Exp $

DISTNAME=	scikit-learn-0.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S/-/_/}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/scikit-learn/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.9:../../math/py-scipy

USE_LANGUAGES=	c c++ fortran

.include "../../lang/python/egg.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
