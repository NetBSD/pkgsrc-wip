# $NetBSD$

DISTNAME=	ptyx-mcq-22.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/ptyx-mcq/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/wxgeo/ptyx
COMMENT=	Python precompiler for LaTeX
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-pdf2image>=1.16.0:../../wip/py-pdf2image
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.9:../../math/py-sympy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
