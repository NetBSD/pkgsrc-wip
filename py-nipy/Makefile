# $NetBSD: Makefile,v 1.1 2013/09/13 18:52:53 jihbed Exp $

DISTNAME=	nipy-0.3.0
CATEGORIES=	biology
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	https://pypi.python.org/packages/source/n/nipy/
FETCH_USING= curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/n/nipy/
COMMENT=	Python package for analysis of neuroimaging data
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/nipy-0.3.0

USE_LANGUAGES=  c fortran
PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.6:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
