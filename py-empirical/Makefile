# $NetBSD: Makefile,v 1.1 2014/01/14 23:55:55 jihbed Exp $

DISTNAME=	empirical-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/e/empirical/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/e/empirical/
COMMENT=	Emperical Method of Fundamental Solutions solver for Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
