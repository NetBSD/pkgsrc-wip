# $NetBSD$

DISTNAME=	thermo-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/thermo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CalebBell/thermo
COMMENT=	Chemical properties component of ChEDL
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas>=0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-fluids>=1.0.26:../../wip/py-fluids
DEPENDS+=	${PYPKGPREFIX}-chemicals>=1.2.0:../../wip/py-chemicals

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Note: wheel did not work with this package as of 0.3.0
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
