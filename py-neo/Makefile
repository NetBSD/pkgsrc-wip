# $NetBSD: Makefile,v 1.1 2014/05/12 21:40:55 jihbed Exp $

DISTNAME=	neo-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/neo/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pythonhosted.org/neo/
COMMENT=	Python package for representing electrophysiology data
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-quantities>=0.10.0:../../wip/py-quantities
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
