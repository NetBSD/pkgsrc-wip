# $NetBSD: Makefile,v 1.2 2014/12/31 13:58:23 thomasklausner Exp $

DISTNAME=	cerridwen-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cerridwen/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cerridwen.viridian-project.de/
COMMENT=	Accurate solar system data for everyone
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-astropy>=0.3.1:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-pyswisseph-[0-9]*:../../wip/py-pyswisseph

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-astropy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
