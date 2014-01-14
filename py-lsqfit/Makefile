# $NetBSD: Makefile,v 1.2 2014/01/14 15:02:49 jihbed Exp $

DISTNAME=	lsqfit-4.5.3
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/l/lsqfit/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/l/lsqfit/
COMMENT=	Utilities for nonlinear least-squares fits
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCLUDE_3X= yes
PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
