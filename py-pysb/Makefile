# $NetBSD: Makefile,v 1.3 2013/09/12 18:31:08 jihbed Exp $

DISTNAME=	pysb-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pysb/
FETCH_USING= curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pysb.org/
COMMENT=	Python Systems Biology modeling framework
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.2:../../math/py-sympy
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
