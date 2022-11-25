# $NetBSD$

DISTNAME=	cgen-2020.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cgen/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://documen.tician.de/cgen/
COMMENT=	C/C++ source generation from an AST
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pytools>=2015.1.2:../../wip/py-pytools

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.6
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
