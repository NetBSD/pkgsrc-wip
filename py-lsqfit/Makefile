# $NetBSD: Makefile,v 1.1 2013/08/31 20:23:39 jihbed Exp $

DISTNAME=	lsqfit-4.5.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/l/lsqfit/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/l/lsqfit/
COMMENT=	Utilities for nonlinear least-squares fits
LICENSE=	gnu-gpl-v3

FETCH_USING=    curl

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCLUDE_3X= yes
PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
