# $NetBSD$

DISTNAME=	cgen-2020.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cgen/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/inducer/cgen
COMMENT=	C and Cxx source generation from an AST
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pytools-[0-9]*:../../wip/py-pytools

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
