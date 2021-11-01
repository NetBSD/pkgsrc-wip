# $NetBSD: Makefile,v 1.3 2015/01/31 22:33:20 jihbed Exp $

DISTNAME=	symath-0.1.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/symath/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bniemczyk/symbolic
COMMENT=	symbolic mathematics for python
LICENSE=	2-clause-bsd

DPENDS+=        ${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

WRKSRC=		${WRKDIR}/symath-0.1.22

PYTHON_VERSIONED_DEPENDENCIES+=	pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
