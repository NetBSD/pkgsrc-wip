# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	pysb-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysb/}

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
