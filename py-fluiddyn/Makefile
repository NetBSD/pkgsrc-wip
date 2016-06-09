# $NetBSD: Makefile,v 1.1 2015/08/05 20:29:09 jihbed Exp $

DISTNAME=	fluiddyn-0.0.10a7
 PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fluiddyn/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/f/fluiddyn/
COMMENT=	Framework for studying fluid dynamics.
LICENSE=	modified-bsd

DEPENDS+=       ${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=       ${PYPKGPREFIX}-psutil>=2.1.3:../../sysutils/py-psutil

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
