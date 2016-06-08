# $NetBSD: Makefile,v 1.1 2015/08/05 20:41:42 jihbed Exp $

DISTNAME=	gwpy-0.1b3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gwpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://gwpy.github.io/
COMMENT=	Package to enable gravitational-wave astrophysics in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=       ${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=       ${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-astropy>=0.4.6:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-gitdb>=-0.6.4:../../wip/py-gitdb


USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
