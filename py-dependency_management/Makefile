# $NetBSD$

DISTNAME=	dependency_management-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dependency_management/}

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/dependency_management
COMMENT=	coala Dependency Management
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=       ${PYPKGPREFIX}-coala_utils-[0-9]*:../../wip/py-coala_utils
DEPENDS+=       ${PYPKGPREFIX}-sarge-[0-9]*:../../wip/py-sarge

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
