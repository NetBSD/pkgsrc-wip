# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	nipy-0.3.0
CATEGORIES=	biology
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nipy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/n/nipy/
COMMENT=	Python package for analysis of neuroimaging data
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/nipy-0.3.0

USE_LANGUAGES=	c fortran
PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.6:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-nibabel>=1.3.0:../../wip/py-nibabel
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
