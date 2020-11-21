# $NetBSD$

DISTNAME=	lazr.restfulclient-0.14.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazr.restfulclient/}

MAINTAINER=     rhialto@NetBSD.org
HOMEPAGE=       https://launchpad.net/lazr.restfulclient
COMMENT=        Provide added functionality on top of wadllib
LICENSE=        gnu-lgpl-v3

DEPENDS+=       ${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=       ${PYPKGPREFIX}-wadllib-[0-9]*:../../wip/py-wadllib
DEPENDS+=       ${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=       ${PYPKGPREFIX}-oauthlib-[0-9]*:../../security/py-oauthlib

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+= setuptools

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
