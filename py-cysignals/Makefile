# $NetBSD$

DISTNAME=	cysignals-1.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cysignals/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sagemath/cysignals
COMMENT=	Interrupt and signal handling for Cython
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8.3:../../textproc/py-sphinx

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
