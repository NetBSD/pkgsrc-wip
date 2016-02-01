# $NetBSD$

DISTNAME=	pynosh-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynosh/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/nschloe/pynosh/
COMMENT=	Nonlinear Schrodinger equations
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-krypy>=2.1.1:../../wip/py-krypy

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
