# $NetBSD$

DISTNAME=	Pint-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pint/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/hgrecco/pint
COMMENT=	Physical quantities module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-uncertainties>=3.1.5:../../math/py-uncertainties

REPLACE_PYTHON+=	pint/pint-convert


BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.1
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
