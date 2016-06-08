# $NetBSD: Makefile,v 1.1 2015/08/05 21:15:53 jihbed Exp $

DISTNAME=	deltasigma-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deltasigma/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/ggventurini/python-deltasigma
COMMENT=	Scale and map to implementable topologies delta sigma modulators
LICENSE=	modified-bsd

DEPENDS+=       ${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
